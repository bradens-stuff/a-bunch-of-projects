/*
* Multiple booleans per int (aka bitmasking) proof of concept by Braden Best aka B1KMusic
* 
* With bitmasking, you can store 32 boolean values in a single 32 bit uint. I'd say 32 is a lot more fair than 768 from using 24 different ints.
*/

#include <stdio.h>
#include "bitmask.h"

int main(void){
  int i;
  char * gtf(int n){
    return n ? "On" : "Off";
  }
  //set options, in this program, option 4 is the only one that is actually used. It is used to decide whether or not to toggle it.
  tog(0);
  tog(3);
  tog(5);
  tog(7);
  tog(9);
  tog(11);
  tog(14);
  tog(16);
  tog(19);
  tog(22);
  tog(31);
  loop: // In the spirit of low level, I'm using a jmp loop
    printf("\n\nOptions represented in decimal: %u\nListing:\n",settings);
    for(i = 0; i < 32; i++){
      printf("Option #%02i: %s\n",i,gtf(get(i)));
    }
  if(!get(4)){
    printf("\nToggling option 4\n");
    toggle(4);
    goto loop;
  }
  return 0;
}
