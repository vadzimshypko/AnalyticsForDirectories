
## TASK

Create the application that will analyze and show statistics of specified directory that will handle recursive directories. It should print number of files and total number of lines (might as well count non-empty and empty lines). Provide unit tests for solutions.- Application should use multithreading (keep in mind system limitations, you might need to control number of concurrent calls, e.g., use thread pool).
- Use std::filesystem
- Use GTest for Unit Tests
- As a bonus, you could also count words and letters and provide performance benchmarks (e.g., measure the impact of using the different number of threads)

## HOW TO START

Application gets two attribute for start:
* path to directory(necessarily)
* number of threads(optional)

**Example**: ~\AnalyticsForDirectories\cmake-build-debug\AnalyticsForDirectories.exe .temp\ 8

## PERFORMANCE

Provide performance benchmarks based on my e-library (and 16 copies of it). Got next result:

**Debug**

* Number of threads = 1, completed in 90.943seconds.
* Number of threads = 2, completed in 47.51seconds.
* Number of threads = 3, completed in 34.589seconds.
* Number of threads = 4, completed in 28.353seconds.
* Number of threads = 5, completed in 24.329seconds.
* Number of threads = 6, completed in 22.004seconds.
* Number of threads = 7, completed in 22.372seconds.
* Number of threads = 8, completed in 20.733seconds.
* Number of threads = 9, completed in 19.814seconds.
* Number of threads = 10, completed in 20.732seconds.
* Number of threads = 11, completed in 19.541seconds.
* Number of threads = 12, completed in 19.942seconds.
* Number of threads = 13, completed in 20.128seconds.
* Number of threads = 14, completed in 20.04seconds.
* Number of threads = 15, completed in 19.007seconds.

**Release**

* Number of threads = 1, completed in 64.753 seconds.
* Number of threads = 2, completed in 24.136 seconds.
* Number of threads = 3, completed in 17.515 seconds.
* Number of threads = 4, completed in 13.493 seconds.
* Number of threads = 5, completed in 13.883 seconds.
* Number of threads = 6, completed in 15.542 seconds.
* Number of threads = 7, completed in 13.671 seconds.
* Number of threads = 8, completed in 11.491 seconds.
* Number of threads = 9, completed in 12.336 seconds.
* Number of threads = 10, completed in 12.501 seconds.
* Number of threads = 11, completed in 12.931 seconds.
* Number of threads = 12, completed in 14.199 seconds.
* Number of threads = 13, completed in 11.319 seconds.
* Number of threads = 14, completed in 13.445 seconds.
* Number of threads = 15, completed in 12.366 seconds.





Description e-library:
* Number of files: 1330
* Number of empty lines: 95506
* Number of nonempty lines: 9005446
* Common number of lines: 9100952
* Number of letters: 702669858
* Number of chars: 2346077711
* Number of words: 51045543

