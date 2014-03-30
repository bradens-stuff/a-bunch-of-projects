#include "main.h"
#ifdef CLOCK_H
void _clock(){
  time_t rawtime;
  struct tm* time_;
  while(1){
    time(&rawtime);
    time_ = localtime(&rawtime);
    printf("\r%i:%02i:%02i", time_->tm_hour, time_->tm_min, time_->tm_sec);
    fflush(stdout);
    usleep(1000000 / 60);
  }
}
#endif
