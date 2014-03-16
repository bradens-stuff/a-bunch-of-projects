#include <stdio.h>

int p(int a, int b){
  int tot = a;
  while(b--)    tot *= a;
  return tot / a;
}

int str2num(char *src){
  unsigned int i = 0;
  unsigned int magnitude = 0;
  unsigned int total = 0;
  while(1){ // validate string and find magnitude
    if(*(src+i) == 0)    break;
    if(!(*(src+i) >= '0' && *(src+i) <= '9'))    break;
    else{
      magnitude ++;
    }
    i++;
  }
  i = 0;
  if(magnitude == 1){
    total = *(src) - '0';
    return total;
  }else{
    while(magnitude){
      int selected = *(src+i) - '0';
      printf("i: \t\t%i\nmagnitude: \t10^%i = %i\nselected: \t%i\npre-total: \t%i\n",i,magnitude-1,p(10,magnitude-1),selected,total);
      total += p(10, magnitude-1) * selected;
      printf("post-total: \t%i\n\n",total);
      i++;
      magnitude--;
    }
    return total;
  }
}

int main(int argc, char **argv){
  int num = str2num(argv[1]);
  printf("%s => %i\n",argv[1],num);
  return 0;
}
