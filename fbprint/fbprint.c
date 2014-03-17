#include "fbprint.h"

void fbprint(char * msg, int baseY){
  int fbfd = open("/dev/fb0", O_RDWR); 
  struct fb_var_screeninfo vinfo;
  struct fb_fix_screeninfo finfo;
  long int screensize;
  char *fbp;

  ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo);
  ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo);

  screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;
  fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);

  void fillRect(int _x, int _y, int _w, int _h, int _r, int _g, int _b){
    int x, y;
    long int location;
    for (y = _y; y < _y+_h; y++)
    for (x = _x; x < _x+_w; x++) {
      location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+vinfo.yoffset) * finfo.line_length;
      fbp[location + 0] = _b;
      fbp[location + 1] = _g;
      fbp[location + 2] = _r;
      fbp[location + 3] = 0;
    }
  }
  int ptr = 0; // pointer
  int cx = 0; // char x
  while(ptr < strlen(msg)){
    switch((int)msg[ptr]){
      case ' ':
        cx++;
        break;
      case '-':
        fillRect(C(cx)+B(1),baseY+B(3),B(2),B(1),WT);
        cx++;
        break;
      case '!':
        fillRect(C(cx)+B(1),baseY+B(1),B(1),B(3),WT);
        fillRect(C(cx)+B(1),baseY+B(5),B(1),B(1),WT);
        cx++;
        break;
      case 'a':
      case 'A': 
        fillRect(C(cx)+B(1),baseY+B(1),B(1),B(5),WT);
        fillRect(C(cx)+B(3),baseY+B(1),B(1),B(5),WT);
        fillRect(C(cx)+B(1),baseY+B(3),B(3),B(1),WT);
        fillRect(C(cx)+B(1),baseY+B(1),B(3),B(1),WT);
        cx++;
        break;
      case 'b':
      case 'B':
        fillRect(C(cx)+B(1),baseY+B(1),B(1),B(5),WT);
        fillRect(C(cx)+B(3),baseY+B(1),B(1),B(5),WT);
        fillRect(C(cx)+B(1),baseY+B(1),B(3),B(1),WT);
        fillRect(C(cx)+B(1),baseY+B(3),B(3),B(1),WT);
        fillRect(C(cx)+B(1),baseY+B(5),B(3),B(1),WT);
        cx++;
        break;
      case 'c':
      case 'C':
        fillRect(C(cx)+B(1),baseY+B(1),B(1),B(5),WT);
        fillRect(C(cx)+B(1),baseY+B(1),B(3),B(1),WT);
        fillRect(C(cx)+B(1),baseY+B(5),B(3),B(1),WT);
        cx++;
        break;
      case 'd':
      case 'D':
        fillRect(C(cx)+B(1),baseY+B(1),B(1),B(5),WT);
        fillRect(C(cx)+B(3),baseY+B(2),B(1),B(3),WT);
        fillRect(C(cx)+B(1),baseY+B(1),B(2),B(1),WT);
        fillRect(C(cx)+B(1),baseY+B(5),B(2),B(1),WT);
        cx++;
        break;
      case 'e':
      case 'E':
        fillRect(C(cx)+B(1),baseY+B(1),B(1),B(5),WT);
        fillRect(C(cx)+B(1),baseY+B(1),B(3),B(1),WT);
        fillRect(C(cx)+B(1),baseY+B(3),B(3),B(1),WT);
        fillRect(C(cx)+B(1),baseY+B(5),B(3),B(1),WT);
        cx++;
        break;
      case 'f':
      case 'F':
        fillRect(C(cx)+B(1),baseY+B(1),B(1),B(5),WT);
        fillRect(C(cx)+B(1),baseY+B(1),B(3),B(1),WT);
        fillRect(C(cx)+B(1),baseY+B(3),B(3),B(1),WT);
        cx++;
        break;
      case 'g':
      case 'G':
        fillRect(C(cx)+B(1),baseY+B(1),B(1),B(5),WT);
        fillRect(C(cx)+B(1),baseY+B(1),B(3),B(1),WT);
        fillRect(C(cx)+B(1),baseY+B(5),B(3),B(1),WT);
        fillRect(C(cx)+B(3),baseY+B(3),B(1),B(2),WT);
        cx++;
        break;
      case 'h':
      case 'H':
        fillRect(C(cx)+B(1),baseY+B(1),B(1),B(5),WT);
        fillRect(C(cx)+B(3),baseY+B(1),B(1),B(5),WT);
        fillRect(C(cx)+B(1),baseY+B(3),B(3),B(1),WT);
        cx++;
        break;
      case 'i':
      case 'I':
        fillRect(C(cx)+B(2),baseY+B(1),B(1),B(5),WT);
        cx++;
        break;
      case 'j':
      case 'J':
        fillRect(C(cx)+B(3),baseY+B(1),B(1),B(5),WT);
        fillRect(C(cx)+B(1),baseY+B(5),B(3),B(1),WT);
        cx++;
        break;
      case 'k':
      case 'K':
        fillRect(C(cx)+B(1),baseY+B(1),B(1),B(5),WT);
        fillRect(C(cx)+B(2),baseY+B(3),B(1),B(1),WT);
        fillRect(C(cx)+B(3),baseY+B(1),B(1),B(2),WT);
        fillRect(C(cx)+B(3),baseY+B(4),B(1),B(2),WT);
        cx++;
        break;
      case 'l':
      case 'L':
        fillRect(C(cx)+B(1),baseY+B(1),B(1),B(5),WT);
        fillRect(C(cx)+B(1),baseY+B(5),B(3),B(1),WT);
        cx++;
        break;
      case 'm':
      case 'M':
        fillRect(C(cx)+B(1),baseY+B(1),B(1),B(5),WT);
        fillRect(C(cx)+B(3),baseY+B(1),B(1),B(5),WT);
        fillRect(C(cx)+B(2),baseY+B(2),B(1),B(1),WT);
        cx++;
        break;
      case 'n':
      case 'N':
        fillRect(C(cx)+B(1),baseY+B(1),B(1),B(5),WT);
        fillRect(C(cx)+B(3),baseY+B(1),B(1),B(5),WT);
        fillRect(C(cx)+B(2),baseY+B(1),B(1),B(1),WT);
        cx++;
        break;
      case 'o':
      case 'O':
        fillRect(C(cx)+B(1),baseY+B(1),B(1),B(5),WT);
        fillRect(C(cx)+B(3),baseY+B(1),B(1),B(5),WT);
        fillRect(C(cx)+B(1),baseY+B(1),B(3),B(1),WT);
        fillRect(C(cx)+B(1),baseY+B(5),B(3),B(1),WT);
        cx++;
        break;
      case 'p':
      case 'P':
        fillRect(C(cx)+B(1),baseY+B(1),B(1),B(5),WT);
        fillRect(C(cx)+B(1),baseY+B(1),B(3),B(1),WT);
        fillRect(C(cx)+B(1),baseY+B(3),B(3),B(1),WT);
        fillRect(C(cx)+B(3),baseY+B(1),B(1),B(3),WT);
        cx++;
        break;
      case 'q':
      case 'Q':
        fillRect(C(cx)+B(1),baseY+B(1),B(1),B(5),WT);
        fillRect(C(cx)+B(3),baseY+B(1),B(1),B(5),WT);
        fillRect(C(cx)+B(1),baseY+B(1),B(3),B(1),WT);
        fillRect(C(cx)+B(1),baseY+B(5),B(3),B(1),WT);
        fillRect(C(cx)+B(4),baseY+B(5),B(1),B(1),WT);
        cx++;
        break;
      case 'r':
      case 'R':
        fillRect(C(cx)+B(1),baseY+B(1),B(1),B(5),WT);
        fillRect(C(cx)+B(1),baseY+B(1),B(3),B(1),WT);
        fillRect(C(cx)+B(1),baseY+B(3),B(2),B(1),WT);
        fillRect(C(cx)+B(3),baseY+B(1),B(1),B(2),WT);
        fillRect(C(cx)+B(3),baseY+B(4),B(1),B(2),WT);
        cx++;
        break;
      case '5':
      case 's':
      case 'S':
        fillRect(C(cx)+B(1),baseY+B(1),B(1),B(3),WT);
        fillRect(C(cx)+B(3),baseY+B(3),B(1),B(3),WT);
        fillRect(C(cx)+B(1),baseY+B(1),B(3),B(1),WT);
        fillRect(C(cx)+B(1),baseY+B(3),B(3),B(1),WT);
        fillRect(C(cx)+B(1),baseY+B(5),B(3),B(1),WT);
        cx++;
        break;
      case 't':
      case 'T':
        fillRect(C(cx)+B(1),baseY+B(1),B(3),B(1),WT);
        fillRect(C(cx)+B(2),baseY+B(1),B(1),B(5),WT);
        cx++;
        break;
      case 'u':
      case 'U':
        fillRect(C(cx)+B(1),baseY+B(1),B(1),B(5),WT);
        fillRect(C(cx)+B(3),baseY+B(1),B(1),B(5),WT);
        fillRect(C(cx)+B(1),baseY+B(5),B(3),B(1),WT);
        cx++;
        break;
      case 'v':
      case 'V':
        fillRect(C(cx)+B(1),baseY+B(1),B(1),B(4),WT);
        fillRect(C(cx)+B(3),baseY+B(1),B(1),B(4),WT);
        fillRect(C(cx)+B(2),baseY+B(5),B(1),B(1),WT);
        cx++;
        break;
      case 'w':
      case 'W':
        fillRect(C(cx)+B(1),baseY+B(1),B(1),B(5),WT);
        fillRect(C(cx)+B(3),baseY+B(1),B(1),B(5),WT);
        fillRect(C(cx)+B(2),baseY+B(4),B(1),B(1),WT);
        cx++;
        break;
      case 'x':
      case 'X':
        fillRect(C(cx)+B(1),baseY+B(1),B(1),B(2),WT);
        fillRect(C(cx)+B(3),baseY+B(1),B(1),B(2),WT);
        fillRect(C(cx)+B(1),baseY+B(4),B(1),B(2),WT);
        fillRect(C(cx)+B(3),baseY+B(4),B(1),B(2),WT);
        fillRect(C(cx)+B(2),baseY+B(3),B(1),B(1),WT);
        cx++;
        break;
      case 'y':
      case 'Y':
        fillRect(C(cx)+B(1),baseY+B(1),B(1),B(2),WT);
        fillRect(C(cx)+B(3),baseY+B(1),B(1),B(2),WT);
        fillRect(C(cx)+B(2),baseY+B(3),B(1),B(3),WT);
        cx++;
        break;
      case 'z':
      case 'Z':
        fillRect(C(cx)+B(1),baseY+B(1),B(3),B(1),WT);
        fillRect(C(cx)+B(1),baseY+B(5),B(3),B(1),WT);
        fillRect(C(cx)+B(3),baseY+B(2),B(1),B(1),WT);
        fillRect(C(cx)+B(2),baseY+B(3),B(1),B(1),WT);
        fillRect(C(cx)+B(1),baseY+B(4),B(1),B(1),WT);
        cx++;
        break;
    }
    ptr ++;
  } 
  munmap(fbp, screensize);
  close(fbfd);
}
