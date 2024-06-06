#include <stdio.h>

void bubble(int a[], int sz)
{
    int i, j;
    int tmp;
    for (i = 0; i < sz - 1; i++)
    {
        for (j = 0; j < sz - 1 - i; j++)
        {
            if (a[j] < a[j + 1])
            {
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
}

int main()
{
    int i, arr[10] = {22, 11, 33, 66, 44, 55, 77, 99, 88, 100};
    i = sizeof(arr) / sizeof(arr[0]);
    
    for (int f = 0; f < 10; f++)
        printf("%d ", arr[f]);
    bubble(arr, i);
    printf("\n,i=%d\n",i);
    for (int f = 0; f < 10; f++)
        printf("%d ", arr[f]);
    return 0;
}