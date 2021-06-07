#include<stdio.h>
#include<stdlib.h>

struct word
{
    char w;
    struct word *next;
};

int main()
{
    void front(struct word *p, struct word *ah);
    void behind(struct word *p, struct word *l);
    void (*en)(struct word*, struct word*);
    struct word *p, *q, head, *last;
    char t;
    p = &head;
    en = behind;
    while (~scanf("%c", &t))
    {
        if (t == '[')
        {
            en = front;
            last = p;
            p = &head;
            continue;
        }
        else if (t == ']')
        {
            en = behind;
            p = last;
            continue;
        }
        else
        {
            q = (struct word *) malloc(sizeof(struct word));
            q->w = t;
            (*en)(p, q);
        }
        p = q;
    }
    for(p = &head; (p-1)->next != NULL; p = p->next) printf("%c", p->w);
    return 0;
}

void front(struct word *p,struct word *ah)
{
    ah->next = p->next;
    p->next = ah;
}

void behind(struct word *p,struct word *l)
{
    p->next = l;
    l->next = NULL;
}
