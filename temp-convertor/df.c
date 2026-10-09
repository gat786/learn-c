#include <stdio.h>

# define UPPER 300
# define LOWER 0
# define STEP 20

void for_looper(){
  float celcius;
  printf("%5s %10s\n", "fahr", "celc");
  for (float fahr = LOWER; fahr <= UPPER; fahr += STEP){
    celcius = 5.0/9.0 * (fahr - 32.0);
    printf("%5.0f %10.1f\n", fahr, celcius);
  }
}

int main(){
  for_looper();
}
