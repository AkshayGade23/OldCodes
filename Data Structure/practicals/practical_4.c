/* Implement programs for following search techniques.
   i. Linear search ii. Binary Search */

#include <stdio.h>
void linear_search(int A[], int size, int element);
void Bianry_search(int B[], int min, int max, int element);



void printArray(int *A, int n)
{
    int i;
    for (i = 0; i <= n - 1; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}



void linear_search(int A[], int size, int element)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (A[i] == element)
        {
            printf("this Element is present at position   '%d'\n\n", i + 1);
            return;
        }
    }
    printf("Elemet is not found\n ");
}

void binary_search(int B[], int min, int max, int element)
{
    int mid ;
    if (min <= max)
    {
         mid = (max + min) / 2;

        if (B[mid] == element)
        {
         printf("this Element is present at position   '%d'\n\n",mid+1);
        }
        else if (B[mid] >= element)
        {
            binary_search(B, min, mid - 1,element);
        }

        else if (B[mid] <= element)
        {
            binary_search(B, mid + 1, max, element);
        }
    }
    else 
    printf("Elemet is not found");

    
}

void main()
{
    int A[] = {2, 4, 5, 6, 67, 8, 8, 5};
    int B[] = {2, 4, 25, 36, 67,69, 88, 95,100};
    int m = sizeof(A) / sizeof(int);
    int n = sizeof(B) / sizeof(int);
    int min = 0;
    int max = n - 1;
    int element;
    int element1;

     printf("Enter the ELEMENT to Linear search ");
     scanf("%d", &element1);
     linear_search(A, m, element1);

    
    printf("Enter the ELEMENT to Binary search ");
    scanf("%d", &element);

    binary_search(B, min, max, element);
}