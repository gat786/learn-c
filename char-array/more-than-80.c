// Exercise 1-17
#include <stdio.h>

#define MAX_INPUT 1000

int getline2(char* , int);

int main(){

  char line_array[MAX_INPUT];
  int length = 0;
  int continue_line = 1;

  while ((length = getline2(line_array, MAX_INPUT)) > 0){
    int visible_chars_length = length;

    if (line_array[length - 1] == '\n') visible_chars_length--;

    if (continue_line == 0 || visible_chars_length > 80){
     printf("%s", line_array);
     if (line_array[length - 1] != '\n'){
       continue_line = 0;
     } else {
       continue_line = 1;
     }
     continue;
    }
    continue_line = 1;
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
