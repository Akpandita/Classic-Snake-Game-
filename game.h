#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#define UP 1
#define DOWN -1
#define LEFT -2
#define RIGHT 2
void initGrid(int,int);
void drawGrid();
void drawsnake();
void drawfood();
void random(int& , int&);
#endif
