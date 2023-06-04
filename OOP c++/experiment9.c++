// Write a program on nesting of functions.


#include <iostream>                // header files
#include <string>

using namespace std;

class Binary
{
    string s;

public:
    void read(void);                  // member functions
    void CheckBinary(void);
    void OnesComp(void);
    void Display(void);
};

//  defination of member functions
 
void Binary ::read()
{
    cout << "Enter a Binary number" << endl;
    cin >> s;
}

void Binary ::CheckBinary()         // Check whether its binary number or not
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) != '0' && s.at(i) != '1')
        {
            cout << "Incorrect Binary Format" << endl;
            exit(0);
        }
    }

    cout << "Correct Binary Format" << endl;
}

void Binary ::Display()
{

    cout << s << endl;
}

void Binary ::OnesComp()          //  OnesCompliment of Binary Number
{
    CheckBinary();                      // nesting of function

    for (int i = 0; i < s.length(); i++)
    {
        if (s.at(i) == '0')
            s.at(i) = '1';

        else
            s.at(i) = '0';
    }

    cout << "OnesCompliment: ";
    Display();                        //  nesting of function
}

int main()                           //  main function
{
    Binary Num;
    Num.read();
    Num.OnesComp();
    
    return 0;
}

