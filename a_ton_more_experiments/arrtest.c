#include <stdio.h>

int main(void){
  int l = 1024,
      h = 600,
      d = 10,
      x = -1,
      y = -1,
      z = -1;
  char buff[ l * h * d ];
  int ind(int x, int y, int z){
      return x + y*l + z*l*h;
  }
  char get(int x, int y, int z){
      return buff[ind(x,y,z)];
  }
  void set(int x, int y, int z, char val){
      buff[ind(x,y,z)] = val;
  }
  char sx[4];
  char sy[3];
  char sz[2];
  int ix,iy,iz;
  a:
    printf("x: ");
    scanf(" %s",&sx);
    printf("\ny: ");
    scanf(" %s",&sy);
    printf("\nz: ");
    scanf(" %s",&sz);
    ix = atoi(sx);
    iy = atoi(sy);
    iz = atoi(sz);
    printf("\nx:%i\ny:%i\nz:%i\ncalculated index:%i\n\n",ix,iy,iz,ind(ix,iy,iz));
  goto a;
  return 0;
}
