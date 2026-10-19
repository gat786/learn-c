#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int getline2(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line, counting lines of any length */
int main() {
  int len; /* length of the current chunk */
  int total; /* length of the current line so far, across chunks */
  int max; /* maximum length seen so far */
  char line[MAXLINE]; /* current input chunk */
  char first[MAXLINE]; /* first chunk of the current line */
  char longest[MAXLINE]; /* first chunk of the longest line saved here */
  max = 0;
  total = 0;
  while ((len = getline2(line, MAXLINE)) > 0) {
    if (total == 0) /* start of a new line */
      copy(first, line);
    total += len;
    if (line[len-1] == '\n') { /* end of the line reached */
      if (total > max) {
        max = total;
        copy(longest, first);
      }
      total = 0;
    }
  }
  if (total > max) { /* last line had no trailing newline */
    max = total;
    copy(longest, first);
  }

  if (max > 0) /* there was a line */ {
    printf("%s", longest);
    if (max >= MAXLINE) printf("...");
    printf("\n");
    for(int i = 0; i < 25; i++) printf("-");
    printf("\n");
    printf("number of chars: %d\n", max);
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
  int i;
  i = 0;
  while ((to[i] = from[i]) !='\0')
    ++i;
}
