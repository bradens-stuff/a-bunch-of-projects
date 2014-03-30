# Snake Game

This is a horrifically buggy snake game I wrote. Uses linux framebuffer for graphics

Quick instructions:
-
    $ ./configure && make && ./snake


To configure:
-
    $ ./configure

To compile without installing:
-
    $ make

To compile and install:
-
    $ make install

To uninstall:
-
    $ make uninstall

Other info:
-
Where's the Keyboard control in the code?
-
Unfortunately, multithreading doesn't seem to play nice with classes, so I had to implement it raw. It is found in `main.cc`

How does the keyboard control work?
-
I tried many different solutions before I put it down for a week.

I ultimately settled for multithreading, and deleted the `keyboard.h` file, since there was no way I could figure out how to separate it from main. Multithreading is not something I am familiar with.

The way it works is relatively simple. It just uses `getchar()` in a separate thread, with the shell mode set to raw (so you don't have to press `<enter>`). It then sets a global variable, and `main()` listens to key before running the snake`s main logic. 

If key suddenly becomes non-zero, then `main()` sets the snake`s key, and sets the global key back to zero. Snake will then notice the same thing happen in its logic, and act accordingly.

This approach is very buggy, and is the main reason, aside from editing the `cursor_blink` file, that this is liable to Segfault.
