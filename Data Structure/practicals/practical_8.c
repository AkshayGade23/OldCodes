// Write Program to implement Tower of Hanoi.

#include <stdio.h>
void TowerOfHonoi(int n, char from, char to, char via);

int i = 1;

void TowerOfHonoi(int n, char from, char to, char via)
{
  //  if (n == 1)
     //   printf("%d.  < %c to %c >\n", i++, from, to);

   // else
   if(n>0)
    {
        TowerOfHonoi(n - 1, from, via, to);
        printf("%d.  < %c to %c >\n", i++, from, to);
        TowerOfHonoi(n - 1, via, to, from);
    }
}
void main()
{
    int n = 4;
    char from = 'A', to = 'c', via = 'B';

    printf("Move upper disk (from) to (to)\n  steps are\n");
    TowerOfHonoi(n, from, to, via);
}