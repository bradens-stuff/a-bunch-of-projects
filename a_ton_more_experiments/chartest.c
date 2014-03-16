//purpose: test if char[100][100] is the same as a mapped char[100 * 100], where coordinates are gotten from x + y * width

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#define X 100
#define Y 50
#define density 1000

int main(){
  srand(time(0));
  int i = 0, j = 0;
  char ptr[ X * Y ];
  for(i = 0; i < Y; i ++)
  for(j = 0; j < X; j ++){
    ptr[j + i*X] = ' ';
  }
  while(++i < density){
    ptr[rand()%(X*Y)] = '#';
  }
  for(i = 0; i < Y; i ++){
    for(j = 0; j < X; j ++){
      printf("%c",ptr[j + i * X]);
    }
  putchar(10);
  }
  return 0;
}
