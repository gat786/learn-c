OUTPUT_DIR := "outputs"

outputs:
  mkdir -p {{ OUTPUT_DIR }}

hello-world: outputs
  #!/bin/bash
  gcc hello-world/main.c -o {{ OUTPUT_DIR }}/hw.out
  ./{{ OUTPUT_DIR }}/hw.out
