#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int getline2(char line[], int maxline);

int main() {
  int len; /* current line length */

  char line[MAXLINE]; /* current input line */
  int line_char_index = 0;

  char line_to_rev[MAXLINE];

  while ((len = getline2(line, MAXLINE)) > 0){
    for (int j = 0; j < len && line[j] != '\n'; j++) {
      if (line_char_index < MAXLINE - 1) {
        line_to_rev[line_char_index] = line[j];
        line_char_index++;
      }
    }
    if (line[len-1] == '\n') {
      for(int i = line_char_index - 1 ; i >= 0; i--) {
        printf("%c", line_to_rev[i]);
      }
      printf("\n");
      line_char_index = 0;
    }
  }

  for(int i = line_char_index - 1 ; i >= 0; i--) {
    printf("%c", line_to_rev[i]);
  }

  return 0;
}

/* getline2: read a line into s, return length */
// s is getting passed as a reference because it is an array
int getline2(char s[],int lim) {
  int c, i;
  for (i=0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}
