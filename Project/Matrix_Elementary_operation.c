#include<stdio.h>
#define size 3

void Line(int arr[][size],int mode ,int num1, int num2)
{
    int sign = (mode % 2 == 0) ? 1 : -1;
    if(!sign)
    {
        for (int j = 0; j < size; ++j)
        {
            int temp = arr[num1][j];
            arr[num1][j] = arr[num2][j];
            arr[num2][j] = temp;
        }
    }
    else
    {
        for (int j = 0; j < size; ++j)
        {
            int temp = arr[j][num1];
            arr[j][num1] = arr[j][num2];
            arr[j][num2] = temp;
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
            k = 2;
            break;
        default:
            printf("输入错误");
            break;
    }

    Line(matrix,k ,1, 2); 

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