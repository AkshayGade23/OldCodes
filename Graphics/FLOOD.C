#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void flood(int ,int ,int , int );
void flood(int x,int y,int fill_col, int old_color){
    if((getpixel(x,y)!=fill_col)&&(getpixel(x,y)!=old_color)){
        putpixel(x,y,fill_col);
        flood(x+1,y,fill_col,old_color);
        flood(x-1,y,fill_col,old_color);
        flood(x,y+1,fill_col,old_color);
        flood(x,y-1,fill_col,old_color);
    }
}
void main()
{
    int gd=DETECT,gm;
    clrscr();

    initgraph(&gd,&gm,"C:\\TURBOC#\\BGI");
    rectangle(50,50,100,100);
    flood(55,55,4,15);
    getch();
    closegraph();
}
