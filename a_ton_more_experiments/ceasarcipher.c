#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define DEFAULT_ROT 1

void encode(char *str, int rot){
  int i;
  int len = strlen(str);
  char c;
  for(i = 0; i < len; i++){
    c = str[i];
    if(c >= 'a' && c <= 'z'){
      c -= 'a'; // Removing the "offset" so that a = 0, b = 1, c = 2 ... z = 25
      c = (c + rot) % 26;
      c += 'a'; 
    }else if(c >= 'A' && c <= 'Z'){
      c -= 'A';
      c = (c + rot) % 26;
      c += 'A';
    }
    putchar(c);
  }
}

void decode(char *str, int rot){
  encode(str, 26 - rot); // In a Ceasar Cipher, decoding is just encoding using the difference of 26 and the encoding key. No need to program new logic
}

void brute(char *str){
  int i;
  for(i = 1; i <= 26; i++){
    printf("%02i:\t", i);
    decode(str,i);
    printf("\n");
  }
}

int main(int argc, char **argv){
  opterr = 0;
  int c;
  int rot = DEFAULT_ROT;
  int flags = 0; 
  char str[10000];
  while((c = getopt(argc,argv,"b:e:d:r:")) != -1){
    switch(c){
      case 'e':
        strcpy(str, optarg);
        flags += 1 << 0;
        break;
      case 'd':
        strcpy(str, optarg);
        flags += 1 << 1;
        break;
      case 'r':
        rot = atoi(optarg);
        flags += 1 << 2;
        break;
      case 'b':
        strcpy(str, optarg);
        flags += 1 << 3;
        break;
    }
  }
 
  if(flags & 1 && (flags >> 1) & 1){
    printf("Error: both -e and -d flags are set\n");
    flags = 0;
  }
  if((flags >> 1) & 1){ // decode flag is set
    decode(str,rot);
  }
  if((flags >> 0) & 1){ // encode flag is set
    encode(str,rot);
  }
  if((flags >> 3) & 1){ // brute force flag is set
    brute(str);
  }

  if(!flags)
    printf("\
Usage: %s [options]\n\
options:\n\
  -b [string]:\tbrute force string (tries all 26 possible rot values to decode it)\n\
  -e [string]:\tencode string\n\
  -d [string]:\tdecode string\n\
  -r [number]:\trotation factor (e.g. -r 13 generates rot13)\n",argv[0]);
  return 0;
}
