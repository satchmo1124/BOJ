#!/bin/bash

g++ -o main main.cpp
if [ $? -ne 0 ]; then
    echo "❌ Compilation failed."
    exit 1
fi
echo "✅ Compilation succeeded."

# Temporary files
TMP_INPUT=$(mktemp)
TMP_EXPECTED=$(mktemp)
TMP_OUTPUT=$(mktemp)

test_num=1
mode="input"
> "$TMP_INPUT"
> "$TMP_EXPECTED"

while IFS= read -r line || [ -n "$line" ]; do
    if [[ -z "$line" ]]; then
        # Blank line → end of one test case
        ./main < "$TMP_INPUT" > "$TMP_OUTPUT"

        if diff -q "$TMP_EXPECTED" "$TMP_OUTPUT" > /dev/null; then
            echo "✅ Test $test_num passed"
        else
            echo "❌ Test $test_num failed"
            echo "--- Input:"
            cat "$TMP_INPUT"
            echo "--- Expected:"
            cat "$TMP_EXPECTED"
            echo "--- Got:"
            cat "$TMP_OUTPUT"
            echo "----------------------"
        fi

        test_num=$((test_num + 1))
        > "$TMP_INPUT"
        > "$TMP_EXPECTED"
        mode="input"
        continue
    fi

    if [[ "$mode" == "input" ]]; then
        echo "$line" >> "$TMP_INPUT"
        mode="output"
    else
        echo "$line" >> "$TMP_EXPECTED"
        mode="input"
    fi
done < testcases.txt

# Final test (if file didn't end with blank line)
if [[ -s "$TMP_INPUT" || -s "$TMP_EXPECTED" ]]; then
    ./main < "$TMP_INPUT" > "$TMP_OUTPUT"

    if diff -q "$TMP_EXPECTED" "$TMP_OUTPUT" > /dev/null; then
        echo "✅ Test $test_num passed"
    else
        echo "❌ Test $test_num failed"
        echo "--- Input:"
        cat "$TMP_INPUT"
        echo "--- Expected:"
        cat "$TMP_EXPECTED"
        echo "--- Got:"
        cat "$TMP_OUTPUT"
        echo "----------------------"
    fi
fi

# Cleanup
rm "$TMP_INPUT" "$TMP_EXPECTED" "$TMP_OUTPUT"
