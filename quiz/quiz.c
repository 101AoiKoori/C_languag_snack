#include <stdio.h>
#define N 4
void fun(int a[][N], int b[], int flag)
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        b[i] = a[0][i];
        for (j = 1; j < N; j++)
            if (flag ? (b[i] > a[j][i]) : (b[i] < a[j][i]))
                b[i] = a[j][i];
    }
}

int main()
{
    int x[N][N] = {{1, 2, 3, 4},
                   {5, 6, 7, 8},
                   {9, 10, 11, 12},
                   {13, 14, 15, 16}};
    int y[N], i;

    fun(x, y, 1);
    for (i = 0; i < N; i++)
        printf("%d,", y[i]);

    printf("\n");

    fun(x, y, 0);
    for (i = 0; i < N; i++)
        printf("%d,", y[i]);
    printf("\n");

}
