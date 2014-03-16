#include <stdio.h>
#include <string.h>
#define WDLENGTH 100

typedef struct{
  int x;
  int y;
  char c[WDLENGTH * 100];
} shit;

shit split(char *in){
  shit out;
  out.x = 0;
  out.y = 0;
  int k = 0;
  while(1){
    if(in[k] == 0){
      out.y++;
      out.x++;
      break;
    }
    if(in[k] == 32){
      out.x = 0;
      out.y++;
      k++;
      continue;
    }else{
      out.c[out.x + out.y * WDLENGTH] = in[k];
      out.x++;
      k++;
    }
  }
  return out;
}

int main(int c, char **argv){
  shit o = split(argv[1]);
  int i,j,k,l;
  for(i = 0; i < o.y; i++){
    for(j = WDLENGTH-1; j >= 0; j--){
      putchar(o.c[j + i * WDLENGTH]);
    }
    putchar(32);
  }
  return 0;
}
