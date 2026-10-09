#include <stdio.h>

void celc_to_fahr(){
  float celcius, fahr;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  celcius = lower;

  printf("%5s %10s\n", "fahr", "celc");
  while (celcius <= upper){
    fahr = 9.0/5.0 * celcius + 32.0;
    printf("%5.1f %10.0f\n", fahr, celcius);
    celcius += step;
  }
}

void fahr_to_celc(){
  float celcius, fahr;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;

  printf("%5s %10s\n", "fahr", "celc");
  while (fahr <= upper){
    celcius = 5.0/9.0 * (fahr - 32.0);
    printf("%5.0f %10.1f\n", fahr, celcius);
    fahr += step;
  }
}

void for_looper(){
  float celcius;
  printf("%5s %10s\n", "fahr", "celc");
  for (float fahr = 0; fahr <= 300; fahr += 20){
    celcius = 5.0/9.0 * (fahr - 32.0);
    printf("%5.0f %10.1f\n", fahr, celcius);
  }
}

int main(){
  fahr_to_celc();
  celc_to_fahr();
  for_looper();
}
