OUTPUT_DIR := "outputs"

outputs:
  mkdir -p {{ OUTPUT_DIR }}
  rm -rf {{ OUTPUT_DIR }}/*

hello-world: outputs
  #!/bin/bash
  gcc hello-world/main.c -o {{ OUTPUT_DIR }}/hw.out
  ./{{ OUTPUT_DIR }}/hw.out

temp-convertor: outputs
  #!/bin/bash
  gcc temp-convertor/main.c -o {{ OUTPUT_DIR }}/tc.out
  ./{{ OUTPUT_DIR }}/tc.out

temp-convertor-df: outputs
  #!/bin/bash
  gcc temp-convertor/df.c -o {{ OUTPUT_DIR }}/df-tc.out
  ./{{ OUTPUT_DIR }}/df-tc.out

charachters: outputs
  #!/bin/bash
  clang --std=c23 charachters/main.c -o {{ OUTPUT_DIR }}/charachters.out
  ./{{ OUTPUT_DIR }}/charachters.out

word-count: outputs
  #!/bin/bash
  clang charachters/word-count/main.c -o {{ OUTPUT_DIR }}/word-count.out
  ./{{ OUTPUT_DIR }}/word-count.out

arrays-count: outputs
  #!/bin/bash
  clang arrays/main.c -o {{ OUTPUT_DIR }}/arrays-count.out
  ./{{ OUTPUT_DIR }}/arrays-count.out

arrays-wl-count: outputs
  #!/bin/bash
  clang arrays/wl-count.c -o {{ OUTPUT_DIR }}/arrays-wl-count.out
  ./{{ OUTPUT_DIR }}/arrays-wl-count.out

ca-longest-line: outputs
  #!/bin/bash
  clang char-array/longest-line.c -o {{ OUTPUT_DIR }}/ca-longest-line.out
  ./{{ OUTPUT_DIR }}/ca-longest-line.out

ca-longest-line-1-16: outputs
  #!/bin/bash
  clang char-array/longest-line-1-16.c -o {{ OUTPUT_DIR }}/longest-line-1-16.out
  ./{{ OUTPUT_DIR }}/longest-line-1-16.out

ca-longest-line-d: outputs
  #!/bin/bash
  clang -g char-array/longest-line-dynamic.c -o {{ OUTPUT_DIR }}/ca-longest-line-dynamic.out
  lldb ./{{ OUTPUT_DIR }}/ca-longest-line-dynamic.out

ca-more-than-80: outputs
  #!/bin/bash
  clang char-array/more-than-80.c -o {{ OUTPUT_DIR }}/ca-more-than-80.out
  ./{{ OUTPUT_DIR }}/ca-more-than-80.out

ca-remove-trailing-blanks: outputs
  #!/bin/bash
  clang -g char-array/remove-trailing-blanks.c -o {{ OUTPUT_DIR }}/ca-remove-trailing-blanks.out
  ./{{ OUTPUT_DIR }}/ca-remove-trailing-blanks.out
