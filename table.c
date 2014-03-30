#include <stdio.h>
#include "table.h"

void table(unsigned char *_table){
  int i,j;
  unsigned char cur;
  printf("\n" B "+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+" R "\n");
  printf(B "|   |");
  for(i = 0; i < 0x10; i++) printf(LW " %X " B "|", i);
  printf("\n" B "+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+" R "\n");
  for(i = 0; i < TY; i++){
    printf(B "| " LW "%02X" B "| " R,16*i);
    for(j = 0; j < TX; j++){
      cur = _table[j + i * TX];
      if(cur < 32){
        printf(G "^%c" R, cur + 0x40);
      }else if(cur > 0x7E){
        printf(G "^?" R);
      }else{
        if(cur > 0x2F && cur < 0x3A)printf(RD);
        if((cur > 0x40  && cur < 0x5B ) || (cur > 0x60 && cur < 0x7B))printf(LB);
        printf("%c " R, _table[j + i*TX]);
      }
      printf(B "| " R);
    }
    printf("\n" B "+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+" R "\n");
  }
}
