Module 12 — C++ and AI Performance

AI System Research: TensorFlow

For this assignment, I researched TensorFlow, an open-source machine learning framework.

TensorFlow uses C++ in its core runtime to perform computations efficiently. Python is commonly used to create and train machine learning models, while C++ helps execute performance-intensive operations. C++ also provides control over memory and supports optimized computation on CPUs and GPUs.

C++ is valuable in TensorFlow because machine learning can involve processing large amounts of numerical data. Efficient execution helps make training and inference practical.

Sources:

* TensorFlow API Documentation
* TensorFlow Architecture

Performance Feature: Faster Game Searching

For my Video Game Library application, I created a performance test comparing linear search and binary search.

The program generates 100,000 sorted game IDs and searches for ID 99999 using both methods. It repeats each search 1,000 times and measures the execution time using the C++ chrono library.

Linear search checks records one at a time, while binary search repeatedly divides the search range in half.

Binary search has a time complexity of O(log n), compared with O(n) for linear search in the worst case.

This makes binary search a useful choice for searching a large library when the records are already sorted.

How C++ Would Help My Application Grow

If my Video Game Library expanded to millions of records, performance would become more important.

C++ could help with efficient searching, managing memory, processing large datasets, and calculating recommendation scores.

If I eventually added a real AI recommendation system, C++ could handle performance-critical operations while an AI model analyzes player preferences and recommends games.

The current program is a performance demonstration, not a live AI system.
