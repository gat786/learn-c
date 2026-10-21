#!/bin/bash
# Usage (from repo root): ./char-array/testdata-1-17/run-tests.sh
# Exercise 1-17: print all input lines longer than 80 characters (not counting '\n').
# Each NN-name.txt is fed to the program and its output must match NN-name.expected byte for byte.
cd "$(dirname "$0")/../.."
export LC_ALL=C
mkdir -p outputs
clang char-array/more-than-80.c -o outputs/more-than-80.out || exit 1

pass=0; fail=0
for input in char-array/testdata-1-17/*.txt; do
  expected="${input%.txt}.expected"
  if ./outputs/more-than-80.out < "$input" | cmp -s - "$expected"; then
    echo "PASS $(basename "$input")"; ((pass++))
  else
    echo "FAIL $(basename "$input")"; ((fail++))
    echo "  want: $(head -c 100 "$expected" | cat -v | tr '\n' '|')"
    echo "  got:  $(./outputs/more-than-80.out < "$input" | head -c 100 | cat -v | tr '\n' '|')"
  fi
done
echo "$pass passed, $fail failed"
