#include<windows.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#define COLUMNS 40
#define ROWS 40
#define FPS 10

extern short sdirection;
bool gameover=false;

int score;

void display_callback();
void reshape_callback(int,int);
void timer_callback(int);
void keyboard_callback(int,int,int);
void init()
{
    glClearColor(0.0,0.0,0.0,1.0);
    initGrid(COLUMNS,ROWS);
}
int main(int argc,char** argv)
{
      glutInit(&argc,argv);
      glutInitDisplayMode(GLUT_RGB | GL_DOUBLE);
      glutInitWindowSize(500,500);
      glutCreateWindow("Snake Game");
      glutDisplayFunc(display_callback);
      glutReshapeFunc(reshape_callback);
      glutTimerFunc(0,timer_callback,0);
      glutSpecialFunc(keyboard_callback);
      init();
      glutMainLoop();
      return 0;
}
int index=0;
void display_callback()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    drawsnake();
    drawfood();
    glutSwapBuffers();
    if(gameover)
    {
        char _score[10];
        itoa(score,_score,10);
        char text[50]="Your score: ";
        strcat(text,_score);
        MessageBox(NULL,text,"GAME OVER",0);
        exit(0);
    }
}
void reshape_callback(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,COLUMNS,0.0,ROWS,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
}
void timer_callback(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/FPS,timer_callback,0);
}
void keyboard_callback(int key,int ,int)
{
    switch(key)
    {
    case GLUT_KEY_UP:
        if(sdirection!=DOWN)
            sdirection=UP;
        break;
    case GLUT_KEY_DOWN:
        if(sdirection!=UP)
            sdirection=DOWN;
        break;
    case GLUT_KEY_RIGHT:
        if(sdirection!=LEFT)
            sdirection=RIGHT;
        break;
    case GLUT_KEY_LEFT:
        if(sdirection!=RIGHT)
            sdirection=LEFT;
        break;
    }
}
