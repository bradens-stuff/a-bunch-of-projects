#include <stdio.h>

int main(){
  FILE *txt = fopen("./hellothere.txt","w");
  fputs("GOT YOU\n",txt);
  fclose(txt);
  return 0;
}
