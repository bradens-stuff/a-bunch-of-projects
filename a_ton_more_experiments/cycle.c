#include <stdio.h>

int cycle(int n, int size){
  return n%size>size/2?size/2-(n%size-size/2):n%size;
}

int main(){
  int y = 0, x, i;
  while(1){
    y++;
    x = cycle(y,80);
    for(i = 0; i < x; i++)    putchar(32);
    printf("#\n",x,y);
  }
}
