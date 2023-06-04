// 1906025 Akshay Gade
// Experiment-14

//  PROGRAM  14(c):
// Single level Inheritance
#include <iostream>
#include <string>
using namespace std;

class school
{
    string s;

public:
    void get()
    {
        cout << "Enter Name of School" << endl;
        cin >> s;
    }
    void displaysch()
    {
        cout << "In School " << s<<endl;
    }
};
class Student : public virtual school //deribed class ff]rom based class school
{
    int total, boys, girls;

public:
    void getnum()
    {
        cout << "Enter total number of students" << endl;
        cin >> total;
        cout << "Enter total number of Boys" << endl;
        cin >> boys;
        cout << "Enter total number of girls" << endl;
        cin >> girls;
    }

    void displays()
    {
        cout << "There are total " << total << endl;
        cout << "In Which," << boys << " Boys and " << girls << " girls" << endl;
    }
};

class teacher : virtual public school //deribed class from based class school
{
    int trachers;

public:
    void gett()
    {
        cout << "Enter number of teachers" << endl;
        cin >> trachers;
    }

    void displayt()
    {
        cout << "There are total " << trachers << " teachers";
    }
};
class G2 : public Student, public teacher // derived class from 2 based class
{
public:
    void getg2()
    {
        get();    // calling menber function of grandparent
        getnum(); //calling menber function of parent
        gett();   // calling menber function of parent
    }
    void Display()
    {
        cout << "Information of School " << endl;
        displaysch(); // calling menber function of grandparent
        displays();   //  calling menber function of parent
        displayt();   //  calling menber function of parent
    }
};

int main()
{
    G2 G;
    G.getg2();
    cout << endl
         << endl;
    G.Display();
}