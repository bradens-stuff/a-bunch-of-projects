//Purpose: to look at patterns in binary, particularly powers and multiplicatives or 2, 3 and so on.#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include "binary.h"

int atoi(char *str);

int main(int argc, char *argv[]){
  int arg, i;
  printf("DEC  HEX  BINARY\n");
  for(i = 1; i < argc; i++){
    arg = atoi(argv[i]);
    printf("%03d  %02x   ",arg,arg);
    binary(arg);
    printf("\n");
  }
  return 0;
}

