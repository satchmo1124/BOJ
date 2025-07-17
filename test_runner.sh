#!/bin/bash

# Compile your C++ code
g++ -o main main.cpp
if [ $? -ne 0 ]; then
    echo "❌ Compilation failed."
    exit 1
fi

echo "✅ Compilation succeeded."

# Run through all input*.txt files in ./tests/
for input_file in tests/input*.txt; do
    # Extract the test number from filename
    test_num=$(basename "$input_file" | grep -o '[0-9]\+')

    expected_file="tests/expected${test_num}.txt"
    output_file="tests/output${test_num}.txt"

    if [ ! -f "$expected_file" ]; then
        echo "⚠️  Skipping test $test_num (missing expected${test_num}.txt)"
        continue
    fi

    # Run the program with input
    ./main < "$input_file" > "$output_file"

    # Compare the output
    if diff -q "$expected_file" "$output_file" > /dev/null; then
        echo "✅ Test $test_num passed"
    else
        echo "❌ Test $test_num failed"
        echo "--- Expected Output:"
        cat "$expected_file"
        echo "--- Your Output:"
        cat "$output_file"
        echo "----------------------"
    fi
done
