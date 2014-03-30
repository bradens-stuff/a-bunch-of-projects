#include "defs.h"
#include "screen.h"

class SnakePiece{
  public:
    int x;
    int y;
    int lastx;
    int lasty;
    int _init;
    SnakePiece(){
      x = 0;
      y = 0;
      lastx = 0;
      lasty = 0;
      _init = 1;
    };
};

class Food{
  public:
    int x;
    int y;
    int lastx;
    int lasty;
    Food(){
      x = (rand() % XRES);
      y = (rand() % YRES);
      x = x - (x % CELLSIZE);
      y = y - (y % CELLSIZE);
      lastx = x;
      lasty = y;
    }
    void init(){
      lastx = x;
      lasty = y;
      x = (rand() % XRES); 
      y = (rand() % YRES); 
      x = x - (x % CELLSIZE);
      y = y - (y % CELLSIZE);
      x = x;
      y = y;
    }
};

class Snake{
  private:
    int length, dir, x, y, lastx, lasty;
    SnakePiece pieces[ (XRES / CELLSIZE) * (YRES / CELLSIZE) ]; 
    Fscreen screen;
    Food food;
    Color fgcol;
    void up(){
      lasty = y;
      y -= CELLSIZE;
      if(y < 0){
        y = YRES - CELLSIZE;
      }
    }
    void down(){
      lasty = y;
      y += CELLSIZE;
      if (y + CELLSIZE > YRES){
        y = 0;
      }
    }
    void left(){
      lastx = x;
      x -= CELLSIZE;
      if(x < 0){
        x = XRES - CELLSIZE;
      }
    }
    void right(){
      lastx = x;
      x += CELLSIZE;
      if (x + CELLSIZE > XRES){
        x = 0;
      }
    }
    void push(int x, int y){ // pushes data into end of array
      SnakePiece temp;
      temp.x = x;
      temp.y = y;
      pieces[length] = temp;
      length ++;
    }
    SnakePiece pop(){ // "removes" element from end of array and returns it
      SnakePiece temp = pieces[length-1];
      length--;
      return temp;
    }
    void unshift(SnakePiece piece){ // the reverse equivalent of push
      int i = length;
      while(i-->0){
        pieces[i+1] = pieces[i];
      }
      pieces[0] = piece;
      length++;
    }
    void move(){
      SnakePiece tail = pop(); 
      if(dir == 0){
        up();
      }else if(dir == 1){
        right();
      }else if(dir == 2){
        down();
      }else if(dir == 3){
        left();
      }
      tail.lastx = tail.x;
      tail.lasty = tail.y;
      tail.x = x;
      tail.y = y;
      tail._init = 0;
      unshift(tail);
    }
    void keyboard(){
      int sysrt_ = 0;
      if(key){
        switch(key){
          case 'w':
          case 'A': // up
            dir = (dir != 2) ? 0 : 2;
            break;
          case 'd':
          case 'C': // right
            dir = (dir != 3) ? 1 : 3;
            break;
          case 's':
          case 'B': // down
            dir = (dir != 0) ? 2 : 0;
            break;
          case 'a':
          case 'D': // left
            dir = (dir != 1) ? 3 : 1;
            break;
          case 'q': // quit
            screen.die();
            sysrt_ = system("reset");
            sysrt_++;
            exit(0);
            break;
          case 'x':
            push(0,0);
            break;
          default:
            break;
        }
        key = 0;
      }
    }
    void collision(){
      int i;
      //with self
      for(i = 1; i < length; i++){
        if(pieces[0].x == pieces[i].x && pieces[0].y == pieces[i].y){
          screen.die();
          i = system("reset");
          printf("\033[0;37;40m\rGame Over\nScore: %i\n", score);
          exit(0);
        }
      }
      //with Food
      if(pieces[0].x == food.x && pieces[0].y == food.y){
        score++;
        push(0,0);
        food.init();
      }
    }
    void render(){
      int i, j;
      Color red(255,0,0);
      for(i = 0; i < length; i++){
        if(!pieces[i]._init){ // don't render if this is the piece's first run
          for(j = 0; j < length; j++){
            if(j != i && (pieces[i].lastx == pieces[j].x && pieces[i].lasty == pieces[j].y)){
              break;
            }else{
              screen.clearRect(pieces[i].lastx,pieces[i].lasty,CELLSIZE,CELLSIZE);
            }
          }
          screen.fillRect(pieces[i].x,pieces[i].y,CELLSIZE-MARGIN,CELLSIZE-MARGIN,fgcol);
        }
      }
      screen.clearRect(food.lastx,food.lasty,CELLSIZE, CELLSIZE);
      screen.fillRect(food.x,food.y,CELLSIZE-MARGIN, CELLSIZE-MARGIN,fgcol);
    }
  public:
    int key = 0;
    int score = 0;
    Snake(int _x, int _y) : fgcol(_R,_G,_B){
      int i, sysrt_;
      x = _x;
      y = _y;
      dir = rand()%4;
      length = 0;
      push(XRES / 2, YRES / 2); // head
      for(i = 1; i < DEFAULT_LENGTH; i++){
        push(0,0);
      }
      screen.clearRect(0,0,XRES,YRES);
      sysrt_ = system("reset");
      sysrt_ += 1;
    }
    void run(){
      move();
      keyboard();
      collision();
      render();
    }
};
