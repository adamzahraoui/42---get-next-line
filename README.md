# Get Next Line

## Introduction

**Get Next Line** is a function that allows you to read a line from a file descriptor efficiently. This project is often a foundational part of learning file I/O and memory management in C programming. It is designed to handle edge cases such as multiple file descriptors, EOF, and memory leaks.

---

## Features

- Reads one line at a time from a file descriptor.
- Supports multiple file descriptors simultaneously.
- Handles any valid buffer size for reading.
- Ensures efficient memory allocation and management.

---

## Requirements

To compile and use the **Get Next Line** function, you'll need:

- A C compiler (e.g., `gcc`).
- Standard C libraries (`unistd.h`, `stdlib.h`, `fcntl.h`).

---

## Usage

### Function Prototype

```c
char *get_next_line(int fd);
