/* Write Programs to implement sorting algorithms. (Bubble sort,
   Selection sort, Insertion sort, Merge sort, Radix sort, Shell sort) */

#include <stdio.h>
#include <stdlib.h>

void printArray(int *A, int n);
void swap(int *i, int *j);
int getmax(int A[], int n);
void BubbleSort(int *A, int n);
void InsertionSort(int *A, int n);
void SelctionSort(int *A, int n);
void Merge(int *A, int low, int mid, int high);
void MergeSort(int *A, int low, int high);
void countsort(int A[], int n, int pos);
void RadixSort(int A[], int n);
void ShellSort(int A[], int n);

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
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}

int getmax(int A[], int n)
{
    int i;
    int max = A[0];
    for (i = 1; i < n; i++)
        if (max < A[i])
            max = A[i];
    return max;
}

void BubbleSort(int *A, int n)
{
    int i, j;
    int isSorted = 0;
    for (i = 0; i < n - 1; i++)
    {
        isSorted = 1;

        for (j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(&A[j], &A[j + 1]);
                isSorted = 0;
            }
        }
        if (isSorted)
            return;
    }
}

void InsertionSort(int *A, int n)
{
    int i, j;
    int key;
    for (i = 1; i <= n - 1; i++)
    {
        key = A[i];
        j = i - 1;
        while (j >= 0 && (A[j] > key))
        {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = key;
    }
    return;
}

void SelctionSort(int *A, int n)
{
    int i, j;
    int Index_Min;

    for (i = 0; i < n - 1; i++)
    {
        Index_Min = i;
        for (j = i + 1; j <= n - 1; j++)
        {
            if (A[Index_Min] > A[j])
                Index_Min = j;
        }
        swap(&A[i], &A[Index_Min]);
    }
}

void Merge(int *A, int low, int mid, int high)
{

    int b[100];
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            b[k] = A[i];
            i++;
            k++;
        }
        else
        {
            b[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        b[k] = A[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = A[j];
        j++;
        k++;
    }
    i = low;

    while (i <= high && k <= (high - low))
    {
        A[i] = b[k];
    }

    for (i = low; i <= high; i++)
    {
        A[i] = b[i];
    }
}

void MergeSort(int *A, int low, int high)
{
    int mid;

    if (low < high)
    {
        mid = (low + high) / 2;
        MergeSort(A, low, mid);
        MergeSort(A, mid + 1, high);
        Merge(A, low, mid, high);
    }
}

void countsort(int A[], int n, int pos)
{
    int count[10] = {0};
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

    for (i = n - 1; i >= 0; i--)
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
    int pos = 1;

    while ((max / pos) > 0)
    {
        countsort(A, n, pos);
        pos = pos * 10;
    }
}

void ShellSort(int A[], int n)
{
    int gap,j,i;
    for (gap = n / 2; gap >= 1; gap/=2)
    {
        for (j = gap; j < n; j++)
        {
            for (i = j-gap; i >= 0 && (A[i] >A[i+gap]); i - gap)
            {  
                   swap(&A[i], &A[i+gap]);
            }
        }
    }
}

void main()
{
    int A[] = {1, 2, 4, 55555, 3, 34, 4343,420, 5,74,998,4355,23,56,999,446,123,23,2};
    int n = sizeof(A) / sizeof(int);

    printArray(A, n);
    printf("\n\n");
    
    //BubbleSort(A,n);
    
    // InsertionSort(A, n);
     printf("Shell Sort\n");

     //SelctionSort(A, n);
    // MergeSort(A, 0, n-1);
    // RadixSort(A, n);
   ShellSort(A,n);

    printArray(A, n);
}