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

class Cursor{ // Gives FB ability to silence blinking cursor
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
};

class FB{
  private:
    int fbfd;
    int sx[2],sy[2], sc[3];
    long int screensize;
    char *fbp;
    Cursor cursor;
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
      if(ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo) == -1){
        perror("Error reading fixed information");
        exit(2);
      }
      if(ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo) == -1){
        perror("Error reading variable information");
        exit(3);
      }
      screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;
      fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
      if ((int)fbp == -1) {
        perror("Error: failed to map framebuffer device to memory");
        exit(4);
      }
    }
    void setRect(int x1, int y1, int x2, int y2){
      sx[0] = x1;
      sx[1] = x2;
      sy[0] = y1;
      sy[1] = y2;
    }
    void setColor(int r, int g, int b){
      sc[0] = r;
      sc[1] = g;
      sc[2] = b;
    }
    void fill(){
      int x;
      int y;
      long int location;
      for (y = sy[0]; y < sy[1]; y++)
      for (x = sx[0]; x < sx[1]; x++) {
        location = ((x+vinfo.xoffset) * 4) + ((y+vinfo.yoffset) * finfo.line_length);
        fbp[location + 0] = sc[2];
        fbp[location + 1] = sc[1];
        fbp[location + 2] = sc[0];
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
};

class Color{
  public:
    int r,g,b;
    Color(int _r, int _g, int _b){
      r = _r;
      g = _g;
      b = _b;
    }
    void set(int _r, int _g, int _b){
      r = _r;
      g = _g;
      b = _b;
    }
};

class Fscreen : public FB{
  public:
    void fillRect(int x, int y, int w, int h, Color c){
      setRect(x, y, x + w, y + h);
      setColor(c.r, c.g, c.b);
      fill();
    }
    void clearRect(int x, int y, int w, int h){
      Color c(0,0,0);
      fillRect(x,y,w,h,c);
    }
    void clearScreen(){
      clearRect(0,0,XRES,YRES);
    }
    void clear(){
      clearScreen();
    }
};
