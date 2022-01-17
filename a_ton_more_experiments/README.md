# A ton more experiments

This is the rest of the experiments/projects. 

7seg
-
Usage:

    $ ./7seg [numbers]

Renders numbers like a 7-segment display (digital clocks)

7seg-improved
-
Usage:

    $ ./7seg-improved [numbers]
    
Same as 7seg but with improved functionality

arrtest
-
Usage:

    $ ./arrtest

Calculates the index in memory in a 3-dimensional array where a value at x.y.z would sit

huge_bools
-
Usage:

    $ ./huge_bools

Expands on the idea of multiple boolean values in one integer by using multiple 32-bit integers to store 512 bools in a single compact structure. **Kinda redundant since C structs have bitfields**

calc
-
Usage:

    $ ./calc

A crappy calculator that barely works

cal
-
Usage:

    $ ./cal

A cheap clone of GNU's `cal`

ceasarcipher
-
Usage:

    $ ./ceasarcipher [options]

options:

    -e [string]:  encode string
    -d [string]:  decode string
    -r [number]:  rotation factor (e.g. -r 13 generates rot13)

This is a more focused project.

char_renderer
-
Usage:

    $ ./char_renderer

A weird buggy graphical renderer I wrote that uses a char * array as the graphics output

chartest
-
Usage:

    $ ./chartest

creates a map (`char *`), and prints random alternations of "#" and " " to create a thing. Indexing is done via `*(map + x + (y * width))`

collatz
-
Usage:

    $ ./collatz [number]

This is based on an idea introduced by an [xkcd comic](https://xkcd.com/710/), reading that comic will pretty much explain what's going on under the hood. But basically, it will use those rules to reduce **any** number to 1

cycle
-
Usage:

    $ ./cycle

I can't even find words to describe this one. Just run it and see what it does

mapface
-
Usage:

    $ ./mapface

Renders a crude "face" out of a charmap

reverse
-
Usage:

    $ ./reverse [text]

Reverses text
reverse_file
-
Usage:

    $ ./reverse_file < [file]

Same thing, but with a file as input

sin
-
Usage:

    $ ./sin

Renders a vertical sine wave

str2num
-
Usage:

    $ ./str2num [number]

Basically a clone of `atoi()` from `<stdlib.h>`
