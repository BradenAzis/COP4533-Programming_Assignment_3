#!/bin/bash

g++ src/HVLCS.cpp -O2 -o hvlcs

# Clear output file
echo -n "" > runtimes.txt

for f in inputs/*.txt; do
    # Print filename (no newline)
    echo -n "$f " >> runtimes.txt

    # Capture ONLY stderr for runtime
    runtime=$(./hvlcs < "$f" 2>&1 1>/dev/null)

    # Write the runtime to the file
    echo "$runtime" >> runtimes.txt
done