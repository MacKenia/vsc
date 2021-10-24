#include <bits/stdc++.h>

#ifndef LIST_H
#define LIST_H

using namespace std;

template<typename T>
class LTT
{
public:
    T *addA(T *p, T *q);
    T *addB(int n,T *p, T *q);
    T *push(T *p,T *q);
    T *shift(T *p, T *q);
    T *delA(T *p, T *q);
    T *delB(int n, T *q);
    T *pop(T *p);
    T *unshift(T *p);
    void del(T *p);
    T *searchA(int tar, T *p);
};

template<typename T>
T *LTT<T>::addA(T *p, T *q) //add q after p
{
    q->next = p->next;
    p->next = q;
    return p->next;
}

template<typename T>
T *LTT<T>::addB(int n,T *p, T *q) // add q before p
{
    for (int i = 0; i < n - 1; i++)
        p = p->next;
    q->next = p->next;
    p->next = q;
    return p->next;
}

template<typename T>
T *LTT<T>::push(T *p, T *q) // push q into stack
{
    p->next = q;
    return q;
}

template<typename T>
T *LTT<T>::shift(T *p, T *q) // push q before queue
{
    q->next = p;
    return p;
}

template<typename T>
T *LTT<T>::delA(T *p, T *q) // delete q from list
{
    p->next = q->next;
    delete q;
    return p;
}

template<typename T>
T *LTT<T>::delB(int n, T *q) // delete nth one form list
{
    T *p = NULL;
    for(int i = 0; i < n - 1; i++)
        q = q->next;
    p = q;
    q = q->next;
    p->next = q->next;
    delete q;
    return p;
}

template<typename T>
T *LTT<T>::pop(T *p) // pop front out of stack
{
    T *q = p;
    p = p->next;
    delete q;
    return p;
}

template<typename T>
T *LTT<T>::unshift(T *p) // delete first one form queue
{
    T *q = p->next;
    delete p;
    return q;
}

template<typename T>
T *LTT<T>::searchA(int n, T *q) // find nth node and return it
{
    for (int i = 0; i < n; i++)
        q = q->next;
    return q;
}

template<typename T>
void LTT<T>::del(T *p) // delete whole List
{
    if(p->next == NULL)
    {
        delete p;
        return;
    }
    T *q = p;
    p = q->next;
    for(; q->next != NULL; q = p, p = p->next)
    {
        delete q;
    }
    delete p;
}
#endif