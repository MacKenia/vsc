#include<stdio.h>

struct word
{
    char w;
    struct word *next;
};

int main()
{

    return 0;
}

void front(struct word *p,struct word *h)
{
    p->next = h;
    h = p;
}

void behind(struct word *p,struct word *l)
{
    l->next = p;
    p->next = NULL;
}
