#include<stdio.h>

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
    struct word *p, *q, head;
    char t;
    p = &head;
    while (~scanf("%d", &t))
    {
        q = (struct word *) malloc(sizeof(struct word));
        en = behind;
        if (t == '[')
        {
            en = front;
            p = &head;
        }
        else if (t == ']')
        {
            en = behind;
            p = q;
        }
        else
        {
            q -> w = t;
            void (*en)(p, q);
        }
    }
    
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
