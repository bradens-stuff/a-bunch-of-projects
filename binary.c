#include <stdio.h>
#include "binary.h"
void binary(int dec){
  int a = dec,
      b = 0,
      c = 0;
  for(c = 7; c >= 0; c--){
    b = a >> c;
    if(b & 1){
      printf("1");
    }else{
      printf("0");
    }
  }
}
