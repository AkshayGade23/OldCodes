#include <iostream>
#include <math.h>
#include <string>
using namespace std;

class student
{
protected:
    int a;
    string name;

public:
    void setnameid(string s, int id)
    {
        name = s;
        a = id;
    }

    void showdetail()
    {
        cout << "ID is " << a << endl
             << "Name is " << name << endl;
    }
};
class sports : virtual public student
{
protected:
    string sport;

public:
    void setsport(string s)
    {
        sport = s;
    }
    void showsport()
    {
        cout << "Sport  is " << sport << endl;
    }
};

class test : public virtual student
{
protected:
    int tes1, tes2;

public:
    void settest(int x, int y)
    {
        tes1 = x;
        tes2 = y;
    }
    void showtest()
    {
        cout << "marks of tes1  is " << tes1 << endl;
        cout << "marks of tes2  is " << tes2 << endl;
    }
};

class result : public test, public sports
{

public:
    void set()
    {
        setnameid("AKshay", 25);
        settest(19, 18);
        setsport("Cricket");
    }
    void put()
    {
        showdetail();
        showsport();
        showtest();
    }
};

int main()
{
    result r;
    r.set();
    r.put();
    return 0;
}