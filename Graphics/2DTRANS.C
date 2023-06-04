//2D translation, scaling and rotation
#include<stdio.h>
#include<conio.h>
#include<graphics.h>

int main()
{
	int gd = DETECT, gm;
	int i;
	int x1, x2, y1, y2, x, y;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	printf("\nEnter the 2 line end points (x1, y1, x2, y2): ");
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

	line(x1, y1, x2, y2);
	getch();
	cleardevice();
	printf("\nEnter the translation points: ");
	scanf("%d%d", &x, &y);

	x1 = x1 + x;
	y1 = y1 + y;
	x2 = x2 + x;
	y2 = y2 + y;

	printf("\nLine After Translation:\n");
	line(x1, y1, x2, y2);

	getch();
	closegraph();
 return 0;
}