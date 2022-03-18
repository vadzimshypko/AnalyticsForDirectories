#include "FileIterator.h"

FileIterator::FileIterator(const fs::path &root) {
    fs::recursive_directory_iterator iterator(root);
    beginIterator = begin(iterator);
    endIterator = end(iterator);
    isAll_ = beginIterator == endIterator;
}

fs::path FileIterator::next() {
    std::lock_guard<std::mutex> lg(mutexToIterator);
    fs::path result;
    while (beginIterator != endIterator && result.empty()) {
        if (beginIterator->is_regular_file()) {
            result = beginIterator->path();
        }
        beginIterator++;
    }
    if(beginIterator == endIterator) isAll_ = true;
    return result;
}

bool FileIterator::isAll() {
    return isAll_;
}
