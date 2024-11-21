Here i have mentioned the major use of ncurses and basic thinngs that is to be used 
for making the project with ncurses
how to compile the project with ncurses
```cmd
 gcc trail.c -std=c99 -lncur
ses -o trail
./trail
```
Some functions and their uses in ncurses.
1. Printing in window
```cmd
addstr - prints the specified string
addch - prints a single char
printw - the ncurses equivalent of printf
```
2. To copy from the buffer to the screen.
```cmd
refresh():
```
3. Moving and sleeping function
4. To hide the cursor
```cmd
curs_set(0);
```
5. Nap before every event  in milliseconds
 ```cmd
napms (100);   
   ```
6. Move
   ```cmd
   move(row,column);
   ```
7. Move and add character
```cmd
mvaddch(row,column,ch);
```
8. has_colors(): bool to check if the terminal support the colors
9. start_color():to start the color
   how to add the color to the content
```cmd
            init_pair(1, COLOR_YELLOW, COLOR_RED);
            init_pair(2, COLOR_GREEN, COLOR_GREEN);
            init_pair(3, COLOR_MAGENTA, COLOR_CYAN);

            attrset(COLOR_PAIR(1));
            addstr("Yellow and red\n\n");
            refresh();
            attroff(COLOR_PAIR(1));
```
10. keypad(stdscr, TRUE): To take input from the keyboard.
11. WINDOW * win = newwin(nlines, ncols, y0, x0):
    where nlines is the height of the window
    and ncols is the width of the window
    y0 and x0 are the coordinates of the upper left corner of
    win on the screen 
    work-To create a window

Special keys. If you have called keypad(stdstr, TRUE), then if the user hits a special key such as the Delete key, the arrow keys, Ctrl combined keys and function keys, a single int value will be returned. Here is the definition of several special keys


           key code        description

           KEY_DOWN        The four arrow keys ...
           KEY_UP
           KEY_LEFT
           KEY_RIGHT
           KEY_HOME        Home key 
           KEY_BACKSPACE   Backspace
           KEY_F(n)        Function keys, for 0 <= n >= 63
           KEY_DC          Delete character
           KEY_IC          Insert char or enter insert mode
           KEY_ENTER       Enter or send
For a complete list read the man page of getch().
Read character from a window. The function int wgetch(WINDOW *win). reads a key from a window. The user input of course comes from the keyboard and not the screen window. But the different windows on the screen might have different delay modes and other properties, therefore affect the behavior of wgetch().
Moving the cursor and read a character. There are also functions which combine cursor moving and character reading together


       int mvgetch(int y, int x);
       int mvwgetch(WINDOW *win, int y, int x);

https://www.codedrome.com/an-introduction-to-ncurses-in-c/
http://jbwyatt.com/ncurses.html#init
