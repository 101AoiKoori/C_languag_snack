#include <stdio.h>
#include <stdlib.h>

int **generate(int numRows, int *returnSize, int **returnColumnSizes)
{
    int **ret = malloc(sizeof(int *) * numRows);
    *returnSize = numRows;
    *returnColumnSizes = malloc(sizeof(int) * numRows);
    for (int i = 0; i < numRows; ++i)
    {
        ret[i] = malloc(sizeof(int) * (i + 1));
        (*returnColumnSizes)[i] = i + 1;
        ret[i][0] = ret[i][i] = 1;
        for (int j = 1; j < i; ++j)
        {
            ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
        }
    }
    return ret;
}

int **generate(int numRows, int *returnSize, int **returnColumnSizes);

int main()
{
    int numRows = 5;       // 生成杨辉三角的行数
    int returnSize;         // 返回的行数
    int *returnColumnSizes; // 返回的每行的列数
    int **triangle = generate(numRows, &returnSize, &returnColumnSizes);

    // 输出生成的杨辉三角
    for (int i = 0; i < returnSize; i++)
    {
        for (int j = 0; j < returnColumnSizes[i]; j++)
        {
            printf("%d ", triangle[i][j]);
        }
        printf("\n");
    }

    // 释放内存
    for (int i = 0; i < returnSize; i++)
    {
        free(triangle[i]);
    }
    free(triangle);
    free(returnColumnSizes);

    return 0;
}
