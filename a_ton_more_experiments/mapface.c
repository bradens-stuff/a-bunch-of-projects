#include <stdio.h>
#include <stdlib.h>

#define height 40
#define width 120
#define FPS 12

#if defined(_WIN64) || defined(_WIN32)
#  define NL 0
#elif defined(__APPLE__)
#  define NL 1
#elif defined(__linux) || defined(__unix) || defined(__posix)
#  define NL 2
#else
#  define NL -1
#endif

void fill(char *map, int x, int y, int w, int h, char c){
  int i,j;
  for(i = y; i < (y+h); i++)
  for(j = x; j < (x+w); j++){
    if(j < width - 1){
      *( map + j + (i * width) ) = c;
    }
  }
}

int main(void){
  printf("%d\n",NL);
  if(NL == -1){
    printf("Error: Unknown system\n");
    return 1;
  }
  char map[width * height];  

  srand(time(0));

  { // anonymous scope
    int i,j;
    for(i = 0; i < height; i++)
    for(j = 0; j < width; j++){
      *( map + j + (i * width) ) = rand() % ('~' - ' ') + ' ';
      if(j == width - 1){
        if(NL == 0){ // Use Windows Newline
          *( map + j + (i * width) - 1 ) = 0x0d; // CR
          *( map + j + (i * width) ) = 0x0a; // LF
        }else if(NL == 1){ // Mac Newline
          *( map + j + (i * width) ) = 0x0d; // CR
        }else if(NL == 2){ // Linux Newline
          *( map + j + (i * width) ) = 0x0a; // LF
        }
      }
    }
  } // scope dies, i and j are freed from memory.
  fill(map,10,6,30,10,'#');
  fill(map,80,6,30,10,'#');
  fill(map,20,20,80,15,'#');

  fill(map,10+2,6+1,30-4,10-2,' ');
  fill(map,80+2,6+1,30-4,10-2,' ');
  fill(map,20+2,20+1,80-4,15-2,' ');
  int X = 2, Y = 2, LX, LY;
  char LC;
  while(1){
    LX = X;
    LY = Y;
    X = (X + 1) % width;
    LC = *(map + X + (Y * width));
    fill(map,X,Y,6,3,'+');
    fill(map,LX,LY,6,3,LC);
    printf("\033[2J%s",map);
    fflush(stdout);
    usleep(1000000/FPS);
  }
  return 0;
}
//CODE WORKS, FINISH WRITEUP, REPOST, NOTIFY JIM, FIX TYPOS IN PYTHOON FILE
