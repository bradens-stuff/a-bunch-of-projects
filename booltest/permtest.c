/*
Bitmask Example by Braden Best
This is made as an example to show possible applications for bitmasking
*/

#include <stdio.h>
#include <stdlib.h>
#include "bitmask.h"

#define WHITE "\033[0;37m"
#define GREEN "\033[0;32m"
#define RED   "\033[0;31m"

char * on(){
  return GREEN "on" WHITE;
}

char * off(){
  return RED "off" WHITE;
}

int main(int argc, char * argv[]){
  unsigned int perm,i;
  char * emp;
  if(argc > 1){
    perm = strtoul(argv[1],&emp,8); // accept input as octal
    settings = perm; // set global settings to user input
    printf("Permission code: %u (octal %03o)\n\nFlags:\n",perm,perm);
    for(i = 0; i < 9; i++){
      printf("  %i: %s\n",i,get(i)?on():off());
    }
    printf("\nVerbose permissions:\n");
    printf("  User read:     %s\n",get(8) ? on() : off());
    printf("  User write:    %s\n",get(7) ? on() : off());
    printf("  User execute:  %s\n",get(6) ? on() : off());

    printf("  Group read:    %s\n",get(5) ? on() : off());
    printf("  Group write:   %s\n",get(4) ? on() : off());
    printf("  Group execute: %s\n",get(3) ? on() : off());

    printf("  Other read:    %s\n",get(2) ? on() : off());
    printf("  Other write:   %s\n",get(1) ? on() : off());
    printf("  Other execute: %s\n",get(0) ? on() : off());
    
    printf("\nWhat ls -l would output:  ");
    printf("-%s%s%s%s%s%s%s%s%s\n",
      get(8) ? "r" : "-",
      get(7) ? "w" : "-",
      get(6) ? "x" : "-",
      get(5) ? "r" : "-",
      get(4) ? "w" : "-",
      get(3) ? "x" : "-",
      get(2) ? "r" : "-",
      get(1) ? "w" : "-",
      get(0) ? "x" : "-"
    );
  }else{
    printf("Usage: permtest [3 digit octal number]\nExample: permtest 777\n");
  }
  return 0;
}
