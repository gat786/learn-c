#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000 /* maximum input line length */

int getline2(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main() {
  char line[MAXLINE];
  int len = 0;

  // char *longest;
  // longest = malloc(MAXLINE);

  int curr_line_length = 0;
  int maximum = 0;

  while ((len = getline2(line, MAXLINE)) > 0) {
    curr_line_length += (len - 1);

    if (line[len - 1] != '\n') {
      continue;
    }

    if (curr_line_length > maximum) {
      maximum = curr_line_length;
    }

    if (line[len - 1] == '\n') {
      curr_line_length = 0;
    }
  }
  if (line[len - 1] != '\n' && line[len] == '\0') {
    if (len > maximum) {
      maximum = len;
    }
  }

  printf("maximum: %d", maximum);
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
  int i;
  i = 0;
  while ((to[i] = from[i]) !='\0')
    ++i;
}
