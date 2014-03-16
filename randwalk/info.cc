#include "screen.h"

int main(){
  fb_t fb;
  fb.init();
  printf("\
All you need to do is copy the following line to the top of the Makefile:\n\
RES=-DXRES=%i -DYRES=%i\n\n\
\
After that, further configuration is optional. Refer to README for further instruction\n",
fb.vinfo.xres, fb.vinfo.yres);
  fb.die();
  return 0;
}
