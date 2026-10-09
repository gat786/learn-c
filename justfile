OUTPUT_DIR := "outputs"

outputs:
  mkdir -p {{ OUTPUT_DIR }}

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
