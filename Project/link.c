#include <stdio.h>
#include <stdlib.h>

typedef struct link
{
    int i;
    struct link *next;
} link;

int main(void)
{
    link a, b, c, d, e;
    a.i = 0;
    b.i = 4;
    c.i = 6;
    d.i = 8;
    e.i = 10;

    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = NULL;

    link *head = &a;

   
    link *finalnode = (link *)malloc(sizeof(link));
    if (finalnode == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    finalnode->next = NULL;
    finalnode->i = 0; 

    while (head->next != NULL)
    {
        head = head->next;
    }

    head = &a; 

    while (head)
    {
        printf("i=%d\thead=%p\tnext=%p\n", head->i, (void *)head, (void *)head->next);
        head = head->next;
    }

    free(finalnode); 

    return 0;
}