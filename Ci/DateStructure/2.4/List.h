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
    T *delA(T *p, T *q);
    T *delB(int n, T *q);
    T *searchA(int tar, T *p);
};

template<typename T>
T *LTT<T>::addA(T *p, T *q)
{
    q->next = p->next;
    p->next = q;
    return p->next;
}

template<typename T>
T *LTT<T>::addB(int n,T *p, T *q)
{
    for (int i = 0; i < n; i++)
        p = p->next;
    q->next = p->next;
    p->next = q;
    return p->next;
}

template<typename T>
T *LTT<T>::delA(T *p, T *q)
{
    p->next = q->next;
    dellet(q);
    return p;
}

template<typename T>
T *LTT<T>::delB(int n, T *q)
{
    T *p;
    for (int i = 0; i < n - 1; i++)
        q = q->next;
    p = q;
    q = q->next;
    p->next = q->next;
    dellet(q);
    return p;
}

template<typename T>
T *LTT<T>::searchA(int n, T *q)
{
    for (int i = 0; i < n; i++)
        q = q->next;
    return q;
}

#endif