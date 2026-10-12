#include <stdio.h>

void print_counted_stars(int count) {
  for (int i = 0; i < count; i++) {
    putchar('*');
  }
  putchar('\n');
}

int main(){
  int c;

  // 1 == OUT, 0 == IN;
  int state = 1;
  int current_word_length = 0;

  int words_counted = 0;

  int histogram[100];
  for (int i = 0; i < 100; i++)
    histogram[i] = 0;

  while((c= getchar()) != EOF){
    if (c == ' ' || c == '\n' || c == '\t') {
      if (words_counted < 100) {
        histogram[words_counted] = current_word_length;
      }else {
        printf("histogram only prints length of first 100 words encountered");
      }

      state = 1;
      current_word_length = 0;
      continue;
    }
    if (state == 1) {
      current_word_length += 1;
      state = 0;
      words_counted += 1;
      continue;
    }
    if (state == 0) {
      current_word_length += 1;
    }
  }

  printf("EOF encountered\n");
  for (int i = 1; i < 1 + words_counted; i++) {
    print_counted_stars(histogram[i]);
  }
}
