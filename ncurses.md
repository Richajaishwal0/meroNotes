# NCURSES: Overview and Usage

## Compilation
To compile a project with ncurses, use the following command:
```bash
gcc trail.c -std=c99 -lncurses -o trail
./trail
```

---

## Basic Functions in ncurses

### 1. **Printing in the Window**
- `addstr`: Prints the specified string.
- `addch`: Prints a single character.
- `printw`: ncurses equivalent of `printf`.

### 2. **Copying Buffer to Screen**
- `refresh()`: Copies the contents from the buffer to the screen.

### 3. **Cursor Management**
- **Hide Cursor**: `curs_set(0);`
- **Move Cursor**: `move(row, column);`

### 4. **Adding Characters at Specific Positions**
- `mvaddch(row, column, ch)`: Moves the cursor to the specified position and adds the character.

### 5. **Delays**
- `napms(milliseconds)`: Introduces a delay (in milliseconds) before an event.

---

## Color Support in ncurses
### Checking and Initializing Colors
- `has_colors()`: Returns a boolean to check if the terminal supports colors.
- `start_color()`: Initializes color functionality.

### Defining Color Pairs
Use `init_pair(pair_number, foreground_color, background_color)` to define color pairs.

#### Example:
```c
init_pair(1, COLOR_YELLOW, COLOR_RED);
init_pair(2, COLOR_GREEN, COLOR_GREEN);
init_pair(3, COLOR_MAGENTA, COLOR_CYAN);

attrset(COLOR_PAIR(1));
addstr("Yellow and red\n\n");
refresh();
attroff(COLOR_PAIR(1));
```

---

## Input Handling
- **Enable Keyboard Input**: `keypad(stdscr, TRUE)`.
- **Reading Input**: 
  - `int wgetch(WINDOW *win)`: Reads a key from a window.
  - `int mvgetch(int y, int x)`: Moves the cursor and reads a character.
  - `int mvwgetch(WINDOW *win, int y, int x)`: Combines window-specific input with cursor movement.

### Special Keys
If `keypad(stdscr, TRUE)` is enabled, the following key codes are returned for special keys:
| Key Code       | Description                   |
|----------------|-------------------------------|
| `KEY_DOWN`     | Down Arrow                   |
| `KEY_UP`       | Up Arrow                     |
| `KEY_LEFT`     | Left Arrow                   |
| `KEY_RIGHT`    | Right Arrow                  |
| `KEY_HOME`     | Home Key                     |
| `KEY_BACKSPACE`| Backspace                    |
| `KEY_F(n)`     | Function Keys (n: 0-63)      |
| `KEY_DC`       | Delete Character             |
| `KEY_IC`       | Insert Character/Mode        |
| `KEY_ENTER`    | Enter Key                    |

For a full list of special keys, refer to the `man` page of `getch`.

---

## Creating a Window
To create a window, use:
```c
WINDOW *win = newwin(nlines, ncols, y0, x0);
```
- `nlines`: Height of the window.
- `ncols`: Width of the window.
- `y0`, `x0`: Coordinates of the upper-left corner of the window.

---

## References
- [An Introduction to ncurses in C](https://www.codedrome.com/an-introduction-to-ncurses-in-c/)
- [ncurses Tutorial and Functions Reference](http://jbwyatt.com/ncurses.html#init)
``` 
