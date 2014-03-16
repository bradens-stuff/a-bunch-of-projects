#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/ioctl.h>

#ifndef FPS 
#  define FPS 60
#endif
  
class CharRenderer{
  private:
  int width;
  int height;
  char *map;
  public:
  char get(int x, int y){
    return *( map + x + y * width );
  }
  void set(int x, int y, char c){
    if(x < width - 1){
      *( map + x + (y * width) ) = c;
    }else if(x == width - 1){
      *( map + x + (y * width) ) = 0x0a;
    }
  }
  void fill(int x, int y, int w, int h, char c){
    int i,j;
    for(i = y; i < (y+h); i++)
    for(j = x; j < (x+w); j++){
      set(j,i,c);
    }
  }
  CharRenderer(char c = 0){
    struct winsize w;
    ioctl(0,TIOCGWINSZ,&w);
    width = w.ws_col;
    height = w.ws_row;
    map = (char *)malloc(width * height * sizeof(char));
    int i,j;
    for(i = 0; i < height; i++)
    for(j = 0; j < width; j++){
      if(!c){
        set(j,i,rand() % ('~' - ' ') + ' ');
      }else{
        set(j,i,c);
      }
    }
  }
  char *operator[](int x){
    return map;
  }
};

int main(void){
  srand(time(0));
  CharRenderer map(0);

  map.fill(10,6,30,10,'#');
  map.fill(80,6,30,10,'#');
  map.fill(20,20,80,15,'#');

  map.fill(10+2,6+1,30-4,10-2,' ');
  map.fill(80+2,6+1,30-4,10-2,' ');
  map.fill(20+2,20+1,80-4,15-2,' ');

  while(1){
    printf("%s",map[0]);
    fflush(stdout);
    usleep(1000000/FPS);
  }
  return 0;
}
