#include<stdio.h>
 void printArray(int *A,int n)
 {
     int i;
    for(i = 0;i <= n-1;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
 }

void swap(int * i,int * j)
{
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}

void BubbleSort(int *A,int n)
{
    int i,j;
    int isSorted=0;
    for(i = 0;i < n-1;i++)
    {
        isSorted=1;
        printf("number of passes %d\n",i+1);
        for(j = 0;j < n-1-i;j++)
        {
            if(A[j] > A[j+1])
            {
             swap(&A[j],&A[j+1]);
             isSorted = 0;
            }
        }
        if(isSorted)
        return;
   }
}

void main()
{
    int A[]={1,2,4,3};
    int n = sizeof(A)/sizeof(int);

    printArray(A,n);
    BubbleSort(A,n);
    printArray(A,n);
    
}