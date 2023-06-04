// 1906025 Akshay Gade
// Experiment no. 13

// primitive type to class type
#include <iostream>
using namespace std;

class Product
{
    int P = 4;

public:
    int getP()
    {
        return P;
    }
    void getdata()
    {
        cout << "value of P = " << P << endl;
    }
};
class Item
{
    int I = 4;

public:
    Item() {}
    Item(Product C)
    {
        I = C.getP();
    }
    void getdata()
    {
        cout << "value of I = " << I << endl;
    }
};

int main()
{
    Item x;
    Product C;
    x = C;
    C.getdata();
    x.getdata();

    return 0;
}