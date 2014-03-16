#include <string>

enum{Get = -1, Unset = 0, Set = 1};

class Bool32{
  private:
    unsigned int b;
  public:
    Bool32(){
      b = 0;
    }
    int get(int n){
      if(n >= 0 && n < 32){
        return (b >> n) & 1;
      }else{
        return 0;
      }
    }
    int set(int n){
      if(n >= 0 && n < 32 && !get(n)){
        b += (1 << n);
      }
    }
    int unset(int n){
      if(n >= 0 && n < 32 && get(n)){
        b -= (1 << n);
      }
    }
    int operator()(int n, int op = Get){
      if(op == Get)      return get(n);
      if(op == Unset)    unset(n);
      if(op == Set)      set(n);
      return -1; // error
    }
    int operator[](int n){
      return get(n);
    }
};

class Bool256{
  private:
    unsigned int b[8];
  public:
    Bool256(){
      int i = 0;
      while(b[i++] = 0,i < 8);
    }
    int get(int n){
      if(n >= 0){
        if     (n < 32 * 1)    return (b[0] >> (n % 32)) & 1;
        else if(n < 32 * 2)    return (b[1] >> (n % 32)) & 1;
        else if(n < 32 * 3)    return (b[2] >> (n % 32)) & 1;
        else if(n < 32 * 4)    return (b[3] >> (n % 32)) & 1;
        else if(n < 32 * 5)    return (b[4] >> (n % 32)) & 1;
        else if(n < 32 * 6)    return (b[5] >> (n % 32)) & 1;
        else if(n < 32 * 7)    return (b[6] >> (n % 32)) & 1;
        else if(n < 32 * 8)    return (b[7] >> (n % 32)) & 1;
        else                   return 0;
      }else{
        return 0;
      }
    }
    void set(int n){
      if(n >= 0 && !get(n)){
        if     (n < 32 * 1)    b[0] += 1 << (n % 32);
        else if(n < 32 * 2)    b[1] += 1 << (n % 32);
        else if(n < 32 * 3)    b[2] += 1 << (n % 32);
        else if(n < 32 * 4)    b[3] += 1 << (n % 32);
        else if(n < 32 * 5)    b[4] += 1 << (n % 32);
        else if(n < 32 * 6)    b[5] += 1 << (n % 32);
        else if(n < 32 * 7)    b[6] += 1 << (n % 32);
        else if(n < 32 * 8)    b[7] += 1 << (n % 32);
      }
    }
    void unset(int n){
      if(n >= 0 && get(n)){
        if     (n < 32 * 1)    b[0] -= 1 << (n % 32);
        else if(n < 32 * 2)    b[1] -= 1 << (n % 32);
        else if(n < 32 * 3)    b[2] -= 1 << (n % 32);
        else if(n < 32 * 4)    b[3] -= 1 << (n % 32);
        else if(n < 32 * 5)    b[4] -= 1 << (n % 32);
        else if(n < 32 * 6)    b[5] -= 1 << (n % 32);
        else if(n < 32 * 7)    b[6] -= 1 << (n % 32);
        else if(n < 32 * 8)    b[7] -= 1 << (n % 32);
      }
    }
    int operator()(int n, int op = Get){
      if(op == Get)      return get(n);
      if(op == Unset)    unset(n);
      if(op == Set)      set(n);
      return -1; // error
    }
    int operator[](int n){
      return get(n);
    }
};

