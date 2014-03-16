#include <stdio.h>
#include <stdlib.h>
//Usage: ./a.out < file
int main(){
  int stdinl = 0, pos = 0;
  fpos_t *fpos;
  char c;
  char *s;
  fgetpos(stdin, &fpos);
  while((c = getc(stdin)) != EOF) stdinl++;
  fsetpos(stdin, &fpos);
  s = malloc(stdinl * sizeof(char));
  while((c = getc(stdin)) != EOF) s[pos++] = c;
  while(pos--) putchar(s[pos]);
  free(s);
  free(fpos);
  return 0;
}
