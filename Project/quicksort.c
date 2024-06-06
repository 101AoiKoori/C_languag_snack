#include <stdio.h>
#include <stdlib.h>
#define N 10

int func(int *a, int s, int e)
{
    int ss = s, se = e, store; // 储存开始和结束的位置
    int nt = s;                
    store = a[nt];
    if (e - s <= 0)
        return 0;

    while (s != e)
    {
        while (s != e)
        {
            if (store > a[e])
            {
                a[s] = a[e];
                s++;
                break;
            }
            e--;
        }

        while (s != e)
        {
            if (store < a[s])
            {
                a[e] = a[s];
                e--;
                break;
            }
            s++;
        }
    }
    // printf("开始递归！");
    a[s] = store;
    nt = s; // 定位Pivot
    func(a, nt + 1, se);
    func(a, ss, nt - 1);
    return 0;
}
 
 
int main()
{
    int i = 0;
    int a[10] = {1, 10, 5, 6, 2, 3, 4, 9, 8, 7};
    func(a, 0, N - 1);
    while (i < N)
        printf("%d\n", a[i++]);
    return 0;
}