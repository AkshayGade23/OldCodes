#include <iostream> //header file
using namespace std;

class rectangle
{
public:
    int lgnt, bdth, area; // declaring variables

    rectangle() {}
    rectangle(int l, int b)

    {
        lgnt = l;
        bdth = b;
    }
    friend rectangle Area(rectangle); //  declaration of friend function
    void perimeter(void)              //  member function
    {
        cout << "Perimeter of Rectangle is " << 2 * (lgnt + bdth) << endl;
    }
};

rectangle Area(rectangle R) // object as function argument and returning object 
{
    R.area = R.lgnt * R.bdth;
    return R;
}

int main() //  main function
{
    rectangle R(20, 30), R1; // declare object
    R.perimeter();           // calling member function

    R1 = Area(R); // calling friend function
    cout << "Area of REactagle is " << R1.area << endl;
    return 0;
}
