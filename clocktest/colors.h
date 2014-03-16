//Control
#define RESET 0
#define BRIGHT 1
#define DIM 2
#define UNDERLINE 3
#define BLINK 4
#define REVERSE 7
#define HIDDEN 8
//Colors
#define BLACK 0
#define RED 1
#define GREEN 2
#define YELLOW 3
#define BLUE 4
#define MAGENTA 5
#define CYAN 6
#define WHITE 7
//Abstraction
#define color(mod,fg,bg) printf("\033[%d;%d;%dm", mod, fg + 30, bg + 40)
#define reset() color(RESET,WHITE,BLACK); printf("\n");
