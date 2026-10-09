#include <stdio.h>

void simple(){
  int c;
  c = getchar();
  while (c != EOF) {
    putchar(c);
    c = getchar();
  }
  printf("EOF received\n");
}

void coercion_example() {
  // c is weakly typed, meaning variable types can get converted automatically
  // to allow fastness in execution
  int a = 'a';
  printf("%c\n", a);
}

void complex(){
  int c;
  while ((c = getchar()) != EOF) {
    putchar(c);
  }
  printf("EOF received\n");
}

void value_eof(){
  int e = EOF;

  printf("EOF is %d", e);
}

void count_chars(){
  long nc = 0;
  printf("%ld\n", nc);
  while(getchar() != EOF) {
    ++nc;
  }
  printf("%ld\n", nc);
}

void line_counting(){
  int c, nl;
  nl = 0;

  while ((c = getchar()) != EOF)
    if (c == '\n')
      nl += 1;

  printf("%d\n", nl);
}

void replace_multispace_with_space() {
  int c;
  int prev_c = 0;

  while ((c = getchar()) != EOF) {
    if (prev_c == ' ' & c == ' '){
      continue;
    }
    putchar(c);
    prev_c = c;
  }
}

/* copy input to output; 1st version */
int main(){
  // coercion_example();
  // simple();
  // complex();
  // value_eof();
  // count_chars();
  replace_multispace_with_space();
}
