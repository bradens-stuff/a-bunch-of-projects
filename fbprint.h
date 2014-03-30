#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#ifndef CELLSIZE
  #define CELLSIZE 12
#endif
#define B(n) (n * CELLSIZE) // Block
#define C(n) (n * B(4)) // Char
#define R(n) (n * B(6)) // Row
#define WT 0xdd,0xdd,0xff
void fbprint(char *msg, int baseY);
