#include <stdio.h>
#include "Bool.h"

int main(){
  Bool512 b;
  b(504, Set);
  b(505, Set);
  b(506, Set);
  b(504, Unset);
  int i = 0;
  while(i < 512){
    printf("Option #%02i: %s\n",i,b[i] ? "True" : "False");
    i++;
  }
  return 0;
}
