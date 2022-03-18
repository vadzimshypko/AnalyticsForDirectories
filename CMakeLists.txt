cmake_minimum_required(VERSION 3.21)
project(AnalyticsForDirectories)

set(CMAKE_CXX_STANDARD 20)

add_library(source
        src/StatisticOfDirectory.cpp src/StatisticOfDirectory.h
        src/AnalyzerForDirectory.cpp src/AnalyzerForDirectory.h
        src/FileIterator.cpp src/FileIterator.h)

add_executable(analytics_for_directories
        src/main.cpp)

target_link_libraries(analytics_for_directories
        source)

# Adding gtest dependency
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

include(FetchContent)
FetchContent_Declare(
        googleTest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googleTest)

add_executable(
        unit_tests
        test/StatisticOfDirectory_tests.cpp
)

target_link_libraries(
        unit_tests
        gtest_main
        source
)

include(googleTest)
gtest_discover_tests(unit_tests)