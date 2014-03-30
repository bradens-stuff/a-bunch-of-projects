#include <stdio.h>
#include "isvowel.h"
int main(int argc, char *argv[]){
  char c, 
       choice;
  short isloop = 1, 
        i;
  if(argc > 1){
    isloop = 0;
  }
  if(isloop){
    while(1){
      printf("Enter a character: $");
      scanf(" %c",&c);
      if(isvowel(&c)){
        printf("'%c' is a vowel\n",c);
      }else{
        printf("'%c' is not a vowel\n",c);
      }
      printf("Again? (y/n) $");
      scanf(" %c",&choice);
      if(choice != 'y'){
        break;
      }
    }
  }else{
    for(i = 1; i < argc; i++){
      if(isvowel(&argv[i][0])){
        printf("'%c' is a vowel\n",argv[i][0]);
      }else{
        printf("'%c' is not a vowel\n",argv[i][0]);
      }
    }
  }
  return 0;
}
