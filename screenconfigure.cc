#include <iostream>
#include <string>
#include "defs.h"
#include "screen.h"
using namespace std;

int main(){
  FB fb;
  int xres = fb.vinfo.xres - (fb.vinfo.xres % CELLSIZE);
  int yres = fb.vinfo.yres - (fb.vinfo.yres % CELLSIZE);
  if(xres == XRES && yres == YRES){
    cout << "Nothing needs to be done.\n";
  }else{
    string cmd; 
    cmd = "RES=-DXRES=" + to_string(xres) + " -DYRES=" +
      to_string(yres);
    cout << "Resolution is not optimal.\n";
    cout << "Fixing\n";
    cmd = "echo '" + cmd + "' > Makefile.tmp";
    system(cmd.c_str());
    system("cat Makefile >> Makefile.tmp");
    system("mv Makefile.tmp Makefile");
  }
  return 0;
}
