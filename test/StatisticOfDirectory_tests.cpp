#include "../src/StatisticOfDirectory.h"

#include <gtest/gtest.h>

static void incrementAllField(StatisticOfDirectory *statistic) {
    statistic->numberFiles++;
    statistic->numberEmptyLines++;
    statistic->numberNonemptyLine++;
    statistic->numberLetters++;
    statistic->numberChars++;
    statistic->numberWords++;
}

TEST(StatisticOfDirectory, Join) {
    StatisticOfDirectory statistic1{};
    incrementAllField(&statistic1);
    incrementAllField(&statistic1);
    StatisticOfDirectory statistic2{};
    incrementAllField(&statistic2);
    statistic1.join(statistic2);
    EXPECT_EQ(statistic1.numberFiles, 3);
    EXPECT_EQ(statistic1.numberWords, 3);
    EXPECT_EQ(statistic1.numberChars, 3);
    EXPECT_EQ(statistic1.numberLetters, 3);
    EXPECT_EQ(statistic1.numberNonemptyLine, 3);
    EXPECT_EQ(statistic1.numberEmptyLines, 3);
}
