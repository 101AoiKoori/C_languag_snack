#include<stdio.h>

int main(){
    char a[3][3] = {'a', 'b', 'c', 'd', 'e', 'f', '\0', 'h'};

    char(*p)[3] = a;
    char *t;
    t = (char*)p+3;
    printf("%s", t);
}
