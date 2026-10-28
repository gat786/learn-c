#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int getline2(char s[],int lim);
int main(){
  char line[MAX_SIZE]; /* line recorded */

  char buffer[MAX_SIZE] = "\0";
  int buff_index = 0;
  int has_text = 0; /* has the current line printed a non-blank char? */

  int size;

  /* buffer and has_text are reset only at '\n', not per getline2 call,
     so lines longer than MAX_SIZE carry pending blanks across chunks */
  while((size = getline2(line, MAX_SIZE)) > 0) {
    for (int i = 0; i < size; ++i){
      if (line[i] == ' ' || line[i] == '\t'){
        if (buff_index < MAX_SIZE - 1) {
          buffer[buff_index] = line[i];
          buff_index += 1;
          buffer[buff_index] = '\0';
        }
        continue;
      } else if (line[i] == '\n') {
        buff_index = 0;
        buffer[0] = '\0';
        if (has_text)
          putchar('\n');
        has_text = 0;
      } else {
        printf("%s", buffer);
        buff_index = 0;
        buffer[0] = '\0';
        printf("%c", line[i]);
        has_text = 1;
      }

    }
  }
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
