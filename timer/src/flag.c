#include "flag.h"

int getflag(int flags, int n){
  return flags >> n & 1;
}

void setflag(int *flags, int n){
  if(!(*(flags) >> n & 1)){
    *(flags) += 1 << n;
  }
}
