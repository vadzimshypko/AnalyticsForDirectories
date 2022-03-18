#include <gtest/gtest.h>
#include "../src/utils.h"
#include "../src/FileIterator.h"

TEST(FileIterator, isAll) {
    fs::path testPath(".out/test/");
    createFileWithDirectory(testPath, "file.txt", "42");
    FileIterator iterator(testPath);
    EXPECT_FALSE(iterator.isAll());
    EXPECT_EQ(iterator.next().string(), testPath / "file.txt");
    EXPECT_TRUE(iterator.isAll());
    fs::remove_all(testPath);
}
