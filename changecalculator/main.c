#include "main.h"

int main(int argc, char **argv){
  if(argc > 1){
    printf("Input: %s\nOutput:\n",argv[1]);
    FUNC(argv[1]);
  }else{
    printf("Usage: %s $[dollar amount]\n",argv[0]);
  }
  return 0;
}
