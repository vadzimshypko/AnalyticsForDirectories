#include <iostream>
#include <filesystem>
#include <string>
#include "AnalyzerForDirectory.h"

namespace fs = std::filesystem;

// FOR TEST

void createFile(const fs::path &path, const std::string &fileName, const std::string &content) {
    std::ofstream file = std::ofstream(path / fileName);
    file << content;
    file.close();
}

void createExampleDirectory(const fs::path &path) {
    fs::create_directories(path / "/a/b");
    createFile(path / "/a/b", "ab.txt", "try read");
}

void printStatistics(const fs::path &pathForAnalyze, size_t numberThreads) {
    if (fs::exists(pathForAnalyze)) {
        AnalyzerForDirectory analyzer{numberThreads};
        StatisticOfDirectory statistic = analyzer.process(pathForAnalyze);
        std::cout << "Statistics for " << pathForAnalyze << std::endl << statistic;
    } else {
        std::cout << "Directory " << pathForAnalyze << " doesn't exist in " << fs::current_path() << std::endl;
    }
}

void printStatistics(const fs::path &pathForAnalyze) {
    printStatistics(pathForAnalyze, std::thread::hardware_concurrency());
}

double calculateTimeOnProcess(const std::function<void()> &f) {
    clock_t start = clock();
    f();
    clock_t end = clock();
    return (double) (end - start) / CLOCKS_PER_SEC;
}

void printPerformanceComparison(const fs::path &pathForAnalyze, size_t maxNumberThreads) {
    for (size_t i = 1; i < maxNumberThreads; ++i) {
        double time = calculateTimeOnProcess([&pathForAnalyze, i]() {
            if (fs::exists(pathForAnalyze)) {
                AnalyzerForDirectory analyzer{i};
                StatisticOfDirectory statistic = analyzer.process(pathForAnalyze);
            }
        });
        std::cout << "Number of threads = " << i << ", completed in " << time << " seconds." << std::endl;
    }
}

int main(int argc, char *argv[]) {
    fs::path pathForAnalyze;
    size_t numberThreads = 0;

    if (argc > 1) {
        pathForAnalyze = argv[1];
    }
    if (argc > 2) {
        numberThreads = static_cast<size_t>(std::stoi(argv[2]));
    }

    if (numberThreads > 0) {
        printStatistics(pathForAnalyze, numberThreads);
    } else {
        printStatistics(pathForAnalyze);
    }

    // printPerformanceComparison(pathForAnalyze, 16);

    return 0;
}

