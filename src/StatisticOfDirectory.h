#pragma once

#include <string>

struct StatisticOfDirectory {
    std::string path;
    uint64_t numberFiles{};
    uint64_t numberEmptyLines{};
    uint64_t numberNonemptyLine{};
    uint64_t numberLetters{};
    uint64_t numberChars{};
    uint64_t numberWords{};

    friend std::ostream &operator<<(std::ostream &stream, const StatisticOfDirectory &statistic);
};

