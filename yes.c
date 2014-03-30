#include <stdio.h>
#include <string.h>

int main(int c, char **v){
  int i;
  char str[1000] = "";

  if(c > 1){
    for(i = 1; i < c; i++){
      if(i > 1){
        strcat(str," ");
      }
      strcat(str,v[i]);
    }
  }else{
    str[0] = 'y';
  }

  while(1){
    printf("%s\n",str);
  }

  return 0;
}
