#include "utils.h"

void createFileWithDirectory(const fs::path &path, const std::string &fileName, const std::string &content) {
    fs::create_directories(path);
    auto file = std::ofstream(path / fileName);
    file << content;
    file.close();
}



