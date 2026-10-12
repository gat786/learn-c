#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

// Exercise 1-13. Write a program to print a histogram of the lengths of words
// in its input. It is easy to draw the
// histogram with the bars horizontal; a vertical orientation is more
// challenging.

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

  int histogram_size = 100;
  int *histogram = malloc(histogram_size * sizeof(int));

  int longest_word = 0;

  for (int i = 0; i < 100; i++)
    histogram[i] = 0;

  while((c= getchar()) != EOF){
    if (words_counted >= histogram_size) {
      histogram_size += 100;
      int *new_hist = realloc(histogram, histogram_size * sizeof(int));

      if (new_hist == NULL) {
        printf("realloc failed, not enough memory\n");
        free(histogram);
        return 1;
      }

      histogram = new_hist;
    }

    if (c == ' ' || c == '\n' || c == '\t') {
      histogram[words_counted] = current_word_length;
      if (current_word_length > longest_word)
        longest_word = current_word_length;
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

  // horizontal histogram
  for (int i = 1; i < 1 + words_counted; i++) {
    print_counted_stars(histogram[i]);
  }

  // vertical histogram
  for(int i = longest_word; i > 0; i--) {
    for (int j = 0; j < histogram_size; j++) {
        if (histogram[j] >= i) {
            printf("* ");
        } else {
            printf("  ");
        }
    }
    printf("\n");
  }

  printf(
    "words counted: %d, size of histogram: %d, longest word: %d\n",
    words_counted,
    histogram_size,
    longest_word
  );
  free(histogram);
  return 0;
}
