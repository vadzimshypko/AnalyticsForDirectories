#include <filesystem>
#include <string>
#include <fstream>

using std::string;

namespace fs = std::filesystem;

void createFile(const fs::path &path, const std::string &fileName, const std::string &content) {
    auto file = std::ofstream(path / fileName);
    file << content;
    file.close();
}

void createExampleDirectory(const fs::path &path) {
    fs::create_directories(path / "/a/b");
    createFile(path / "/a/b", "ab.txt", "try read");
}



