#include "AnalyzerForDirectory.h"

StatisticOfDirectory AnalyzerForDirectory::process(const fs::path &pathForAnalyze) {
    StatisticOfDirectory statistic{pathForAnalyze.string()};
    for (auto const &dir_entry: fs::recursive_directory_iterator(pathForAnalyze)) {
        std::cout << dir_entry << '\n';
        if (dir_entry.is_regular_file()) {
            ++statistic.numberFiles;
            processFile(dir_entry, &statistic);
        }
    }
    return statistic;
}

void AnalyzerForDirectory::processFile(const fs::directory_entry &entry, StatisticOfDirectory *statistic) {
    std::ifstream ifstream{entry.path()};
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
        countWords(line, statistic);
    }
}

void AnalyzerForDirectory::countWords(const std::string &text, StatisticOfDirectory *statistic) {
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
