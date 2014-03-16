#include <stdio.h>
#include <stdlib.h>

void collatz(int *n){
  if(*(n) % 2){
    *(n) *= 3;
    *(n) += 1;
  }else{
    *(n) /= 2;
  }
}

int main(int argc, char **argv){
  int i = 0, j = 0, n = 0;
  if(argc > 1){
    while(++j < argc){
      i = 0, n = atoi(argv[j]);
      printf("\n\nFor n = %i:\n",n);
      while(1){
        printf("[%i]: %i\n",i,n);
        if(n == 1)    break;
        collatz(&n);
        i++;
      }
    }
  }else{
    printf("Usage: %s [n]\nThe Collatz conjcture says that by dividing even numbers by 2 and multiplying odd by 3 and adding 1, you can get any number down to 1. Try it!\n",argv[0]);
  }
  return 0;
}
