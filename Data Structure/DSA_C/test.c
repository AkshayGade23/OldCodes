#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void postfix(char a[])
{
  char value,x;
  int i, j;
  char *postfix = (char *)malloc(strlen(a) + 1);
  i = j = 0;
  value = a[i];

  while (value != '/0')
  {
    if (value == '(')
      push(value);

    else if (value == ')')
    {
      while ((x = pop()) != '(')
        postfix[j++] = x;
    }

    else if (isoperator(value))
    {
      while (!empty() && precedance(top()) >= precedance(value))
      {
        postfix[j++] = pop();
      }
      push(value);
    }

    else
    {
      postfix[j++] = value;
    }
    i++;

    value = a[i];
  }

  while (!empty())
  {
    postfix[j++] = pop();
  }

  postfix[j] = '/0';

  return postfix;
}

void main()
{
}