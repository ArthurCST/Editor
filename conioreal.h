#ifndef __CONIOREAL_H
#define __CONIOREAL_H

#ifndef __CURSES_H
#include <curses.h>
#endif

#define BLACK         0
#define RED           1
#define GREEN         2
#define BROWN         3
#define BLUE          4
#define MAGENTA       5
#define CYAN          6
#define LIGHTGRAY     7
#define DARKGRAY      8
#define LIGHTRED      9
#define LIGHTGREEN    10
#define YELLOW        11
#define LIGHTBLUE     12
#define LIGHTMAGENTA  13
#define LIGHTCYAN     14
#define WHITE         15

int initconio(void);
int endconio(void);
int clrscr(void);
int clreol(void);
int textcolor(int color);
int textbackground(int color);
int getche(void);
int wherex(void);
int wherey(void);
int gotoxy(int x, int y);
int newline(void);
short cur_pair, cur_bold;

#endif