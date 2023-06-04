
#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    int id;
    string name;

    Student(int x, string s)
    {
        id = x;
        name = s;
    }

    virtual void display() = 0;
};

class test : public Student
{
public:
    int t1, t2;

    test(int x, string s, int m1, int m2) : Student(x, s)
    {
        t1 = m1;
        t2 = m2;
    }
    void display()
    {
        cout << "ID = " << id << endl
             << "Name = " << name << endl;

        cout << "MArks of TEST1 = " << t1 << endl;
        cout << "MArks of TEST2 = " << t2 << endl;
    }
};

class Sport : public Student
{
public:
    string sp;

    Sport(int x, string s, string p) : Student(x, s) { sp = p; }

    void display()
    {
        cout << "ID = " << id << endl
             << "Name = " << name << endl;

        cout << "Sport = " << sp << endl;
    }
};

int main()
{
    Student *ptr[2];
    test t(25, "Akshay", 19, 20);
    Sport s(25, "Akshay", "Cricket");

    ptr[0] = &t;
    ptr[1] = &s;

    ptr[0]->display();
    cout << endl;
    ptr[1]->display();
}