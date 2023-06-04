#include <iostream>
using namespace std;

void deleteCharAt(string *str, int i)
{
    if (str == NULL)
        return;

    str[i] = str[i + 1];
    deleteCharAt(str, i + 1);
}

string backpsaceString(string *str)
{

    int i = 0;

    while (str != NULL)
    {

        if (str[i].compare("#") == 0)
        {
            if (i != 0)
            {
                deleteCharAt(str, i);
                i--;
            }
            deleteCharAt(str, i);
            i--;
        }
        else
            i++;
    }
    cout << "------------";
    string s(s.begin, s.end);
    cout << " temp  " << s;
    return s;
}

bool backspaceCompare(string s, string t)
{
    return backpsaceString(s).compare(backspaceCompare(t)) == 0 ? true : false;
}

int main()
{
    string s = "ab#c";
    string t = "ad#c";

    cout << backspaceCompare(s, t);

    return 0;
}