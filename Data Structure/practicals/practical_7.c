// Write Program to perform Insert and Delete operations on Linear Queue using array
#include <stdio.h>

void printArray(int A[], int front, int rear);
void Enqueue(int A[], int n, int *front, int *rear, int elem);
void Dequeue(int A[], int n, int *front, int *rear);

void printArray(int A[], int front, int rear)
{
    int i;
    for (i = front; i <= rear; i++)
    {
        printf("%d \n", A[i]);
    }
    printf("\n");
}

void Enqueue(int A[], int n, int *front, int *rear, int elem)
{
    if ((*rear) + 1 >= n)
        printf("Queue is full...\n");

    else
    {

        if ((*front) == -1)
        {
            ++(*front);
        }

        ++(*rear);
        A[*rear] = elem;
    }
    return;
}

void Dequeue(int A[], int n, int *front, int *rear)
{
    if ((*front) > (*rear))
        printf("Queue is empty...\n");

    else
    {
        ++(*front);
    }

    return;
}

void main()
{
    int A[10];
    int n = sizeof(A) / sizeof(int);
    int front = -1;
    int rear = -1;

    Enqueue(A, n, &front, &rear, 45);
    Enqueue(A, n, &front, &rear, 56);
    Enqueue(A, n, &front, &rear, 56);
    Enqueue(A, n, &front, &rear, 434);
  
    printArray(A, front, rear);
    

    Dequeue(A, n, &front, &rear);
    printArray(A, front, rear);

    Dequeue(A, n, &front, &rear);
    printArray(A, front, rear);

    Dequeue(A, n, &front, &rear);
    printArray(A, front, rear);

    
}