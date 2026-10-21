#!/bin/bash
# Usage (from repo root): ./char-array/testdata/run-tests.sh
# Each NN-name.txt is fed to the program and its output is compared with NN-name.expected.
cd "$(dirname "$0")/../.."
export LC_ALL=C
mkdir -p outputs
clang char-array/longest-line-1-16.c -o outputs/longest-line-1-16.out || exit 1

pass=0; fail=0
for input in char-array/testdata/*.txt; do
  expected="${input%.txt}.expected"
  # Blank lines are ignored, so it doesn't matter if the stored line keeps its '\n'.
  got=$(./outputs/longest-line-1-16.out < "$input" | sed '/^$/d')
  want=$(sed '/^$/d' "$expected")
  if [ "$got" = "$want" ]; then
    echo "PASS $(basename "$input")"; ((pass++))
  else
    echo "FAIL $(basename "$input")"; ((fail++))
    echo "  want: $(echo "$want" | tr '\n' '|' | cut -c1-80)"
    echo "  got:  $(echo "$got" | tr '\n' '|' | cut -c1-80)"
  fi
done
echo "$pass passed, $fail failed"
