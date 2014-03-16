#include "bitmask.h"

unsigned int settings = 0;

int get(int n){
  return (settings >> n) & 1;
}
void toggle(int n){
  if(get(n)){
    settings -= 1 << n;
  }else{
    settings += 1 << n;
  }
}
