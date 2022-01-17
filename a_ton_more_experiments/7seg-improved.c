// Slightly obfuscated 7-segment ascii art printer
// numbers only
// line = 5+1 x 5 x 10
// digit = 5 x 5
// I don't know what possessed me to do this. Needed a distraction from mpassw I guess.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MIN(a, b) \
    ( (a) < (b) ? (a) : (b) )

// +0: 7-segment for 0-9
// +70: draw offsets mod 3
// +73: segment graphics mod 3
// +76: segment graphics len mod 3
static char const *draw_data =
    "1110111001001010111011011011011101011010111101111101001011111111111011"
    "\1\5\t-||\3\1\1";

void
draw_7seg_digit(char *linebuf, char digit, int column)
{
    static char digitbuf[25];

    memset(digitbuf, ' ', 25);

    for(int segid = 0; segid < 7; ++segid){
        char const *gfxptr;

        if(*(draw_data + 7 * (digit - '0') + segid) == '0')
            continue;

        gfxptr = draw_data + 70 + segid % 3;
        memset(digitbuf + 10 * (segid/3) + gfxptr[0], gfxptr[3], gfxptr[6]);
    }

    for(int row = 0; row < 5; ++row)
        memcpy(linebuf + 60 * row + 6 * column, digitbuf + 5 * row, 5);
}

void
draw_7seg_line(char const *line, size_t len)
{
    static char linebuf[300];

    memset(linebuf, ' ', 300);

    for(int i = 0; i < len; ++i)
        draw_7seg_digit(linebuf, line[i], i);

    for(int i = 0; i < 5; ++i){
        fwrite(linebuf + 60 * i, 1, 60, stdout);
        fwrite("\n", 1, 1, stdout);
    }
}

void
draw_7seg(char const *str)
{
    size_t slen = strlen(str);
    size_t offset = 0;

    while(offset < slen){
        size_t amount = MIN(slen - offset, 10);

        draw_7seg_line(str + offset, amount);
        offset += amount;
    }
}

void
usage(void)
{
    puts("Usage: 7seg <string of numbers>");
    exit(1);
}

int
validate(char const *numstr)
{
    for(int i = 0; numstr[i] != '\0'; ++i)
        if(!isdigit(numstr[i]))
            return 0;

    return 1;
}

int
main(int argc, char **argv)
{
    if(argc < 2 || !validate(argv[1]))
        usage();

    draw_7seg(argv[1]);
    return 0;
}
