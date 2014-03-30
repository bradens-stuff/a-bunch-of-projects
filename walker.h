#include "defs.h"
#include "screen.h"

typedef class Color{
  public:
    short int r,g,b;
    void set(short int rvalue, short int gvalue = 0, short int bvalue = 0){
      if(gvalue){
        r = rvalue;
        g = gvalue;
        b = bvalue;
      }else{
        r = rvalue;
        g = rvalue;
        b = rvalue;
      }
    }
} color_t;

typedef class FBE : public FB{
  public:
    void fillRect2(int _x, int _y, int _w, int _h, color_t color){
      fillRect(_x,_y,_w,_h,color.r,color.g,color.b); 
    }
} fbe_t;

typedef class Walker{
  private:
    int x,y,dir;
    fbe_t fb;
    color_t cl;
    void up(){
      y -= CELLSIZE;
      if (y < 0) y = YRES - CELLSIZE;
    }
    void down(){
      y += CELLSIZE;
      if (y + CELLSIZE > YRES) y = 0;
    }
    void left(){
      x -= CELLSIZE;
      if (x < 0) x = XRES - CELLSIZE;
    }
    void right(){
      x += CELLSIZE;
      if (x + CELLSIZE > XRES) x = 0;
    }
  public:
    Walker(int _x, int _y){
      x = _x; 
      y = _y;
      dir = rand() % 4;
      fb.fillRect(0,0,XRES,YRES,0xff,0xff,0xff);
      fb.fillRect(1,1,XRES-2,YRES-2,0,0,0);
    }
    void run(){
      int _dir = dir;
      while(_dir == dir || (_dir + 2) % 4 == dir){
        _dir = rand()%4;
      }
      dir = _dir;
      if(dir == 0){
        up();
      }
      if(dir == 1){
        right();
      }
      if(dir == 2){
        down();
      }
      if(dir == 3){
        left();
      }
      cl.set(rand()%0xFF,rand()%0xFF,rand()%0xFF);
      //cl.set(rand()%0xFF);
      fb.fillRect2(x,y,CELLSIZE-MARGIN,CELLSIZE-MARGIN,cl);
    }
    void exit(){
      delete this;
    }
    ~Walker(){
      fb.die();
      system("reset");
    }
} walker_t;

