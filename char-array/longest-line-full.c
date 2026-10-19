#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000 /* size of each chunk read by getline2 */

int getline2(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line in full, whatever its length */
int main() {
  int len; /* length of the current chunk */
  int total; /* length of the current line so far, across chunks */
  int max; /* maximum length seen so far */
  char line[MAXLINE]; /* current input chunk */
  char *cur, *longest, *tmp; /* heap buffers: line being built, longest line */
  int curcap, longcap, tmpcap; /* bytes allocated for each buffer */

  curcap = longcap = MAXLINE;
  cur = malloc(curcap);
  longest = malloc(longcap);
  if (cur == NULL || longest == NULL) {
    printf("error: out of memory\n");
    return 1;
  }
  max = 0;
  total = 0;
  while ((len = getline2(line, MAXLINE)) > 0) {
    if (total + len + 1 > curcap) { /* chunk won't fit: grow cur */
      while (total + len + 1 > curcap)
        curcap *= 2;
      tmp = realloc(cur, curcap);
      if (tmp == NULL) {
        printf("error: out of memory\n");
        return 1;
      }
      cur = tmp;
    }
    copy(&cur[total], line); /* append chunk after what we have so far */
    total += len;
    if (line[len-1] == '\n') { /* end of the line reached */
      if (total > max) {
        max = total;
        /* swap buffers instead of copying: cur becomes the longest,
           and the old longest buffer gets reused for the next line */
        tmp = longest; longest = cur; cur = tmp;
        tmpcap = longcap; longcap = curcap; curcap = tmpcap;
      }
      total = 0;
    }
  }
  if (total > max) { /* last line had no trailing newline */
    max = total;
    tmp = longest; longest = cur; cur = tmp;
  }

  if (max > 0) /* there was a line */ {
    printf("%s\n", longest);
    for(int i = 0; i < 25; i++) printf("-");
    printf("\n");
    printf("number of chars: %d\n", max);
  }
  free(cur);
  free(longest);
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
