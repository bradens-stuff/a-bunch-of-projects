#include <stdio.h>
#include <string.h>
#define GET(b,n) ((b>>n)&1)
#define TOG(b,n) if((b>>n)&1){b -= 1<<n;}else{b += 1<<n;}
#define VERBOSE 0
#define NORUN 1
int main(int argc, char **argv){
  int i,b;
  int o = 0;
  if(argc >= 3){
    for(i = 0; i < argc; i++){
      if(!strcmp(argv[i],"-v")){
        TOG(o,VERBOSE)
      }
      if(!strcmp(argv[i],"-n")){
        TOG(o,NORUN)
      }
    }
  }
  if(argc > 1){
    FILE *in = fopen(argv[1],"r");
    char *fname = strcat(argv[1],".r13");
    FILE *out;
    if(!GET(o,NORUN))out = fopen(fname,"w");
    while((i = fgetc(in)) != EOF){
      if (i >= 0x41 && i <= 0x5A){ // range: uppercase
        b = 1;
      }else if(i >= 0x61 && i <= 0x7A){ //range: lowercase
        b = 2;
      }else{
        b = 0;
      }
      switch(b){
        case 0:
          if(GET(o,VERBOSE))printf("%c",i);
          if(!GET(o,NORUN))fprintf(out,"%c",i);
          break;
        case 1:
          i = ( ( (i - 0x41) + 13 ) % 26 ) + 0x41;
          if(GET(o,VERBOSE))printf("%c",i);
          if(!GET(o,NORUN))fprintf(out,"%c",i);
          break;
        case 2:
          i = ( ( (i - 0x61) + 13 ) % 26 ) + 0x61;
          if(GET(o,VERBOSE))printf("%c",i);
          if(!GET(o,NORUN))fprintf(out,"%c",i);
          break;
      }
    }
    fclose(in);
    if(!GET(o,NORUN))fclose(out);
  }else{
    printf("Usage: %s [file] [options]\noptions:\n  -v: verbose\n  -n: norun\n",argv[0]);
  }
  return 0;
}
