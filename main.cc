#include "defs.h"
#include "snake.h"
#include <thread>
using namespace std;

int key;

void keylistener(){
  int sysrt_ = 0;
  key = 0;
  while(1){
    sysrt_ = system("stty raw");
    key = getchar();
    sysrt_ = system("stty sane");
  }
  sysrt_++;
}

int main(void){
  srand(time(0));
  Snake snake(XRES/2, YRES/2);
  thread k(keylistener);
  while(1){
    if(key){
      snake.key = key;
      key = 0;
      printf("\r\033[K\r\033[0;30;40m\r"); // clear line, carriage return, set color to black
    }
    snake.run();
    usleep(1000000/FPS);
  }
  k.join();
}
