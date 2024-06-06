#include <stdio.h>
int funa(int a, int b) { 
    return a + b; 
}

int funb(int a, int b) { 
    return a - b; 
}

int sss(int (*t)(), int x, int y) { 
    return ((*t)(x, y)); 
}

int main()
{
    int x;
    x = sss(funa, 9, 3);
    x += sss(funb, 8, 3);
    printf("%d\n", x);
    
}