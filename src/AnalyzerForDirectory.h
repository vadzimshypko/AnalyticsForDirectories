#pragma once

#include <fstream>
#include <iostream>
#include <filesystem>
#include <thread>
#include "StatisticOfDirectory.h"
#include "FileIterator.h"

namespace fs = std::filesystem;

class AnalyzerForDirectory {
public:
    AnalyzerForDirectory();

    explicit AnalyzerForDirectory(size_t numberThreads);

    StatisticOfDirectory process(const fs::path &pathForAnalyze);

private:
    static void processInThread(FileIterator& iterator, StatisticOfDirectory& commonStatistic);

    static void processFile(const fs::path &path, StatisticOfDirectory *statistic);

    static void countWords(const std::string &text, StatisticOfDirectory *statistic);

    static bool isSeparateChar(char c);

    size_t numberThreads;
    std::vector<std::thread> pool;
};
