#include <stdio.h>

int to_celcius(int fahrenheit) {
  printf("%8d", fahrenheit);
  // in c when dividing if both the numbers are int, then the
  // result will also be int, we need to make it float
  // to get the result we want.
  float celcius = (fahrenheit - 32.0) * (5.0 / 9.0);
  printf("%8.1f\n", celcius);
  return celcius;
}

int main() {
  printf("%8s%8s\n","fah","cel");
  for (int i = 0; i <= 200; i++){
    int celcius = to_celcius(i);
    // printf("Value outside function %d\n", celcius);
  }

  return 0;
}
