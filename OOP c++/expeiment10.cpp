//  Experiment -10
// 1906025 Akshay Gade
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

class BuiltIn
{
    string s;                 // delcaring variables

public:
    void getstring1()
    {
        cout << "Enter String For BuiltIn Functions " << endl;
        cin >> s;
        cout << endl
             << endl;
    }

    void BuiltIn_Func()
    {
        // concatination
        cout << "Conanating string (" << s << ") with string (Concat) " << endl;
        s.append("Concat"); // In built function

        cout << "Concatinated string =" << s << endl
             << endl;

        // Comparision
        {
            string sample;
            cout << " Enter string for Compare" << endl;
            cin >> sample;

            if (s.compare(sample) == 0) // comapring string
                cout << "String " << s << "  is equal to string  " << sample
                     << endl
                     << endl;

            else
                cout << "String " << s << "  is not equal to string  " << sample
                     << endl{
                     << endl;
        }

        // find postion of charater in string
        {
            char sample;
            cout << "Enter Charater" << endl;
            cin >> sample;
            // finding postion of charater
            cout << " 1st occurance of (" << sample << ") is at " << s.find(sample) << endl
                 << endl;
        }

        // Reverse string
        cout << " Reversing String " << endl;
        reverse(s.begin(), s.end());           //reversing string
        cout << " Reversed string = " << s
             << endl
             << endl
             << endl;
    }
};

class UserDefined
{
    string s;           // delcaring variables

public:
    void getstring2()
    {
        cout << "Enter String For UserDefined Functions " << endl;
        cin >> s;
        cout << endl<< endl;
    }

    void UserDefined_Func()
    {
        // concatination
        cout << "Conanating string (" << s << ") with string (Concat) " << endl;
        s = s + "Concat";                //  appending string
        cout << "Concatinated string =" << s<< endl<< endl;

        // Comparision
        {
            string sample;
            cout << "Enter string for Compare" << endl;
            cin >> sample;

            if (s.length() == sample.length())
            {
                for (int i = 0; i < s.length(); i++)      // comparing string
                {
                    if (s.at(i) != sample.at(i))         // comparing charater
                    {
                        cout << "String " << s << "is not  equal to string " << sample<< endl<< endl;
                        break;
                    }
                }
                cout << "String " << s << "is equal to string " << sample<< endl<< endl;
                     
                     
            }

            else
                cout << "String " << s << "is not equal to string " << sample<< endl<< endl;
        }

        // find postion of charater in string
        {
            int flag = 0;
           char sample;               // declaring variables

            cout << "Enter Charater" << endl;
            cin >> sample;

            for (int i = 0; i < s.length(); i++)
            {
                if (s.at(i) == sample)          // finding positon
                {
                    flag = 1;
                    cout << "Occurance of charater is at " << i + 1 << "position " << endl;
                }
            }
            if (flag == 0)
                cout << " This character is not present in this string" << endl<< endl;
        }

        // Reverse string
        cout << " Reversing String " << endl;

        for (int i = 0; i < (s.length() / 2); i++)   //reversing string
        {
            swap(s[i], s[(s.length() - i - 1)]);
        }
        cout << " Reversed string = " << s << endl;

    }
};
int main()
{
    BuiltIn A;
    UserDefined B;

    A.getstring1();             // calling member functions
    A.BuiltIn_Func();

    B.getstring2();
    B.UserDefined_Func();

    return 0;
}