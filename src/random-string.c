#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char *gen_str(int len){
  int i;
  char *ret = calloc(sizeof(char), len+1);
  for(i = 0; i < len; i++)
    ret[i] = rand()%2 ? rand()%26 + (rand()%2 ? 'a' : 'A') : (rand()%10 + '0');
  ret[i] = 0;
  return ret;
}

int main(int argc, char **argv){
  srand(time(0));
  char *str;

  if(argc > 1)
    str = gen_str(atoi(argv[1]));
  else
    str = gen_str(50);

  printf("%s\n", str);
  return 0;
}
