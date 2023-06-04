#include <iostream>
#include <math.h>
using namespace std;

class point
{
    int x, y;

public:
    friend void distancemeasure(point p1, point p2);
    point(int a, int b)
    {
        x = a;
        y = b;
    }
};

void distancemeasure(point p1, point p2)
{
    cout << "distance is " << sqrt(((p2.x - p1.x) * (p2.x - p1.x)) - ((p2.y - p1.y) * (p2.y - p1.y))) << endl;
}

int main()
{
    point p1(76, 1), p2(0,1 );

    distancemeasure(p1, p2);
}
