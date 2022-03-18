#pragma once

#include <string>
#include <ostream>
#include <mutex>
#include <atomic>

struct StatisticOfDirectory {
    StatisticOfDirectory();

    StatisticOfDirectory(const StatisticOfDirectory &);

    StatisticOfDirectory &operator=(const StatisticOfDirectory &);

    friend std::ostream &operator<<(std::ostream &, const StatisticOfDirectory &);

    void join(const StatisticOfDirectory &);

    std::atomic_int64_t numberFiles{};
    std::atomic_int64_t numberEmptyLines{};
    std::atomic_int64_t numberNonemptyLine{};
    std::atomic_int64_t numberLetters{};
    std::atomic_int64_t numberChars{};
    std::atomic_int64_t numberWords{};
};

