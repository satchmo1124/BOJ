#!/bin/bash

# compile
g++ -std=c++17 -Wall -o a.out "$1" || exit 1

# run
./a.out

# Clean up
rm -f a.out