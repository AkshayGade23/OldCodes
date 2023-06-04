#include "bits/stdc++.h"
using namespace std;

// void Merge(int[], int, int, int);
// void MergeSort(int[], int, int);
// void printArray(int *, int);

void printArray(int *A, int n)
{
    int i;
    for (i = 0; i <= n - 1; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void Merge(int *A, int low, int mid, int high)
{
    cout << low << " " << mid << " " << high << endl;
    int b[100];
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
            b[k++] = A[i++];

        else
            b[k++] = A[j++];
    }

    while (i <= mid)
        b[k++] = A[i++];

    while (j <= high)
        b[k++] = A[j++];

    i = low;

    for (i = low; i <= high; i++)
        A[i] = b[i];
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

int main()
{
    int A[] = {99, 98, 97, 96, 2, 94, 93, 92, 91, 90};
    int n = sizeof(A) / sizeof(int);

    printArray(A, n);

    MergeSort(A, 0, n - 1);
    printArray(A, n);
    return 0;
}