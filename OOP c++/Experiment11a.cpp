// 1906025 Akshay Gade
//  PROGRAM 11:
// Experiment-11
#include <iostream>
using namespace std;

class Complex
{
    int a, b;

public:
    Complex() {}
    Complex(int x, int y)
    {
        a = x;
        b = y;
    }
    void display()
    {
        cout << "( " << a << " + " << b << " )i" << endl;
    }

    Complex operator+(Complex C)
    {
        Complex temp;
        temp.a = a + C.a;
        temp.b = b + C.b;

        return temp;
    }
};
int main()
{
    Complex C1(5, 10);
    Complex C2(15, 30);
    Complex C3;

    C1.display();
    C2.display();

    C3 = C1 + C2;

    C3.display();

    return 0;
}