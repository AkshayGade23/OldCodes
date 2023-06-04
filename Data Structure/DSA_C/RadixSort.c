#include <stdio.h>
#include <stdlib.h>
void printArray(int *A, int n)
{
    int i;
    for (i = 0; i <= n - 1; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
int getmax(int A[], int n)
{ 
    int i;
    int max = A[0];
    for ( i = 1; i < n; i++)
        if (max < A[i])
            max = A[i];

  
    return max;
}

void countSort(int A[], int n, int pos)
{
    int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int i;
    int j;
    int *B = (int *)malloc(n * sizeof(int));
   
    for (i = 0; i < n; i++)
    {
        ++count[(A[i] / pos % 10)];
    }
    for (i = 1; i < 10; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    for (i = n-1; i >= 0; i--)
    {
        B[--count[A[i] / pos % 10]] = A[i];
    }

    for (i = 0; i < n; i++)
    {
        A[i] = B[i];
    }
   
}
void RadixSort(int A[], int n)
{
   
    int max = getmax(A, n);
    int pos = 1 ;

    while ((max / pos) > 0)
    {
        countSort(A, n, pos);
        pos = pos * 10;
    }
   
}

void main()
{
    int A[] = {1, 2, 3, 66, 34, 45, 353, 55, 12};
    int n = sizeof(A) / sizeof(int);

    printArray(A, n);
    RadixSort(A, n);
    printArray(A, n);
}