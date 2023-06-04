#include<stdio.h> 
#include<graphics.h> 

void findNewCoordinate(int s[][2], int p[][1]) 
{ 
	int temp[2][1] = { 0 }; 
	     int i, j, k;
	for (i = 0; i < 2; i++)
		for (j = 0; j < 1; j++)
			for (k = 0; k < 2; k++)
				temp[i][j] += (s[i][k] * p[k][j]);

	p[0][0] = temp[0][0];
	p[1][0] = temp[1][0];
}

// Scaling the Polygon
void scale(int x[], int y[], int sx, int sy)
{
	int p[2][1], i;
	int s[2][2];
	s[0][0] = sx;
	s[0][1] = 0;
	s[1][0] = 0;
	s[1][1] = sy;

	line(x[0], y[0], x[1], y[1]);
	line(x[1], y[1], x[2], y[2]);
	line(x[2], y[2], x[0], y[0]);

	for (i = 0; i < 3; i++)
	{

		p[0][0] = x[i];
		p[1][0] = y[i];

		findNewCoordinate(s, p);

		x[i] = p[0][0];
		y[i] = p[1][0];
	}

	line(x[0], y[0], x[1], y[1]);
	line(x[1], y[1], x[2], y[2]);
	line(x[2], y[2], x[0], y[0]);
}


int main()
{
	int x[] = { 100, 200, 300 };
	int y[] = { 200, 100, 200 };
	int sx = 2, sy = 2;

	int gd, gm;
	detectgraph(&gd, &gm); 
	initgraph(&gd, &gm,"C:\\TURBOC3\\BGI "); 

	scale(x, y, sx,sy); 
	getch(); 

	return 0; 
} 