class Bool512{
  private:
    unsigned int b[16];
  public:
    Bool512(){
      int i = 0;
      while(b[i++] = 0,i < 16);
    }
    int get(int n){
      if(n >= 0){
        if     (n < 32 * 1)     return (b[0] >> (n % 32)) & 1;
        else if(n < 32 * 2)     return (b[1] >> (n % 32)) & 1;
        else if(n < 32 * 3)     return (b[2] >> (n % 32)) & 1;
        else if(n < 32 * 4)     return (b[3] >> (n % 32)) & 1;
        else if(n < 32 * 5)     return (b[4] >> (n % 32)) & 1;
        else if(n < 32 * 6)     return (b[5] >> (n % 32)) & 1;
        else if(n < 32 * 7)     return (b[6] >> (n % 32)) & 1;
        else if(n < 32 * 8)     return (b[7] >> (n % 32)) & 1;
        else if(n < 32 * 9)     return (b[8] >> (n % 32)) & 1;
        else if(n < 32 * 10)    return (b[9] >> (n % 32)) & 1;
        else if(n < 32 * 11)    return (b[10] >> (n % 32)) & 1;
        else if(n < 32 * 12)    return (b[11] >> (n % 32)) & 1;
        else if(n < 32 * 13)    return (b[12] >> (n % 32)) & 1;
        else if(n < 32 * 14)    return (b[13] >> (n % 32)) & 1;
        else if(n < 32 * 15)    return (b[14] >> (n % 32)) & 1;
        else if(n < 32 * 16)    return (b[15] >> (n % 32)) & 1;
        else                    return 0;
      }else{
        return 0;
      }
    }
    void set(int n){
      if(n >= 0 && !get(n)){
        if     (n < 32 * 1)      b[0] += 1 << (n % 32);
        else if(n < 32 * 2)      b[1] += 1 << (n % 32);
        else if(n < 32 * 3)      b[2] += 1 << (n % 32);
        else if(n < 32 * 4)      b[3] += 1 << (n % 32);
        else if(n < 32 * 5)      b[4] += 1 << (n % 32);
        else if(n < 32 * 6)      b[5] += 1 << (n % 32);
        else if(n < 32 * 7)      b[6] += 1 << (n % 32);
        else if(n < 32 * 8)      b[7] += 1 << (n % 32);
        else if(n < 32 * 9)      b[8] += 1 << (n % 32);
        else if(n < 32 * 10)     b[9] += 1 << (n % 32);
        else if(n < 32 * 11)    b[10] += 1 << (n % 32);
        else if(n < 32 * 12)    b[11] += 1 << (n % 32);
        else if(n < 32 * 13)    b[12] += 1 << (n % 32);
        else if(n < 32 * 14)    b[13] += 1 << (n % 32);
        else if(n < 32 * 15)    b[14] += 1 << (n % 32);
        else if(n < 32 * 16)    b[15] += 1 << (n % 32);
      }
    }
    void unset(int n){
      if(n >= 0 && get(n)){
        if     (n < 32 * 1)      b[0] -= 1 << (n % 32);
        else if(n < 32 * 2)      b[1] -= 1 << (n % 32);
        else if(n < 32 * 3)      b[2] -= 1 << (n % 32);
        else if(n < 32 * 4)      b[3] -= 1 << (n % 32);
        else if(n < 32 * 5)      b[4] -= 1 << (n % 32);
        else if(n < 32 * 6)      b[5] -= 1 << (n % 32);
        else if(n < 32 * 7)      b[6] -= 1 << (n % 32);
        else if(n < 32 * 8)      b[7] -= 1 << (n % 32);
        else if(n < 32 * 9)      b[8] -= 1 << (n % 32);
        else if(n < 32 * 10)     b[9] -= 1 << (n % 32);
        else if(n < 32 * 11)    b[10] -= 1 << (n % 32);
        else if(n < 32 * 12)    b[11] -= 1 << (n % 32);
        else if(n < 32 * 13)    b[12] -= 1 << (n % 32);
        else if(n < 32 * 14)    b[13] -= 1 << (n % 32);
        else if(n < 32 * 15)    b[14] -= 1 << (n % 32);
        else if(n < 32 * 16)    b[15] -= 1 << (n % 32);
      }
    }
    int operator()(int n, int op = Get){
      if(op == Get)      return get(n);
      if(op == Unset)    unset(n);
      if(op == Set)      set(n);
      return -1; // error
    }
    int operator[](int n){
      return get(n);
    }
};
