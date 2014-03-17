#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "table.h"
int main(){
  srand(time(0));
  int i;
  unsigned char _table[TX * TY];
  for(i = 0; i < TX * TY; i++){ // generate ascii _table
    _table[i] = i;
    //_table[i] = rand();
  }
  table(_table);
  return 0;
}
