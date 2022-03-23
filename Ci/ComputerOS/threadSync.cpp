#include <bits/stdc++.h>
#include <thread>
#include <mutex>
#include <windows.h>

using namespace std;

struct Q
{
    string name;
    int num;
    int size;
    Q() : name(), num(0), size(10) {};
};

void Producer(Q *q, mutex *m)
{
    q->name = "Producer";
    while (true)
    {
        if(m->try_lock())
        {
            cout << q->name << "生产: " << ++q->num << endl;
            m->unlock();
        }
        else
        {
            cout << "生产停止" << endl;
        }
        Sleep(100);
    }
}

void Consumer(Q *q, mutex *m)
{
    q->name = "Consumer";
    while (true)
    {
        if(m->try_lock())
        {
            if(q->num > 0)
            {
                cout << q->name << "消费: " << q->num-- << endl;
            }
            else
            {
                cout << "商品为0, 消费停止" << endl;
            }
            m->unlock();
        }
        else
        {
            cout << "正在生产, 消费停止" << endl;
        }
        Sleep(100);
    }
    
}

int main()
{
    Q q;
    mutex m;
    thread t1(Producer, &q, &m);
    thread t2(Consumer, &q, &m);
    t1.join();
    t2.join();
    return 0;
}
