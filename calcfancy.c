#include "main.h"
#define DBG printf("amounti: %i\namountf: %f\n",amounti,amountf);
void calcfancy(char *src){
    unsigned int ones = 0,
                 fives = 0,
                 tens = 0,
                 twenties = 0,
                 fifties = 0,
                 hundreds = 0,
                 quarters = 0,
                 dimes = 0,
                 nickels = 0,
                 pennies = 0;
    //break decimal value into individual counterparts amounti (e.g. 5 in 5.21) and amountf (e.g. 21 in 5.21)
    int amounti = atoi(src);
    double amountf =(atof(src) - amounti)*100; // double precision in order to get an accurate
    while(amounti > 0){
      if(amounti >= 100){
        hundreds++;
        amounti -= 100;
      }else if(amounti >= 50){
        fifties++;
        amounti -= 50;
      }else if(amounti >= 20){
        twenties++;
        amounti -= 20;
      }else if(amounti >= 10){
        tens++;
        amounti -= 10;
      }else if(amounti >= 5){
        fives++;
        amounti -= 5;
      }else if(amounti >= 1){
        ones++;
        amounti -= 1;
      }else{
        ones++;
        amounti --;
      }
    }
    while(amountf > 0){
      if(amountf >= 25){
        quarters++;
        amountf -= 25;
      }else if(amountf >= 10){
        dimes++;
        amountf -= 10;
      }else if(amountf >= 5){
        nickels++;
        amountf -= 5;
      }else if(amountf >= 1){
        pennies++;
        amountf -= 1;
      }else{
        pennies++;
        amountf --;
      }
    }
    while(hundreds){
      printf("[100 (._.) 100]\n");
      hundreds --;
    }
    while(fifties){
      printf("[ 50 (._.) 50 ]\n");
      fifties --;
    } 
    while(twenties){
      printf("[ 20 (._.) 20 ]\n");
      twenties --;
    } 
    while(tens){
      printf("[ 10 (._.) 10 ]\n");
      tens --;
    } 
    while(fives){
      printf("[  5 (._.) 5  ]\n");
      fives --;
    } 
    while(ones){
      printf("[  1 (._.) 1  ]\n");
      ones --;
    } 
    while(quarters){
      printf("Q ");
      quarters --;
    } 
    printf("\n");
    while(dimes){
      printf("D ");
      dimes --;
    } 
    printf("\n");
    while(nickels){
      printf("N ");
      nickels --;
    } 
    printf("\n");
    while(pennies){
      printf("P ");
      pennies --;
    } 
    printf("\n");

}
