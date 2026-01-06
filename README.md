Sorting Algorithms in C++

This project demonstrates and compares multiple sorting algorithms implemented in C++, including both sequential and parallel versions. It is intended for educational purposes, performance comparison, and learning parallel programming concepts.

Algorithms Included

The program implements the following sorting algorithms:

Bubble Sort (Sequential)

Parallel Bubble Sort

Merge Sort (Sequential)

Parallel Merge Sort

Library Sort (using the C++ Standard Library sorting function)

Features

Compares traditional sorting algorithms with their parallel counterparts

Demonstrates the impact of parallelism on sorting performance

Uses standard C++ libraries and optional parallel constructs

Works with arrays or vectors of integers

Requirements

C++ compiler that supports C++11 or later

For parallel versions:

OpenMP support (if used)

Compile with appropriate flags (see below)

Compilation
Standard Compilation
g++ program2.cpp -o sorting

Compilation with Parallel Support (OpenMP)
g++ program2.cpp -o sorting -fopenmp


Make sure your compiler supports OpenMP if you are using the parallel algorithms.

Running the Program
./sorting


Depending on the implementation, the program may:

Generate random data

Sort predefined arrays

Display timing results for each algorithm

Print sorted output to the console

Output

The program typically outputs:

The sorted array(s)

Execution time for each sorting algorithm

A comparison between sequential and parallel performance

Purpose

This project is useful for:

Learning how classic sorting algorithms work

Understanding parallel algorithm design

Comparing algorithm efficiency

Studying the performance tradeoffs between sequential and parallel execution

Notes

Parallel Bubble Sort is included for comparison purposes, even though it is not efficient in practice.

Merge Sort is generally faster and more scalable, especially in parallel implementations.

Library sort uses highly optimized algorithms provided by the C++ Standard Library.

License

This project is provided for educational use. You may modify and reuse it freely.
