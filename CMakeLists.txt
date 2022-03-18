cmake_minimum_required(VERSION 3.21)
project(AnalyticsForDirectories)

set(CMAKE_CXX_STANDARD 20)

add_executable(AnalyticsForDirectories src/main.cpp
        src/StatisticOfDirectory.cpp src/StatisticOfDirectory.h
        src/AnalyzerForDirectory.cpp src/AnalyzerForDirectory.h
        src/FileIterator.cpp src/FileIterator.h)
