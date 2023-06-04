#include <iostream>

using namespace std;

class A
{

public:
    int numa = 10;
    virtual A operator+(A a)
    {
        A temp;
        temp.numa = this->numa + a.numa;
        cout << "A class\n  Numa = " << temp.numa << endl;
        return temp;
    }
};
class B : public A
{

public:
    int numb = 20;
    B operator+(B a)
    {
        B temp;
        temp.numb = this->numb + a.numb;
        cout << "B class\n  Numb = " << temp.numb << endl;
        return temp;
    }
};

int main()
{
    A *ptr_A; // Pointer of class A
    A A1;    // objects of class A
    B B1,B2;   // objects of class B

    ptr_A = &B1; // pointer pointing
    (*ptr_A)+ B2;
    // B1 + B2; 

    return 0;
}