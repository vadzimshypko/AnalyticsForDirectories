#include <gtest/gtest.h>
#include "../src/utils.h"
#include "../src/AnalyzerForDirectory.h"

using ::testing::TestWithParam;
using ::testing::internal::ParamGenerator;
using ::testing::Values;

class AnalyzerForDirectoryTest : public AnalyzerForDirectory {
    FRIEND_TEST(AnalyzerForDirectoryTest, isSeparateChar);

    FRIEND_TEST(AnalyzerForDirectoryTest, processFiles);
};

TEST(AnalyzerForDirectoryTest, processFiles) {
    fs::path testPath(".out/test/");
    fs::remove_all(testPath);
    createFileWithDirectory(testPath, "file.txt", "42\n42");

    StatisticOfDirectory statistic{};
    AnalyzerForDirectoryTest::processFile(testPath / "file.txt", &statistic);
    EXPECT_EQ(statistic.numberFiles, 1);
    EXPECT_EQ(statistic.numberNonemptyLine, 2);
    EXPECT_EQ(statistic.numberEmptyLines, 0);
    EXPECT_EQ(statistic.numberChars, 6);

    fs::remove_all(testPath);
    createFileWithDirectory(testPath, "file1.txt", "42\n\n4");

    AnalyzerForDirectoryTest::processFile(testPath / "file1.txt", &statistic);
    EXPECT_EQ(statistic.numberFiles, 2);
    EXPECT_EQ(statistic.numberNonemptyLine, 4);
    EXPECT_EQ(statistic.numberEmptyLines, 1);
    EXPECT_EQ(statistic.numberChars, 12);

    fs::remove_all(testPath);
}

TEST(AnalyzerForDirectoryTest, isSeparateChar) {
    EXPECT_TRUE(AnalyzerForDirectoryTest::isSeparateChar('.'));
    EXPECT_FALSE(AnalyzerForDirectoryTest::isSeparateChar('B'));
    EXPECT_FALSE(AnalyzerForDirectoryTest::isSeparateChar('a'));
    EXPECT_FALSE(AnalyzerForDirectoryTest::isSeparateChar('z'));
    EXPECT_TRUE(AnalyzerForDirectoryTest::isSeparateChar('|'));
    EXPECT_TRUE(AnalyzerForDirectoryTest::isSeparateChar(' '));
}


class AnalyzerForDirectoryParametersTests
        : public AnalyzerForDirectory, public TestWithParam<std::pair<std::string, int>> {
public:
    FRIEND_TEST(AnalyzerForDirectoryParametersTests, countWordsAndLetters);
};

TEST_P(AnalyzerForDirectoryParametersTests, countWordsAndLetters) {
    StatisticOfDirectory statistic{};
    AnalyzerForDirectoryTest::countWordsAndLetters(std::get<0>(GetParam()), &statistic);
    EXPECT_EQ(statistic.numberWords, std::get<1>(GetParam()));
}

INSTANTIATE_TEST_SUITE_P
(AnalyzerForDirectory_tests, AnalyzerForDirectoryParametersTests, Values(
        std::make_pair("aaa,aa", 2),
        std::make_pair("t ", 1),
        std::make_pair("a.a . t", 3),
        std::make_pair(" t", 1),
        std::make_pair("aaa....bbb|||ctd?a", 4),
        std::make_pair("aaa aaa", 2)));