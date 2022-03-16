#include <fstream>
#include <iostream>
#include <filesystem>
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

int main(int argc, char *argv[]) {
    fs::path pathForAnalyze;
    if (argc > 1) {
        pathForAnalyze = argv[1];
        std::cout << pathForAnalyze << std::endl;
    }
    if (fs::exists(pathForAnalyze)) {
        AnalyzerForDirectory analyzer;
        StatisticOfDirectory statistic = analyzer.process(pathForAnalyze);
        std::cout << statistic;
    } else {
        std::cout << "Directory " << pathForAnalyze << " doesn't exist in " << fs::current_path() << std::endl;
        return 1;
    }
    return 0;
}
