#include "game.h"
#include<GL/gl.h>
#include<GL/glut.h>
#include<ctime>
#include <stdio.h>
#include <stdlib.h>

int gridx,gridy;
bool food=true;
int snake_length=5;
int foodx,foody;
short sdirection=RIGHT;
int posx[60]={20,20,20,20,20},posy[60]={20,19,18,17,16};
extern bool gameover;
extern int score;


void initGrid(int x,int y)
{
    gridx=x;
    gridy=y;
}
void unit(int,int);
void drawGrid()
{   for(int x=0;x<gridx;x++)
    {
        for(int y=0;y<gridy;y++)
        {
            unit(x,y);
        }
    }
}
void unit(int x,int y)
{   if(x==0 || y==0 || x==gridx-1 || y==gridy-1)
    {
        glLineWidth(3.0);
        glColor3f(1.0,0.0,0.0);
    }
    else
    {
        glLineWidth(1.0);
        glColor3f(1.0,1.0,1.0);
    }

    glBegin(GL_LINE_LOOP);
        glVertex2f(x,y);
        glVertex2f(x+1,y);
        glVertex2f(x+1,y+1);
        glVertex2f(x,y+1);

    glEnd();
}
void drawfood()
{
    if(food)
        random(foodx,foody);
    food=false;
    glColor3f(1.0,0.0,0.0);
    glRectf(foodx,foody,foodx+1,foody+1);
}
void drawsnake()
{
    for(int i=snake_length-1;i>0;i--)
    {
        posx[i]=posx[i-1];
        posy[i]=posy[i-1];
    }
    if(sdirection==UP)
        posy[0]++;
    else if(sdirection==DOWN)
        posy[0]--;
    else if (sdirection==RIGHT)
        posx[0]++;
    else if (sdirection==LEFT)
        posx[0]--;
    for(int i=0;i<snake_length;i++)
    {
        if(i==0)
            glColor3f(0.0,1.0,0.0);
        else
            glColor3f(0.0,0.0,1.0);
        glRectd(posx[i],posy[i],posx[i]+1,posy[i]+1);
    }

    if(posx[0]==0 || posx[0]== gridx-1 || posy[0]==gridy-1 || posy[0]==0)
        gameover=true;
    if(posx[0]==foodx && posy[0]==foody){
        score++;
        snake_length++;
        if(snake_length>60)
            snake_length=60;
        food=true;
    }
}
void random(int &x,int &y)
{
    int _maxx= gridx-2;
    int _maxy=gridy-2;
    int _min = 1;
    srand((time(NULL)));
    x=_min + rand() % (_maxx-_min);
    y=_min + rand() % (_maxy-_min);
}
