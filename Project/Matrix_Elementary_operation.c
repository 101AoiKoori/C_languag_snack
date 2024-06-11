#include<stdio.h>
#define size 3

void Line(int arr[][size], int line1, int line2)
{
    for (int j = 0; j < size; ++j)
    {
        int temp = arr[line1][j];
        arr[line1][j] = arr[line2][j];
        arr[line2][j] = temp;
    }
}

int main()
{
    int matrix[size][size] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    for (int j = 0; j < size; ++j)
    {
        for (int i = 0; i < size; i++)
        {
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }

    Line(matrix, 1, 2); 

    printf("\n交换后的矩阵:\n");

    for (int j = 0; j < size; ++j)
    {
        for (int i = 0; i < size; i++)
        {
            printf("%d ", matrix[j][i]);
        }
        printf("\n");
    }

    return 0;
}