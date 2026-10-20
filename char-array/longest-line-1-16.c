#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int getline2(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
int main() {
  int len; /* current line length */
  char line[MAXLINE]; /* current input line */

  int max; /* maximum length seen so far */
  max = 0;

  char *curr_buffer, *tmp_buffer, *longest;
  int curr_buffer_l, tmp_buffer_l;

  int current_line_length = 0;
  max = 0;
  while ((len = getline2(line, MAXLINE)) > 0){
    if (line[len - 1] != '\n') {
      /* there was no line break found */
      current_line_length += (len - 2);
      continue;
    }
    current_line_length += (len - 1);
    if (current_line_length > max) {
      max = current_line_length;
    }
    if(line[len - 1] == '\n'){
      current_line_length = 0;
    }
  }

  printf("max: %d\n", max);
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
  int i;
  i = 0;
  while ((to[i] = from[i]) !='\0')
    ++i;
}
