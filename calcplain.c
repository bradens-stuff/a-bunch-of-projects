#include "main.h"

void calcplain(char *src){
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
    double amount = atof(src);
    char *s = malloc(3 * sizeof(char));
    while(amount > 0){
      if(amount >= 100){
        hundreds++;
        amount -= 100;
      }else if(amount >= 50){
        fifties++;
        amount -= 50;
      }else if(amount >= 20){
        twenties++;
        amount -= 20;
      }else if(amount >= 10){
        tens++;
        amount -= 10;
      }else if(amount >= 5){
        fives++;
        amount -= 5;
      }else if(amount >= 1){
        ones++;
        amount -= 1;
      }else if(amount >= 0.25){
        quarters++;
        amount -= 0.25;
      }else if(amount >= 0.10){
        dimes++;
        amount -= 0.10;
      }else if(amount >= 0.05){
        nickels++;
        amount -= 0.05;
      }else{
        pennies++;
        amount -= 0.01;
      }
    }
    if(hundreds){
      if(hundreds > 1){
        s = "s";
      }else{
        s = "";
      } 
      printf("%i hundred%s\n",hundreds,s);
    }
    if(fifties){
      if(fifties > 1){
        s = "ies";
      }else{
        s = "y";
      } 
      printf("%i fift%s\n",fifties,s);
    }
    if(twenties){
      if(twenties > 1){
        s = "ies";
      }else{
        s = "y";
      } 
      printf("%i twent%s\n",twenties,s);
    }
    if(tens){
      if(tens > 1){
        s = "s";
      }else{
        s = "";
      } 
      printf("%i ten%s\n",tens,s);
    }
    if(fives){
      if(fives > 1){
        s = "s";
      }else{
        s = "";
      } 
      printf("%i five%s\n",fives,s);
    }
    if(ones){
      if(ones > 1){
        s = "s";
      }else{
        s = "";
      } 
      printf("%i one%s\n",ones,s);
    }
    if(quarters){
      if(quarters > 1){
        s = "s";
      }else{
        s = "";
      } 
      printf("%i quarter%s\n",quarters,s);
    }
    if(dimes){
      if(dimes > 1){
        s = "s";
      }else{
        s = "";
      } 
      printf("%i dime%s\n",dimes,s);
    }
    if(nickels){
      if(nickels > 1){
        s = "s";
      }else{
        s = "";
      } 
      printf("%i nickel%s\n",nickels,s);
    }
    if(pennies){
      if(pennies > 1){
        s = "ies";
      }else{
        s = "y";
      } 
      printf("%i penn%s\n",pennies,s);
    }
}
