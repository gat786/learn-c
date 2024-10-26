#include <stdio.h>

int to_celcius(int fahrenheit) {
  printf("Temp in fahrenheit %d\n", fahrenheit);
  // in c when dividing if both the numbers are int, then the
  // result will also be int, we need to make it float
  // to get the result we want.
  int celcius = (fahrenheit - 32) * (5.0 / 9.0);
  printf("Temperature in celcius %d\n", celcius);
  return celcius;
}

int main() {
  for (int i = 0; i <= 200; i++){
    int celcius = to_celcius(i);
    printf("Value outside function %d\n", celcius);
  }

  return 0;
}
