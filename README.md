# Circular Buffer Implementation
# Course: CE-ESY26 - Assignment 1

## Description
Manual implementation of a Circular Buffer in C, managing read and write pointers through a fixed-size array.

## Features
- Circular data storage using modulo arithmetic.
- Manual pointer management (head and tail).
- Detection of Buffer Overflow and Buffer Underflow.
- Sequential character processing.

## Implementation Details
- Data Structure: Struct containing a buffer array, head, tail, and count.
- Operations: init, write, read, isFull, and isEmpty.
- Process: Accepts user input, appends "CE-ESY", writes to buffer, and reads back for display.

## Files
- majd khangi.c: Source code.
- README.md: Documentation.

## Requirements
- C Compiler (e.g., GCC).
- Standard C Libraries (stdio.h, string.h).
