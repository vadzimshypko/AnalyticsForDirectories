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

    virtual ~AnalyzerForDirectory() = default;

protected:

    static void processInThread(FileIterator &iterator, StatisticOfDirectory &commonStatistic);

    static void processFile(const fs::path &path, StatisticOfDirectory *statistic);

    static void countWordsAndLetters(const std::string &text, StatisticOfDirectory *statistic);

    static bool isSeparateChar(char c);

    size_t numberThreads;
    std::vector<std::thread> pool;
};
