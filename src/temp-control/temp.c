#include <stdio.h>

float to_celcius(int fahrenheit) {
  printf("%8d", fahrenheit);
  // in c when dividing if both the numbers are int, then the
  // result will also be int, we need to make it float
  // to get the result we want.
  float celcius = (fahrenheit - 32.0) * (5.0 / 9.0);
  printf("%8.1f\n", celcius);
  return celcius;
}

float to_fahrenheit(int celcius) {
  printf("%8d", celcius);
  float fahrenheit = (celcius / (5.0/9.0)) + 32.0;
  printf("%8.1f\n",fahrenheit);
  return fahrenheit;
}



int main() {
  printf("%8s%8s\n","fah","cel");
  for (int i = 0; i <= 200; i++){
    float celcius = to_celcius(i);
    // printf("Value outside function %d\n", celcius);
  }

  printf("%8s%8s\n","cel","fah");
  for (int i = 0; i <= 200; i++){
    float fahrenheit = to_fahrenheit(i);
    // printf("Value outside function %d\n", celcius);
  }

  return 0;
}
