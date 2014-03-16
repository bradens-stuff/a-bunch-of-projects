/*
 * Sine thingy by Braden Best 2014
 *
 * At the right termheight, you will see a three-dimensional rotating cylinder
 *   That's at approx. 44 characters tall
 *
 * One configuration that works: xterm with default settings @ ~580 pixels tall (approx. 44 chars tall)
 *
 */

#include <stdio.h>
#include <math.h>

#define PI 3.14159263

int main(){
  int n = 0;
  double s = 0;
  double i;
  while(++n){
    s = sin(n);
    for(i = -PI; i < s; i+=0.05)    printf(" ");
    printf("#\n");
    fflush(stdout);
  }
  return 0;
}
