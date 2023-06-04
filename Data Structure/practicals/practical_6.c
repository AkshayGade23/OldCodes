//Write Program to perform Push and Pop operations on Stack using array

#include <stdio.h>

void printArray(int *A, int Top);
void push(int A[], int n, int *Top, int elem);
int pop(int A[], int *Top);

void printArray(int *A, int Top)
{
    int i;
    for (i = 0; i <= Top; i++)
    {
        printf("%d \n", A[i]);
    }
    printf("\n");
}

void push(int A[], int n, int *Top, int elem)
{
    if ((*Top) + 1 >= n)
        printf("array is full\n\n");

    else
    {
        ++(*Top);
        A[*Top] = elem;
         printf("%d is pushed\n",A[*Top]);
    }
}

int pop(int A[], int *Top)
{
    int poped;
    if ((*Top) == -1)
        printf("array is EMPTY\n");

    else
    {
        printf("%d is popped\n",A[*Top]);
        --(*Top);
    }
}

void main()
{
    int A[10];
    int n = 10;
    int Top = -1;

    push(A, n, &Top, 47);
    push(A, n, &Top, 57);
    push(A, n, &Top, 37);
   
    
    printArray(A, Top);
    pop(A, &Top);
    printArray(A, Top);
    pop(A, &Top);
    printArray(A, Top);
    pop(A, &Top);
    pop(A, &Top);
}