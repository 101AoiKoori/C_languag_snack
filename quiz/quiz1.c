#include <stdio.h>
int main()
{
    int i, j=0, n = 0;
    
    int a[4][4] = {
        {1, 3, 5, 7},
        {9, 11, 13, 15},
        {17, 19, 21, 23},
        {0, 0, 0, 0}
        };

    int(*p)[4] = a;

    for (i = 0; i < 4; i++){
        for (j = 0; j < 4; j++)
        {
            n = *(*(p)+j);
            printf("i=%d,j=%d,n=%d\n", i, j,n);

        }
    }
}