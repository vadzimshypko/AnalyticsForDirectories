#include "AnalyzerForDirectory.h"

std::mutex g_mutex;
std::vector<std::exception_ptr> g_exceptions;

void processException() {
    for (auto &e: g_exceptions) {
        try {
            if (e != nullptr)
                std::rethrow_exception(e);
        }
        catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    g_exceptions.clear();
}

AnalyzerForDirectory::AnalyzerForDirectory() : AnalyzerForDirectory(std::thread::hardware_concurrency()) {}

AnalyzerForDirectory::AnalyzerForDirectory(size_t numberThreads) : numberThreads(numberThreads) {
    if (numberThreads <= 0) {
        throw std::invalid_argument("Received negative number of threads");
    }
    pool.reserve(numberThreads);
}

StatisticOfDirectory AnalyzerForDirectory::process(const fs::path &pathForAnalyze) {
    StatisticOfDirectory statistic{};
    FileIterator iterator{pathForAnalyze};
    for (int i = 0; i < numberThreads; ++i) {
        pool.emplace_back(std::thread(processInThread, std::ref(iterator), std::ref(statistic)));
    }

    for (auto &i: pool) {
        i.join();
    }
    pool.clear();

    processException();
    return statistic;
}

void AnalyzerForDirectory::processInThread(FileIterator &iterator, StatisticOfDirectory &commonStatistic) {
    try {
        StatisticOfDirectory localStatistic{};
        while (!iterator.isAll()) {
            fs::path pathToFile = iterator.next();
            if (!pathToFile.empty()) {
                processFile(pathToFile, &localStatistic);
            }
        }
        commonStatistic.join(localStatistic);
    }
    catch (...) {
        std::lock_guard<std::mutex> lock(g_mutex);
        g_exceptions.push_back(std::current_exception());
    }
}

void AnalyzerForDirectory::processFile(const fs::path &path, StatisticOfDirectory *statistic) {
    ++statistic->numberFiles;
    std::ifstream ifstream{path};
    std::string line;
    while (std::getline(ifstream, line)) {
        // count emtpy/nonempty strings
        if (line.empty()) {
            ++statistic->numberEmptyLines;
        } else {
            ++statistic->numberNonemptyLine;
        }
        // count chars
        statistic->numberChars += line.size() + 1; // '\n' between lines and end-of-file character.
        // count words
        countWordsAndLetters(line, statistic);
    }
    ifstream.close();
}

void AnalyzerForDirectory::countWordsAndLetters(const std::string &text, StatisticOfDirectory *statistic) {
    bool lastSeparate = true;
    for (auto c: text) {
        if (isSeparateChar(c)) {
            lastSeparate = true;
        } else if (std::isalpha(c) && lastSeparate) {
            ++statistic->numberWords;
            lastSeparate = false;
        }
        // count letters
        if (std::isalpha(c)) {
            ++statistic->numberLetters;
        }
    }
}

bool AnalyzerForDirectory::isSeparateChar(char c) {
    return std::isspace(c) || std::iscntrl(c) || std::ispunct(c);
}

