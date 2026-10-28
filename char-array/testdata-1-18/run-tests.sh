#!/bin/bash
# Usage (from repo root): ./char-array/testdata-1-18/run-tests.sh
# Exercise 1-18: remove trailing blanks and tabs from each line of input, and delete entirely blank lines.
# A line that ends without '\n' (last line of input) is printed without one.
# Only ' ' and '\t' count as blanks; other characters such as '\r' are left alone.
# Each NN-name.txt is fed to the program and its output must match NN-name.expected byte for byte.
cd "$(dirname "$0")/../.."
export LC_ALL=C
mkdir -p outputs
clang char-array/remove-trailing-blanks.c -o outputs/remove-trailing-blanks.out || exit 1

pass=0; fail=0
for input in char-array/testdata-1-18/*.txt; do
  expected="${input%.txt}.expected"
  if ./outputs/remove-trailing-blanks.out < "$input" | cmp -s - "$expected"; then
    echo "PASS $(basename "$input")"; ((pass++))
  else
    echo "FAIL $(basename "$input")"; ((fail++))
    echo "  want: $(head -c 100 "$expected" | cat -vt | tr '\n' '|')"
    echo "  got:  $(./outputs/remove-trailing-blanks.out < "$input" | head -c 100 | cat -vt | tr '\n' '|')"
  fi
done
echo "$pass passed, $fail failed"
