#include<stdio.h>
#include <stdlib.h>

int matrix(int **arr, int size);

void CramerRule(int **arr, int size1, int *answer, float *result);

int main()
{
    int answer[3] = {1, 6, 9};

    int arr[3][3] = {
        {1, 1, 1},
        {1, -1, 5},
        {-1, 1, 6}};

    // 将二维数组转换为指针数组
    int *arrPtr[3];
    for (int i = 0; i < 3; ++i)
    {
        arrPtr[i] = arr[i];
    }

    int size = 3;
    float result[3];

    CramerRule(arrPtr, size, answer, result);

    for (int l = 0; l < size; ++l)
    {
        printf("x%d = %lf\t", l + 1, result[l]);
    }
    printf("\n");

    return 0;
}

//计算行列式
int matrix(int **arr, int size)
{
    // 一阶行列式的处理
    if (size == 1)
    {
        return arr[0][0];
    }
    // 开辟二维数组空间
    int **p = (int **)malloc(size * sizeof(int *));

    for (int i = 0; i < size; ++i)
    {
        p[i] = (int *)malloc((size - 1) * sizeof(int));
    }

    int i, j, k;
    int sum = 0;
    // k用于计算代数余子式的正负号
    for (k = 0; k < size; ++k)
    {
        int m = 0;
        // 以第一行展开计算
        for (i = 1; i < size; ++i)
        {
            int n = 0;
            for (j = 0; j < size; ++j)
            {
                if (j != k)
                {
                    p[m][n++] = arr[i][j];
                }
            }
            ++m;
        }
        //判断正负号
        int sign = (k % 2 == 0) ? 1 : -1;
        // 用递归计算行列式的值
        sum += sign * arr[0][k] * matrix(p, size - 1);
    }
    //释放内存
    for (int i = 0; i < size; ++i)
    {
        free(p[i]);
    }
    free(p);

    return sum;
}

//克莱姆法则计算线性方程组
void CramerRule(int **arr, int size1, int *answer, float *result)
{
    int det = matrix(arr, size1);
    //判断特殊情况
    if (det == 0)
    {
        printf("行列式为空。\n");
        return;
    }
    //开辟二维数组空间
    int **n = (int **)malloc(size1 * sizeof(int *)); // arr
    for (int i = 0; i < size1; ++i)
    {
        n[i] = (int *)malloc((size1 - 1) * sizeof(int));
    }
    //a用于交替answer在行列式的不同列切换
    for (int a = 0; a < size1; ++a)
    {
        //复制数组
        for (int i = 0; i < size1; ++i)
        {
            for (int j = 0; j < size1; ++j)
            {
                n[i][j] = arr[i][j];
            }
        }
        //交换列的位置
        for (int k = 0; k < size1; ++k)
        {
            n[k][a] = answer[k];
        }
        //计算行列式
        int detAi = matrix(n, size1);
        printf("detAi=%d,det=%d\n", detAi, det);
        //计算方程组的解（但不知道为什么输出的是整形）
        result[a] = detAi / det;
    }
    //释放内存
    for (int i = 0; i < size1; ++i)
    {
        free(n[i]);
    }
    free(n);
}