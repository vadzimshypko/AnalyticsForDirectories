#pragma once

#include <filesystem>
#include <mutex>
#include <atomic>

namespace fs = std::filesystem;

class FileIterator {
public:
    explicit FileIterator(const fs::path &root);

    fs::path next();

    bool isAll();

private:
    fs::recursive_directory_iterator beginIterator;
    fs::recursive_directory_iterator endIterator;
    std::atomic_bool isAll_;
    std::mutex mutexToIterator;
};
