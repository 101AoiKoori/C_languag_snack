#include<stdio.h>
#include <stdlib.h>
#define size 3

void SwapTransformation(int arr[][size],int model ,int paramenter1, int paramenter2)
{
    if(model)
    {
        for (int j = 0; j < size; ++j)
        {
            int temp = arr[paramenter1][j];
            arr[paramenter1][j] = arr[paramenter2][j];
            arr[paramenter2][j] = temp;
        }
    }
    else
    {
        for (int j = 0; j < size; ++j)
        {
            int temp = arr[j][paramenter1];
            arr[j][paramenter1] = arr[j][paramenter2];
            arr[j][paramenter2] = temp;
        }
    }
}

void kMultiply(int arr[][size], int model,int paramenter1, int k)
{
    if(model){
        for (int i = 0; i < size;++i){
            arr[paramenter1-1][i] *= k;
        }
    }else{
        for (int i = 0; i < size; ++i)
        {
            arr[i][paramenter1-1] *= k;
        }
    }

}

void col_operation(double matrix[][size], int rows, int cols, int src_col, int dest_col, double l,int model)
{
   if(model){
        for (int j = 0; j < cols; j++)
        {
            matrix[dest_col][j] += l * matrix[src_col][j];
        }
    }else{
        for (int i = 0; i < rows; i++){
            matrix[i][dest_col] += l * matrix[i][src_col];

        }
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

    printf("行变换按1,列变换按2\n");
    int a,k;
    scanf("%d", &a);
    switch (a)
    {
        case 1:
            k = 1;
            break;
        case 2:
            k = 0;
            break;
        default:
            printf("输入错误");
            break;
    }

    //SwapTransformation(matrix,k ,1, 2);
    kMultiply(matrix, k, 1, 2);
    
    printf("\n变换后的矩阵:\n");

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