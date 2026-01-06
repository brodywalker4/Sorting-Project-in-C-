Sorting Algorithms in C++

This project demonstrates and compares multiple sorting algorithms implemented in C++, including both sequential and parallel versions. It is intended for educational purposes, performance comparison, and learning parallel programming concepts.

Algorithms Included

Bubble Sort (Sequential), Parallel Bubble Sort, Merge Sort (Sequential), Parallel Merge Sort, and the C++ Standard Library Sort algorithm.

Features

Sequential and parallel sorting implementations, performance comparison between algorithms, demonstration of parallel programming concepts, use of standard C++ libraries, and support for sorting arrays or vectors of integers.

Requirements

A C++ compiler supporting C++11 or later, OpenMP support for parallel algorithms if enabled, and a system capable of running multithreaded programs.

Compilation
Standard Compilation
g++ program2.cpp -o sorting

Compilation with Parallel Support (OpenMP)
g++ program2.cpp -o sorting -fopenmp

Running the Program
./sorting


The program may generate random input data, sort predefined or user-provided arrays, display execution times, and output sorted results depending on the implementation.

Output

Sorted arrays, execution time for each sorting algorithm, and performance comparisons between sequential and parallel approaches.

Purpose

Learning how classic sorting algorithms work, understanding parallel algorithm design, analyzing performance differences, and comparing optimized library implementations with manual algorithms.

Notes

Parallel Bubble Sort is included for demonstration purposes despite its inefficiency, Merge Sort generally performs better and scales well with parallel execution, and the library sort uses highly optimized algorithms provided by the C++ Standard Library.

License

Provided for educational use, free to modify and reuse.
