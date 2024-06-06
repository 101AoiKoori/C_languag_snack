#include <stdio.h>
#include <string.h>

int fun(char *t)
{
    int len = strlen(t);
    int i;
    char before = t[0];
    char current;
    int flag = 1;
    if (len < 2)
    {
        return 0;
    }
    for (i = 1; t[i] != '\0'; i++)
    {
        current = t[i];
        if (before != current - 1)
        {
            flag = 0;
            break;
        }
        before = current;
    }
    return flag;
}

int main()
{
    char s[100];
    printf("请输入一段字符:");
    if (fgets(s, sizeof(s), stdin) != NULL)
    {
        size_t len = strlen(s);
        if (len > 0 && s[len - 1] == '\n')
        {
            s[len - 1] = '\0';
        }

        if (fun(s))
            printf("\n%s是连续的,1\n", s);
        else
            printf("\n%s不是连续的,0\n", s);
    }
    else
    {
        printf("输入错误");
    }
    return 0;
}