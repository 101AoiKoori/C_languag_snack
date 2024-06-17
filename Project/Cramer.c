#include <stdio.h>
#include <stdlib.h>

double matrix(double **arr, int size);
void CramerRule(double **arr, int size1, double *answer, double *result);

int main()
{
    double answer[4] = {1, 6, 9, 12};
    int size = 4;
    double arr[4][4] = {
        {1, 1, 1, 2},
        {1, -1, 5, 6},
        {-1, 1, 6, 8},
        {1, 2, 3, 4}};

    // 将二维数组转换为指针数组
    double *arrPtr[4];
    for (int i = 0; i < size; ++i)
    {
        arrPtr[i] = arr[i];
    }
    double result[4];

    CramerRule(arrPtr, size, answer, result);

    for (int l = 0; l < size; ++l)
    {
        printf("x%d = %.4f\t", l + 1, result[l]);
    }

    printf("\n");

    return 0;
}

// 计算行列式
double matrix(double **arr, int size)
{
    // 一阶行列式的处理
    if (size == 1)
    {
        return arr[0][0];
    }

    // 开辟二维数组空间
    double **p = (double **)malloc((size - 1) * sizeof(double *));
    if (p == NULL)
    {
        fprintf(stderr, "内存分配失败\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size - 1; ++i)
    {
        p[i] = (double *)malloc((size - 1) * sizeof(double));
        if (p[i] == NULL)
        {
            fprintf(stderr, "内存分配失败\n");
            // 释放已分配的内存
            for (int j = 0; j < i; ++j)
            {
                free(p[j]);
            }
            free(p);
            exit(EXIT_FAILURE);
        }
    }

    double sum = 0;
    // k用于计算代数余子式的正负号
    for (int k = 0; k < size; ++k)
    {
        int m = 0;
        // 以第一行展开计算
        for (int i = 1; i < size; ++i)
        {
            int n = 0;
            for (int j = 0; j < size; ++j)
            {
                if (j != k)
                {
                    p[m][n++] = arr[i][j];
                }
            }
            ++m;
        }
        // 判断正负号
        int sign = (k % 2 == 0) ? 1 : -1;
        // 用递归计算行列式的值
        sum += sign * arr[0][k] * matrix(p, size - 1);
    }
    // 释放内存
    for (int i = 0; i < size - 1; ++i)
    {
        free(p[i]);
    }
    free(p);

    return sum;
}

// 克莱姆法则计算线性方程组
void CramerRule(double **arr, int size1, double *answer, double *result)
{
    double det = matrix(arr, size1);
    // 判断特殊情况
    if (det == 0)
    {
        printf("行列式为空。\n");
        return;
    }
    // 开辟二维数组空间
    double **n = (double **)malloc(size1 * sizeof(double *)); // arr
    if (n == NULL)
    {
        fprintf(stderr, "内存分配失败\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size1; ++i)
    {
        n[i] = (double *)malloc(size1 * sizeof(double));
        if (n[i] == NULL)
        {
            fprintf(stderr, "内存分配失败\n");
            // 释放已分配的内存
            for (int j = 0; j < i; ++j)
            {
                free(n[j]);
            }
            free(n);
            exit(EXIT_FAILURE);
        }
    }
    // a用于交替answer在行列式的不同列切换
    for (int a = 0; a < size1; ++a)
    {
        // 复制数组
        for (int i = 0; i < size1; ++i)
        {
            for (int j = 0; j < size1; ++j)
            {
                n[i][j] = arr[i][j];
            }
        }
        // 交换列的位置
        for (int k = 0; k < size1; ++k)
        {
            n[k][a] = answer[k];
        }
        // 计算行列式
        double detAi = matrix(n, size1);
        printf("detAi=%.2f, det=%.2f\n\n", detAi, det);
        // 计算方程组的解
        result[a] = detAi / det;
    }
    // 释放内存
    for (int i = 0; i < size1; ++i)
    {
        free(n[i]);
    }
    free(n);
}