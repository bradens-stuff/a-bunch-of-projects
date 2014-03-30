#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

#ifndef XRES
#  define XRES 100
#endif
#ifndef YRES
#  define YRES 100
#endif

typedef class Cursor{
  public:
    void start(){
      FILE *f = fopen("/sys/class/graphics/fbcon/cursor_blink","w");
      fprintf(f,"1");
      fclose(f);
    }
    void stop(){
      FILE *f = fopen("/sys/class/graphics/fbcon/cursor_blink","w");
      fprintf(f,"0");
      fclose(f);
    }
} cursor_t;

typedef class FB{
  private:
    int fbfd;
    long int screensize;
    char *fbp;
    cursor_t cursor;
  public:
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
    FB(){
      cursor.stop();
      fbfd = open("/dev/fb0", O_RDWR);
      if(fbfd == -1){
        perror("Error: cannot open framebuffer device");
        exit(1);
      }
      ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo);
      ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo);
      if(vinfo.bits_per_pixel != 32){
        perror("Error: Color-mode not 32-bit.");
        exit(2);
      }
      screensize = vinfo.xres * vinfo.yres * 4;
      fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
      if ((int)fbp == -1) {
        perror("Error: failed to map framebuffer device to memory");
        exit(3);
      }
    }
  
    void fillRect(int _x, int _y, int _w, int _h, int _r, int _g, int _b){
      int x;
      int y;
      long int location;
      for (y = _y; y < _y+_h; y++)
      for (x = _x; x < _x+_w; x++) {
        location = 4 * (x + y * vinfo.xres);
        fbp[location + 0] = _b;
        fbp[location + 1] = _g;
        fbp[location + 2] = _r;
        fbp[location + 3] = 0;
      }
    }
  
    void die(){
      delete this;
    }
    ~FB(){
      munmap(fbp, screensize);
      close(fbfd);
      cursor.start();
    }
} fb_t;
