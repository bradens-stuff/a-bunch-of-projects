#include "walker.h"
#include <stdio.h>
#include <thread>
int key;

void keylistener(){
  while(1){
    system("stty raw");
    key = getchar();
    printf("\r\033[0;30;40m\033[K\r");
    system("stty sane");
  }
}

int main(void){
  key = 0;
  std::thread k(keylistener);
  srand(time(0)); // seed random
  Walker walker(XRES / 2, YRES / 2);
  while(1){
    if(key){
      if(key == 'q'){
        walker.exit();
      }
      key = 0;
    }
    walker.run();
    usleep(1000000/FPS);
  }
  k.join();
}
