/**
 * 两端都可以入队和出队的循环队列
 * 写出循环队列的类型定义
 * 写出“从队尾删除” 和 “从队头插入”的算法
 */
#include <bits/stdc++.h>
#define N 10

using namespace std;

struct iQueue
{
    int *v;
    int front;
    int rear;
    int operator++()
    {
        int tmp = front;
        front=(front+1+N)%N;
        return tmp;
    }

    int operator--()
    {
        return front=(front-1+N)%N;
    }

    int operator++(int)
    {
        int tmp = rear;
        rear=(rear+1+N)%N;
        return tmp;
    }

    int operator--(int)
    {
        return rear=(rear-1+N)%N;
    }

    void push(int a)
    {
        v[(*this)++] = a;
    }

    void pop()
    {
        v[(*this)--] = 0;
    }

    void shift(int a)
    {
        v[--(*this)] = a;
    }

    void unshift()
    {
        v[++(*this)] = 0;
    }
};

void show(iQueue sq)
{
    for(int i = 0; i < N; i++) cout << i+1 << " ";
    cout << endl;
    for(int i = 0; i < N; i++)
    {
        cout << sq.v[i] << " ";
    }
    cout << endl << endl;
}

int main()
{
    iQueue sq;
    sq.v = new int[N];
    sq.front = 0;
    sq.rear = 0;
    for(int i = 0; i < N; i++)
    {
        sq.push(i);
    }
    sq.push(1);
    show(sq);
    sq.push(2);
    show(sq);
    sq.pop();
    sq.shift(3);
    show(sq);
    for(int i = 0; i < N; i++)
    {
        sq.unshift();
    }
    show(sq);
    return 1;
}