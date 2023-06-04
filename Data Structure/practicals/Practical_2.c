//Implement Program to perform insertion and deletion operations on One Dimensional Array.

#include <stdlib.h>
#include <stdio.h>

void insert(int *arr, int data, int *size, int index, int capacity)
{

    int i;
    if ((*size) >= capacity)
    {
        printf(" full\n");
        return;
    }
    if (index <= (*size))
    {
        for (i = (*size) - 1; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[index] = data;
        *size += 1;
        return;
    }
    printf("Arreay is till this postion( %d ) so data will insert next to it\n",(*size));
    arr[*size] = data;
    (*size) += 1;

    return;
}

void delete (int arr[], int *size, int index)
{

    int i;
    if ((*size) == 0)
    {
        printf(" empty\n");
        return;
    }
    if (index <= (*size))
    {
        for (i = index ; i < (*size); i++)
        {
            arr[i] = arr[i + 1];
        }

        *size -= 1;
        return;
    }
printf("data is not present at this  %d  position\n",index);
    return ;
}

void display(int arr[], int *size)
{
    if ((*size == 0))
    {
        printf("Empty");
        return ;
    }
    for (int i = 0; i < (*size); i++)
        printf("  %d  \n", arr[i]);

        printf("\n\n");
}

void main()
{
    int arr[10] = {12, 156, 34};
    int size=3;

    int capacity= sizeof(arr) / sizeof(int);
 
     display(arr,&size);
//  insert ( address of "arr",element which will inser,address of "size",position,capacity of array)
    insert(arr, 45, &size, 2, capacity); 
     display(arr,&size);

   
    
//delete (adress of "arr", adress of "size", position)
    delete (arr, &size, 0);
    printf("deleted successfuly\n");
     display(arr,&size);

}