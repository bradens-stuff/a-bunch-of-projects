#include "isvowel.h"

int isvowel(char *c){
  return c[0] == 'a' ? 1 :
         c[0] == 'e' ? 1 :
         c[0] == 'i' ? 1 :
         c[0] == 'o' ? 1 :
         c[0] == 'u' ? 1 : 0;
} 
