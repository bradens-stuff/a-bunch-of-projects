#include <string.h>
#include "keys.h"
#include "colors.h"
#include "main.h"
void on(){
  color(DIM, GREEN, BLACK);
  printf("enabled");
  reset();
} 
void off(){
  color(DIM, RED, BLACK);
  printf("not enabled");
  reset();
} 
void err(){
  printf("Options: clock or -c; stopwatch or -s\n");
  printf("Clock is ");
  #ifdef CLOCK_H
    on();
  #else
    off();
  #endif
  printf("Stopwatch is ");
  #ifdef STOPWATCH_H
    on();
  #else
    off();
  #endif
}

int main(int argc, char *argv[]){
  if(argc > 1){
    #ifdef CLOCK_H
      if(!strcmp(argv[1], "clock") || !strcmp(argv[1], "-c")){
        _clock();
      }
    #endif
    #ifdef STOPWATCH_H
      if(!strcmp(argv[1], "stopwatch") || !strcmp(argv[1], "-s")){
        stopwatch();
      }
    #endif
    err();
  }else{
    printf("cunts");
    err();
  }
  return 0;
}
