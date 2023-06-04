#include <stdio.h>

void printArray(int *A, int n)
{
    int i;
    for (i = 0; i <= n - 1; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;

    do
    {
        while (A[i] <= pivot)
            i++;

        while (A[j] > pivot)
            j--;

        if (i < j)
            swap(&A[i], &A[j]);

    } while (i < j);

    swap(&A[low], &A[j]);
    return j;
}

void QuickSort(int A[], int low, int high)
{
    if (low < high)
    {
        int PartitionIndex = partition(A, low, high);
        QuickSort(A, low, PartitionIndex - 1);
        QuickSort(A, PartitionIndex + 1, high);
    }
}
void main()

{
    int A[] = {99, 98, 91, 97, 96, 95, 94, 93, 92, 95, 94, 91, 90};
    int n = sizeof(A) / sizeof(int);

    printArray(A, n);
    QuickSort(A, 0, n - 1);
    printArray(A, n);
}