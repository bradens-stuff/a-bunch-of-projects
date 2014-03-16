#define tog(n) toggle(n)

/* The 32-bit int where bools are stored. */
unsigned int settings;

/* Returns a ^ b in integer form */
int ipow(int a, int b);

/* Grabs the nth index from settings */
int get(int n);

/* Toggles the nth index from settings */
void toggle(int n);


/* For example, a permissions tab could be represented like this
   000 000 000
   ^^^ ^^^ ^^^
   ||| ||| |||--- 0 , ox
   ||| ||| ||---- 1 , ow
   ||| ||| |----- 2 , or
   ||| |||------- 3 , gx
   ||| ||-------- 4 , gw
   ||| |--------- 5 , gr
   |||----------- 7 , ux
   ||------------ 8 , uw
   |------------- 9 , ur

You'd use get(7) to get the user execute permission, or tog(7) to toggle it

A full example is included in file permtest.c. To run it follow these steps:

1: gcc -o perms permtest.c bitmask.c -Wall -O2

2: ./perms

*/
