#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

int main()
{
    int gd = DETECT, gm;

    int x1, x2, y1, y2, xn, yn, r;
    double radians, c, s, deg;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    printf("\nEnter the 2 line end points (x1, y1, x2, y2): ");
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    line(x1, y1, x2, y2);
    getch();

    printf("\nEnter the degree of rotation: ");
    scanf("%lf", &deg);


    radians = deg * 0.01745;
    c = cos(radians);
    s = sin(radians);
    r = x2 - x1;

    xn = x1 + r * c + 1;
    yn = y1 + r * s + 1;

    line(x1, y1, xn, yn);

	getch();
	closegraph();
    return 0;
}