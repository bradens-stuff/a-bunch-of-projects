/*
Bitmask test suite by Braden Best
This file is made to test the bitmask functions
*/
#include <stdio.h>
#include "bitmask.h"

int main(){
  printf("Welcome to the bitmask test suite.\n");
  settings = 486;
  printf("Testing ipow()\n");
  int i;
  for(i = 0; i < 5; i ++) printf("2 ^ %u = %u\n",i,ipow(2,i));
  printf("Testing get() (settings = decimal %u, hexadecimal %x)\n",settings,settings);
  for(i = 0; i < 32; i ++) printf("bit %u: %s\n",i,get(i) ? "on" : "off");
  printf("Testing toggle()\n");
  printf("toggling bit 4\n");
  printf("Before:\n  bit 4: %s\n  bitmask: ",get(4) ? "on" : "off");
  for(i = 31; i >= 0; i --) printf("%u",(settings>>i)&1);
  printf("\n  decimal: %u\n  hexadecimal: %x\n",settings,settings);
  tog(4);
  printf("After:\n  bit 4: %s\n  bitmask: ",get(4) ? "on" : "off");
  for(i = 31; i >= 0; i --) printf("%u",(settings>>i)&1);
  printf("\n  decimal: %u\n  hexadecimal: %x\n",settings,settings);
  return 0;
}
