#include <stdio.h>
#include "fbprint.h"
#define FPS 60

int main(int argc, char *argv[]){
  if(argc >= 2){
    while(1){
      fbprint(argv[1],R(0));
      usleep(1000000 / FPS);
    }
  }else{
    printf("Usage: fbprint [string]\n");
  }
  return 0;
}
