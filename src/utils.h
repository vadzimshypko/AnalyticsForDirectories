#pragma once

#include <filesystem>
#include <string>
#include <fstream>

namespace fs = std::filesystem;

void createFileWithDirectory(const fs::path &path, const std::string &fileName, const std::string &content);