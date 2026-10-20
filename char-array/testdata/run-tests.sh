#!/bin/bash
# Usage (from repo root): ./char-array/testdata/run-tests.sh
cd "$(dirname "$0")/../.."
clang char-array/longest-line-1-16.c -o outputs/longest-line-1-16.out || exit 1
pass=0; fail=0
while IFS=$'\t' read -r file want; do
  got=$(./outputs/longest-line-1-16.out < "char-array/testdata/$file" | sed 's/[^0-9]//g')
  if [ "$got" = "$want" ]; then echo "PASS $file ($got)"; ((pass++))
  else echo "FAIL $file: want $want, got $got"; ((fail++)); fi
done < char-array/testdata/expected.txt
echo "$pass passed, $fail failed"
