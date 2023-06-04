
 /* Implement Program for matrix operations using Multidimensional Arrays. (Eg. Matrix Addition,
   Subtraction and Multiplication) */

#include <stdio.h>

#define MAX 40

void dis_matrix(int A[][MAX], int row, int col);
void add_matrix(int A[][MAX], int B[][MAX], int C[][MAX], int row, int col);
void sub_matrix(int A[][MAX], int B[][MAX], int C[][MAX], int row, int col);
void mul_matrix(int A[][MAX], int B[][MAX], int C[][MAX], int row, int col, int col1);
void input_matrix(int A[][MAX], int row, int col);

void dis_matrix(int add[][MAX], int row, int col)
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            printf("%d  ", add[i][j]);

        printf("\n");
    }
}

void add_matrix(int A[][MAX], int B[][MAX], int C[][MAX], int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void sub_matrix(int A[][MAX], int B[][MAX], int C[][MAX], int row, int col)
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void mul_matrix(int A[][MAX], int B[][MAX], int C[][MAX], int row, int col, int col1)
{

    int sum, i, j, k;

    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            sum = 0;
            for (k = 0; k < col1; k++)
            {
                sum = sum + A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

void input_matrix(int A[][MAX], int row ,int col)
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
}


void main()
{
    int A[MAX][MAX], B[MAX][MAX], mul[MAX][MAX], add[MAX][MAX], sub[MAX][MAX];

    int col1, row1, row2, col2;
    int i, j, k;

    printf("Enter number of rows and columns of A\n");
    scanf("%d %d", &row1, &col1);

    printf("Enter elements\n");
    input_matrix(A, row1, col1);



    printf("number of rows and columns of B \n");
    scanf("%d %d", &row2, &col2);

    printf("Enter elements\n");
    input_matrix(B, row2, col2);



    if ((col1 == col2) && (row1 == row2))
    {
        add_matrix(A, B, add, row1, col1);
        printf("Addtion \n");
        dis_matrix(add, row1, col1);

        printf("\n\n");

        sub_matrix(A, B, sub, row1, col1);
        printf("subtracation \n");
        dis_matrix(sub, row1, col1);
        printf("\n\n");
    }
    
    else
        printf("Addition and Subtraction not possible");
 



    if (col1 != row2)
        printf("Multiplication not possible");

    else
    {
        mul_matrix(A, B, mul, row1, col2, col1);
        
        printf("Multiplication \n");
        dis_matrix(mul, row1, col2);
    }
}

