#include <ostream>
#include "StatisticOfDirectory.h"

std::ostream &operator<<(std::ostream &stream, const StatisticOfDirectory &statistic) {
    return stream << "Statistics for " << statistic.path << std::endl <<
                  "Number of files: " << statistic.numberFiles << std::endl <<
                  "Number of empty lines: " << statistic.numberEmptyLines << std::endl <<
                  "Number of nonempty lines: " << statistic.numberNonemptyLine << std::endl <<
                  "Common number of lines: " << (statistic.numberEmptyLines + statistic.numberNonemptyLine) << std::endl <<
                  "Number of letters: " << statistic.numberLetters << std::endl <<
                  "Number of chars: " << statistic.numberChars << std::endl <<
                  "Number of words: " << statistic.numberWords <<
                  std::endl;
}
