/*
* Even/odd thing by Braden Best
* No copyright
*/

#include <stdio.h>

int iseven(int n){
  return n % 2 == 0 ? 1 : 0;	
}

char * eo(int n){
  return iseven(n) ? "even" : "odd";
}

int main(void) {
  int i;
  for (i = 0; i < 100; i++){
  	printf("%d is %s\n",i,eo(i));
  }
  return 0;
}
