#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv){
  char *str = argv[1];
  int i,
      j,
      h = 5,
      ch = 5,
      w = strlen(str) * ch;
  char display[h * w];
  for(i = 0; i < h * w; i ++){
   display[i] = 0;
  }
  void putd(c,x,y){
    display[x + y * w] = c;
  }
  char getd(x,y){
    return display[x + y * w];
  }
  for(i = 0; i < h; i++){
    for(j = 0; j < strlen(str); j++){
      switch((int)str[j]){
        case '0':
          switch(i){
            case 0: 
              putd(' ',(j*ch)+0,0);
              putd('-',(j*ch)+1,0);
              putd('-',(j*ch)+2,0);
              putd('-',(j*ch)+3,0);
              putd(' ',(j*ch)+4,0);
              break;
            case 1: 
              putd('|',(j*ch)+0,1);
              putd(' ',(j*ch)+1,1);
              putd(' ',(j*ch)+2,1);
              putd(' ',(j*ch)+3,1);
              putd('|',(j*ch)+4,1);
              break;
            case 2: 
              putd('|',(j*ch)+0,2);
              putd(' ',(j*ch)+1,2);
              putd(' ',(j*ch)+2,2);
              putd(' ',(j*ch)+3,2);
              putd('|',(j*ch)+4,2);
              break;
            case 3: 
              putd('|',(j*ch)+0,3);
              putd(' ',(j*ch)+1,3);
              putd(' ',(j*ch)+2,3);
              putd(' ',(j*ch)+3,3);
              putd('|',(j*ch)+4,3);
              break;
            case 4:
              putd(' ',(j*ch)+0,4);
              putd('-',(j*ch)+1,4);
              putd('-',(j*ch)+2,4);
              putd('-',(j*ch)+3,4);
              putd(' ',(j*ch)+4,4);
              break;
          }
          break;
        case '1':
          switch(i){
            case 0: 
              putd(' ',(j*ch)+0,0);
              putd(' ',(j*ch)+1,0);
              putd(' ',(j*ch)+2,0);
              putd(' ',(j*ch)+3,0);
              putd(' ',(j*ch)+4,0);
              break;
            case 1: 
              putd(' ',(j*ch)+0,1);
              putd(' ',(j*ch)+1,1);
              putd(' ',(j*ch)+2,1);
              putd('|',(j*ch)+3,1);
              putd(' ',(j*ch)+4,1);
              break;
            case 2: 
              putd(' ',(j*ch)+0,2);
              putd(' ',(j*ch)+1,2);
              putd(' ',(j*ch)+2,2);
              putd('|',(j*ch)+3,2);
              putd(' ',(j*ch)+4,2);
              break;
            case 3: 
              putd(' ',(j*ch)+0,3);
              putd(' ',(j*ch)+1,3);
              putd(' ',(j*ch)+2,3);
              putd('|',(j*ch)+3,3);
              putd(' ',(j*ch)+4,3);
              break;
            case 4: 
              putd(' ',(j*ch)+0,4);
              putd(' ',(j*ch)+1,4);
              putd(' ',(j*ch)+2,4);
              putd(' ',(j*ch)+3,4);
              putd(' ',(j*ch)+4,4);
              break;
          }
          break;
        case '2':
          switch(i){
            case 0: 
              putd(' ',(j*ch)+0,0);
              putd('-',(j*ch)+1,0);
              putd('-',(j*ch)+2,0);
              putd('-',(j*ch)+3,0);
              putd(' ',(j*ch)+4,0);
              break;
            case 1: 
              putd(' ',(j*ch)+0,1);
              putd(' ',(j*ch)+1,1);
              putd(' ',(j*ch)+2,1);
              putd(' ',(j*ch)+3,1);
              putd('|',(j*ch)+4,1);
              break;
            case 2: 
              putd(' ',(j*ch)+0,2);
              putd('-',(j*ch)+1,2);
              putd('-',(j*ch)+2,2);
              putd('-',(j*ch)+3,2);
              putd(' ',(j*ch)+4,2);
              break;
            case 3: 
              putd('|',(j*ch)+0,3);
              putd(' ',(j*ch)+1,3);
              putd(' ',(j*ch)+2,3);
              putd(' ',(j*ch)+3,3);
              putd(' ',(j*ch)+4,3);
              break;
            case 4: 
              putd(' ',(j*ch)+0,4);
              putd('-',(j*ch)+1,4);
              putd('-',(j*ch)+2,4);
              putd('-',(j*ch)+3,4);
              putd(' ',(j*ch)+4,4);
              break;
          }
          break;
        case '3':
          switch(i){
            case 0: 
              putd(' ',(j*ch)+0,0);
              putd('-',(j*ch)+1,0);
              putd('-',(j*ch)+2,0);
              putd('-',(j*ch)+3,0);
              putd(' ',(j*ch)+4,0);
              break;
            case 1: 
              putd(' ',(j*ch)+0,1);
              putd(' ',(j*ch)+1,1);
              putd(' ',(j*ch)+2,1);
              putd(' ',(j*ch)+3,1);
              putd('|',(j*ch)+4,1);
              break;
            case 2: 
              putd(' ',(j*ch)+0,2);
              putd('-',(j*ch)+1,2);
              putd('-',(j*ch)+2,2);
              putd('-',(j*ch)+3,2);
              putd(' ',(j*ch)+4,2);
              break;
            case 3: 
              putd(' ',(j*ch)+0,3);
              putd(' ',(j*ch)+1,3);
              putd(' ',(j*ch)+2,3);
              putd(' ',(j*ch)+3,3);
              putd('|',(j*ch)+4,3);
              break;
            case 4: 
              putd(' ',(j*ch)+0,4);
              putd('-',(j*ch)+1,4);
              putd('-',(j*ch)+2,4);
              putd('-',(j*ch)+3,4);
              putd(' ',(j*ch)+4,4);
              break;
          }
          break;
        case '4':
          switch(i){
            case 0: 
              putd(' ',(j*ch)+0,0);
              putd(' ',(j*ch)+1,0);
              putd(' ',(j*ch)+2,0);
              putd(' ',(j*ch)+3,0);
              putd(' ',(j*ch)+4,0);
              break;
            case 1: 
              putd('|',(j*ch)+0,1);
              putd(' ',(j*ch)+1,1);
              putd(' ',(j*ch)+2,1);
              putd(' ',(j*ch)+3,1);
              putd('|',(j*ch)+4,1);
              break;
            case 2: 
              putd(' ',(j*ch)+0,2);
              putd('-',(j*ch)+1,2);
              putd('-',(j*ch)+2,2);
              putd('-',(j*ch)+3,2);
              putd(' ',(j*ch)+4,2);
              break;
            case 3: 
              putd(' ',(j*ch)+0,3);
              putd(' ',(j*ch)+1,3);
              putd(' ',(j*ch)+2,3);
              putd(' ',(j*ch)+3,3);
              putd('|',(j*ch)+4,3);
              break;
            case 4: 
              putd(' ',(j*ch)+0,4);
              putd(' ',(j*ch)+1,4);
              putd(' ',(j*ch)+2,4);
              putd(' ',(j*ch)+3,4);
              putd(' ',(j*ch)+4,4);
              break;
          }
          break;
        case '5':
          switch(i){
            case 0: 
              putd(' ',(j*ch)+0,0);
              putd('-',(j*ch)+1,0);
              putd('-',(j*ch)+2,0);
              putd('-',(j*ch)+3,0);
              putd(' ',(j*ch)+4,0);
              break;
            case 1: 
              putd('|',(j*ch)+0,1);
              putd(' ',(j*ch)+1,1);
              putd(' ',(j*ch)+2,1);
              putd(' ',(j*ch)+3,1);
              putd(' ',(j*ch)+4,1);
              break;
            case 2: 
              putd(' ',(j*ch)+0,2);
              putd('-',(j*ch)+1,2);
              putd('-',(j*ch)+2,2);
              putd('-',(j*ch)+3,2);
              putd(' ',(j*ch)+4,2);
              break;
            case 3: 
              putd(' ',(j*ch)+0,3);
              putd(' ',(j*ch)+1,3);
              putd(' ',(j*ch)+2,3);
              putd(' ',(j*ch)+3,3);
              putd('|',(j*ch)+4,3);
              break;
            case 4: 
              putd(' ',(j*ch)+0,4);
              putd('-',(j*ch)+1,4);
              putd('-',(j*ch)+2,4);
              putd('-',(j*ch)+3,4);
              putd(' ',(j*ch)+4,4);
              break;
          }
          break;
        case '6':
          switch(i){
            case 0: 
              putd(' ',(j*ch)+0,0);
              putd('-',(j*ch)+1,0);
              putd('-',(j*ch)+2,0);
              putd('-',(j*ch)+3,0);
              putd(' ',(j*ch)+4,0);
              break;
            case 1: 
              putd('|',(j*ch)+0,1);
              putd(' ',(j*ch)+1,1);
              putd(' ',(j*ch)+2,1);
              putd(' ',(j*ch)+3,1);
              putd(' ',(j*ch)+4,1);
              break;
            case 2: 
              putd(' ',(j*ch)+0,2);
              putd('-',(j*ch)+1,2);
              putd('-',(j*ch)+2,2);
              putd('-',(j*ch)+3,2);
              putd(' ',(j*ch)+4,2);
              break;
            case 3: 
              putd('|',(j*ch)+0,3);
              putd(' ',(j*ch)+1,3);
              putd(' ',(j*ch)+2,3);
              putd(' ',(j*ch)+3,3);
              putd('|',(j*ch)+4,3);
              break;
            case 4: 
              putd(' ',(j*ch)+0,4);
              putd('-',(j*ch)+1,4);
              putd('-',(j*ch)+2,4);
              putd('-',(j*ch)+3,4);
              putd(' ',(j*ch)+4,4);
              break;
          }
          break;
        case '7':
          switch(i){
            case 0: 
              putd(' ',(j*ch)+0,0);
              putd('-',(j*ch)+1,0);
              putd('-',(j*ch)+2,0);
              putd('-',(j*ch)+3,0);
              putd(' ',(j*ch)+4,0);
              break;
            case 1: 
              putd(' ',(j*ch)+0,1);
              putd(' ',(j*ch)+1,1);
              putd(' ',(j*ch)+2,1);
              putd(' ',(j*ch)+3,1);
              putd('|',(j*ch)+4,1);
              break;
            case 2: 
              putd(' ',(j*ch)+0,2);
              putd(' ',(j*ch)+1,2);
              putd(' ',(j*ch)+2,2);
              putd(' ',(j*ch)+3,2);
              putd('|',(j*ch)+4,2);
              break;
            case 3: 
              putd(' ',(j*ch)+0,3);
              putd(' ',(j*ch)+1,3);
              putd(' ',(j*ch)+2,3);
              putd(' ',(j*ch)+3,3);
              putd('|',(j*ch)+4,3);
              break;
            case 4: 
              putd(' ',(j*ch)+0,4);
              putd(' ',(j*ch)+1,4);
              putd(' ',(j*ch)+2,4);
              putd(' ',(j*ch)+3,4);
              putd(' ',(j*ch)+4,4);
              break;
          }
          break;
        case '8':
          switch(i){
            case 0: 
              putd(' ',(j*ch)+0,0);
              putd('-',(j*ch)+1,0);
              putd('-',(j*ch)+2,0);
              putd('-',(j*ch)+3,0);
              putd(' ',(j*ch)+4,0);
              break;
            case 1: 
              putd('|',(j*ch)+0,1);
              putd(' ',(j*ch)+1,1);
              putd(' ',(j*ch)+2,1);
              putd(' ',(j*ch)+3,1);
              putd('|',(j*ch)+4,1);
              break;
            case 2: 
              putd(' ',(j*ch)+0,2);
              putd('-',(j*ch)+1,2);
              putd('-',(j*ch)+2,2);
              putd('-',(j*ch)+3,2);
              putd(' ',(j*ch)+4,2);
              break;
            case 3: 
              putd('|',(j*ch)+0,3);
              putd(' ',(j*ch)+1,3);
              putd(' ',(j*ch)+2,3);
              putd(' ',(j*ch)+3,3);
              putd('|',(j*ch)+4,3);
              break;
            case 4: 
              putd(' ',(j*ch)+0,4);
              putd('-',(j*ch)+1,4);
              putd('-',(j*ch)+2,4);
              putd('-',(j*ch)+3,4);
              putd(' ',(j*ch)+4,4);
              break;
          }
          break;
        case '9':
          switch(i){
            case 0: 
              putd(' ',(j*ch)+0,0);
              putd('-',(j*ch)+1,0);
              putd('-',(j*ch)+2,0);
              putd('-',(j*ch)+3,0);
              putd(' ',(j*ch)+4,0);
              break;
            case 1: 
              putd('|',(j*ch)+0,1);
              putd(' ',(j*ch)+1,1);
              putd(' ',(j*ch)+2,1);
              putd(' ',(j*ch)+3,1);
              putd('|',(j*ch)+4,1);
              break;
            case 2: 
              putd(' ',(j*ch)+0,2);
              putd('-',(j*ch)+1,2);
              putd('-',(j*ch)+2,2);
              putd('-',(j*ch)+3,2);
              putd(' ',(j*ch)+4,2);
              break;
            case 3: 
              putd(' ',(j*ch)+0,3);
              putd(' ',(j*ch)+1,3);
              putd(' ',(j*ch)+2,3);
              putd(' ',(j*ch)+3,3);
              putd('|',(j*ch)+4,3);
              break;
            case 4: 
              putd(' ',(j*ch)+0,4);
              putd('-',(j*ch)+1,4);
              putd('-',(j*ch)+2,4);
              putd('-',(j*ch)+3,4);
              putd(' ',(j*ch)+4,4);
              break;
          }
          break;
      }
    }
  }
  /* Debug code to show detailed contents of display
  for(i = 0; i < h; i++)
  for(j = 0; j < w; j++){
    char cur = getd(j,i);
    printf("display[%i] (%i,%i):\t%s%c\n", j+i*w, j, i, cur!=32?"":"<space>", cur!=32?cur:32);
    usleep(1000000/12);
  }
  printf("Calculated Width: %i\nCalculated string: \n",w);
  */
  for(i = 0; i < h; i++){
    for(j = 0; j < w; j++){
      putchar(getd(j,i));
    }
    putchar(10);
  }
  return 0;
}
