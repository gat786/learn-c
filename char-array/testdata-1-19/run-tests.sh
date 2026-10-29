#!/bin/bash
# Usage (from repo root): ./char-array/testdata-1-19/run-tests.sh
# Exercise 1-19: reverse the input a line at a time.
# Each line's characters are reversed; the '\n' stays at the end of the line.
# A line that ends without '\n' (last line of input) is printed reversed without one.
# Lines longer than 999 characters keep only their first 999 (MAXLINE - 1), reversed.
# Each NN-name.txt is fed to the program and its output must match NN-name.expected byte for byte.
# Every test prints its input, expected and actual output in full (via cat -vet):
#   '$' marks the end of a line (a missing '$' means no trailing '\n'), '^I' is a tab.
cd "$(dirname "$0")/../.."
export LC_ALL=C
mkdir -p outputs
clang char-array/reverse-string.c -o outputs/reverse-string.out || exit 1

show() {
  if [ -s "$1" ]; then
    cat -vet "$1" | sed 's/^/    /'
    # cat -vet leaves no newline after a final line without '\n'
    [ -n "$(tail -c 1 "$1")" ] && echo
  else
    echo "    (empty)"
  fi
}

actual=$(mktemp)
trap 'rm -f "$actual"' EXIT

pass=0; fail=0
for input in char-array/testdata-1-19/*.txt; do
  expected="${input%.txt}.expected"
  ./outputs/reverse-string.out < "$input" > "$actual"
  if cmp -s "$actual" "$expected"; then
    status="PASS"; ((pass++))
  else
    status="FAIL"; ((fail++))
  fi
  echo "==================== $status $(basename "$input") ===================="
  echo "  input:"
  show "$input"
  echo "  expected:"
  show "$expected"
  echo "  got:"
  show "$actual"
  echo
done
echo "$pass passed, $fail failed"
[ "$fail" -eq 0 ]
