// Akshay Gade Creation
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MAX 30

class Stack
{
    string data[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }
    void push(string x)
    {
        data[++top] = x;
    }
    string pop()
    {
        return data[top--];
    }
    string topValue()
    {
        return data[top];
    }

    bool empty()
    {
        if (top == -1)
            return true;

        return false;
    }

    bool full()
    {
        if (top == MAX - 1)
            return true;

        return false;
    }
};

bool isOperator(string c)
{
    if (c == "+" || c == "-" || c == "/" || c == "*")
        return true;

    return false;
}
string prefixToInfix(string expression)

{
    Stack stack = Stack();
    string infix;

    for (int i = 0; i < expression.size(); i++)
    {
        string c = string(1, expression[i]);

        if (c == " ")
            continue;
        if (isOperator(c))
        {
            if (!stack.full())
            {
                stack.push(")");
                infix.append(" (");
                stack.push(c);
            }
        }
        else
        {
            if (i + 1 < expression.size())

                if (expression[i + 1] != ' ')
                    c += expression[++i];

            infix.append(" " + c);
            if (!stack.empty())
            {
                if (stack.topValue() == ")")
                    infix.append(" " + stack.pop());

                infix.append(" " + stack.pop());
            }
        }
    }
    return infix;
}

double evaluatePrefix(string expression)
{
    Stack stack = Stack();
    for (int i = expression.size() - 1; i >= 0; i--)
    {
        string c = string(1, expression[i]);
        if (c == " ")
            continue;

        if (isdigit(expression[i]))
        {
            if (i - 1 > -1)
            {
                if (isdigit(expression[i - 1]))
                {
                    c += expression[--i];
                    reverse(c.begin(), c.end());
                }
            }
            stack.push(c);
        }

        else
        {
            double o1 = stod(stack.pop());
            double o2 = stod(stack.pop());

            switch (expression[i])
            {
            case '+':
                stack.push(to_string(o1 + o2));
                break;
            case '-':
                stack.push(to_string(o1 - o2));
                break;
            case '*':
                stack.push(to_string(o1 * o2));
                break;
            case '/':
                stack.push(to_string(o1 / o2));
                break;
            }
        }
    }
    return stod(stack.topValue());
}

int main()
{
    cout << prefixToInfix("+ / 51 3 / 2 1") << endl;
    cout << evaluatePrefix("+ / 51 3 / 2 1") << endl;
    return 0;
}