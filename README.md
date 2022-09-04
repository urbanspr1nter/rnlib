# rnlib
A collection of amateur C++ utilities for getting POCs written in C++ delivered faster created in August 2022.

## Introduction
`rnlib` is a personal C++ library I've written to help myself get projects up and running faster. It is designed to
help me learn more C++. Functionality and POC is a priority, so the set of utilities that come with this library is
useful for that.

This library provides:
* string-to-file and file-to-string utilities
* string manipulation utilities such as string splitting
* vector and map transformation tools
* csv reading
* basic building blocks for more complex data structures
* ... and more in the future.

what this library is **not**:
* production-ready software. DO NOT use this in your production software. All libraries are written to get code as
quickly as possible, so there are bugs.
* written by a C++ expert. 😊 -- so be careful.

what this library is:
* **not versioned**
* always improving, and trying to get better each commit.
* aims to be self-documenting
* very much a WIP

## Requirements

This works in projects created for **Microsoft Windows** under CLion. That 
is about as much as I've tested.

## Setup

Just point your include directories to the `rn.h` header file, and the library directory to 
where `rnlib.lib` is. 