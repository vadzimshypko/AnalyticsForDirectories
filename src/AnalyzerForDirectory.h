#pragma once

#include <fstream>
#include <iostream>
#include <filesystem>
#include "StatisticOfDirectory.h"

namespace fs = std::filesystem;

class AnalyzerForDirectory {
public:
    StatisticOfDirectory process(const fs::path &pathForAnalyze);

private:
    void processFile(const fs::directory_entry &entry, StatisticOfDirectory *statistic);

    void countWords(const std::string &text, StatisticOfDirectory *statistic);

    bool isSeparateChar(char c);
};
