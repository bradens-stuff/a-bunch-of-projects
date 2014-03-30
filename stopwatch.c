#include "main.h"
#ifdef STOPWATCH_H
#define DELAY 300 // This depends on hardware. The slower the CPU, the higer this number. Adjust as necessary.
void stopwatch(){
  int ms = 0,
      s = 0,
      m = 0,
      h = 0;
  while(1){
    ms ++;
    if(ms > 999){
      s ++;
      ms = 0;
    }
    if(s > 59){
      m ++;
      s = 0;
    }
    if(m > 59){
      h ++;
      m = 0;
    }
    printf("%02d:%02d:%02d.%03d\r",h,m,s,ms);
    fflush(stdout);
    usleep(1000-DELAY);
  }
}
#endif
