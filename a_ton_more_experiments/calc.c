#include <stdio.h>
#include <stdlib.h>

int main(){
  int c,i = 0;
  int total = 0;
  int op = 0;
  char buf[1000];
  void clear(){
    int j;
    for(j = 0; j < 1000; j++){
      buf[j] = 0;
    }
    i = 0;
  }
  void push(char val){
    buf[i] = val; 
    i++;
  }
  void doop(){
    if(!op) total = atoi(buf);
    else if(op == 1) total += atoi(buf);
    else if(op == 2) total -= atoi(buf);
    else if(op == 3) total *= atoi(buf);
    else if(op == 4) total /= atoi(buf);
    clear();
    printf("\033[2J\r%i%c",total,op==0?0:op==1?'+':op==2?'-':op==3?'*':'/');
  }
  clear();
  system("stty raw");
  printf("\033[2J");
  while(c = getchar()){
    switch(c){
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        push(c);
        break;
      case '+':
        doop();
        op = 1;
        break;
      case '-':
        doop();
        op = 2;
        break;
      case '*':
        doop();
        op = 3;
        break;
      case '/':
        doop();
        op = 4;
        break;
      case '=':
        doop();
        goto finish;
    }
  }
  finish:
  system("stty sane");
  printf("\nTotal: %i\n",total);
  return 0;
}
