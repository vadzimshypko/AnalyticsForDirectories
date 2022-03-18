#include "StatisticOfDirectory.h"

StatisticOfDirectory::StatisticOfDirectory() : numberFiles{0}, numberEmptyLines{0}, numberNonemptyLine{0},
                                               numberLetters{0}, numberChars{0}, numberWords{0} {}

StatisticOfDirectory &StatisticOfDirectory::operator=(const StatisticOfDirectory &other) {
    numberFiles = other.numberFiles.load();
    numberEmptyLines = other.numberEmptyLines.load();
    numberNonemptyLine = other.numberNonemptyLine.load();
    numberLetters = other.numberLetters.load();
    numberChars = other.numberChars.load();
    numberWords = other.numberWords.load();
    return *this;
}

StatisticOfDirectory::StatisticOfDirectory(const StatisticOfDirectory &other) {
    numberFiles = other.numberFiles.load();
    numberEmptyLines = other.numberEmptyLines.load();
    numberNonemptyLine = other.numberNonemptyLine.load();
    numberLetters = other.numberLetters.load();
    numberChars = other.numberChars.load();
    numberWords = other.numberWords.load();
}

std::ostream &operator<<(std::ostream &stream, const StatisticOfDirectory &statistic) {
    stream << "Number of files: " << statistic.numberFiles << std::endl <<
           "Number of empty lines: " << statistic.numberEmptyLines << std::endl <<
           "Number of nonempty lines: " << statistic.numberNonemptyLine << std::endl <<
           "Common number of lines: " << (statistic.numberEmptyLines + statistic.numberNonemptyLine) << std::endl <<
           "Number of letters: " << statistic.numberLetters << std::endl <<
           "Number of chars: " << statistic.numberChars << std::endl <<
           "Number of words: " << statistic.numberWords << std::endl;
    return stream;
}

void StatisticOfDirectory::join(const StatisticOfDirectory &otherStatistics) {
    numberFiles += otherStatistics.numberFiles;
    numberEmptyLines += otherStatistics.numberEmptyLines;
    numberNonemptyLine += otherStatistics.numberNonemptyLine;
    numberLetters += otherStatistics.numberLetters;
    numberChars += otherStatistics.numberChars;
    numberWords += otherStatistics.numberWords;
}
