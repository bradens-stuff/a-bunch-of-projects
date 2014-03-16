#include "bitmask.h"

unsigned int settings = 0;

int ipow(int a, int b){
  if(b == 0){
     return 1;
  }
  int c = a;
  while(b-->1){
    c = a * c;
  }
  return c;
}

int get(int n){
  return (settings >> n) & 1;
}
void toggle(int n){
  if(get(n)){
    settings -= ipow(2,n);
  }else{
    settings += ipow(2,n);
  }
}
