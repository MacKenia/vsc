#include<stdio.h>
#include<stdlib.h>
typedef struct array Int;

struct array
{
    struct array *previous;
    int number;
    struct  array *next;
};

int main()
{
    int swap(Int *a, Int *b);
    int connect(Int *a, Int *b);
    int i, j, k, t, sum = 0;
    Int array, *p = &array, *n;
    while(~scanf("%d", &i)&&i!=0)
    {
        for(j = 0; j < i; j++)
        {
            getchar();
            scanf("%d", &t);
            n = (struct array *)malloc(sizeof(Int));
            n->number = t;
            connect(p, n);
            p = p->next;
        }
        p = &array;
        for(j = 0; j < i; j++)
        {
            p = &array;
            for(k = 0; k < i - j - 1; k++)
            {
                p = p->next;
                if (p->number > (p->next)->number)
                {
                    swap(p, p->next);
                    sum++;
                }
                
            }
        }
        printf("*%d\n", sum);
        sum = 0;
        p = &array;
    }
    return 0;
}

int swap(Int *a, Int *b)
{
    int t;
    t = a->number;
    a->number = b->number;
    b->number = t;
    return 0;
}

int connect(Int *a, Int *b)
{
    a->next=b;
    b->previous = a;
    b->next = NULL;
    return 0;
}
