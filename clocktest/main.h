#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#define CYCLE 32

#ifdef STOPWATCH_H
void stopwatch();
#endif
#ifdef CLOCK_H
void _clock();
#endif
