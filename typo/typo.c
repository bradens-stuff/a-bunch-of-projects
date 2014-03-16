#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void){
  srand(time(0));
  int c,d,r[3];
  #if !defined(USEFILE)
    r[2] = system("stty raw");
  #endif
  while((c = getchar())){
    if(c == 4 || c == EOF) break; // EOF is passed by file. 4 is passed by, unsurprisingly, ctrl+D
    #if !defined(USEFILE)
      printf("\033[D");
    #endif
    r[0] = rand()%10;
    r[1] = rand()%26;
    d = c + ((r[0] == 1) ? r[1] : 0);
    if(d >= '!' && d <= '~') putchar(d);
    else putchar(c);
  }
  #if !defined(USEFILE)
    r[2] = system("stty sane");
  #endif
  return 0;
}
