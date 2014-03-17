#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "flag.h"
#include "timer.h"

void timer(int argc, char **argv){
  int seconds = 0;
  int flags = 0;
  /*
   * flag 0: verbose flag
   * flag 1: indicates that seconds were set via options
   */
  if(argc > 1){
    int c;
    while((c = getopt(argc,argv,"vs:m:h:")) != -1){
      if(c == 'v'){
        setflag(&flags,0);
      }
      if(c == 's'){
        seconds += atoi(optarg);
        setflag(&flags,1);
      }
      if(c == 'm'){
        seconds += 60 * atoi(optarg);
        setflag(&flags,1);
      }
      if(c == 'h'){
        seconds += 3600 * atoi(optarg);
        setflag(&flags,1);
      }
    }
    if(!getflag(flags,1)){
      seconds = atoi(argv[optind]);
    }
  }else{
    seconds = DEFAULT_SECONDS;
  }
  if(getflag(flags,0)){
    printf("\r\033[K");
    while(seconds > 0){
      printf("\r\033[K%i",seconds--);
      fflush(stdout);
      usleep(1000000);
    }
  }else{
    usleep(seconds * 1000000);
  }
  printf("\rTIME IS UP\n");
}
