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
https://www.codedrome.com/an-introduction-to-ncurses-in-c/
