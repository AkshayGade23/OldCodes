#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>

int maxx, maxy, midx, midy;

void axis()
{
    getch();
    cleardevice();
    line(midx, 0, midx, maxy);
    line(0, midy, maxx, midy);
}

int main()
{
    int x1, x2, y1, y2, x, y;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    maxx = getmaxx();
    maxy = getmaxy();

    midx = maxx / 2;
    midy = maxy / 2;

    axis();
    bar3d(midx + 50, midy - 100, midx + 60, midy - 90, 30, 1);
    printf("Enter the translation factor: ");
    scanf("%d%d", &x, &y);

    printf("\nAfter translation: ");
    bar3d(midx + x + 50, midy - (y + 100), midx + x + 60, midy - (y + 90), 30, 1);
    getch();
    closegraph();
    return 0;
}