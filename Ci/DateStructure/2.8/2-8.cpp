/**
 * 双向堆栈
 */
#include <bits/stdc++.h>
#define Max 100

using namespace std;

typedef struct
{
    int top[2], bot[2];
    int *v;
    int m;
} DblStack;

void insert(DblStack &d)
{
    int choice;
    int tmp;
    if(d.top[1] - d.top[0] == 1)
    {
        cout << "堆栈已满";
        return;
    }
    cout << "请输入数据：";
    cin >> tmp;
    cin.ignore();
    cout << "1. 在头栈插入" << endl
         << "2. 在尾栈插入" << endl
         << "> ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        d.v[d.top[0]++] = tmp;
        break;
    case 2:
        d.v[d.top[1]++] = tmp;
        break;
    }
    cout << "成功" << endl << endl;
}

void pop(DblStack d)
{
    int choice;
    cout << "1. 在头栈弹出" << endl
         << "2. 在尾栈弹出" << endl
         << "> ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        d.v[d.top[0]--] = 0;
        break;
    case 2:
        d.v[d.top[1]--] = 0;
        break;
    }
    cout << "成功" << endl << endl;
}

char gethead(DblStack d)
{
    for(int i = d.bot[0]; i < d.top[0]; i++)
    {
        cout << d.v[i] << " ";
    }
    return 0;
}

char gettail(DblStack d)
{
    for (int i = d.bot[1]; i > d.top[1]; i--)
    {
        cout << d.v[i];
    }
    return 0;
}

void info(DblStack d)
{
    cout << "剩余容量: " << d.top[1] - d.top[0] + 1 << endl
    << "头栈栈顶指针位置为：" << d.top[0] << endl
    << "头栈数据为：" << gethead(d) << endl
    << "尾栈栈顶指针位置为：" << d.top[1] << endl
    << "尾栈数据为：" << gettail(d) << endl << endl;
}

int main()
{
    // initial DoubleStack
    DblStack DStack;
    int stack[Max];
    DStack.v = stack;
    DStack.top[0] = 0;
    DStack.bot[0] = 0;
    DStack.bot[1] = Max - 1;
    DStack.top[1] = Max - 1;
    DStack.m = Max;

    // Operations
    bool flag = true;
    int choice;
    cout << "当前栈可容纳的最大元素个数为：" << Max << endl;
    while (flag)
    {
        cout << "请选择操作：" << endl
             << "1. 查看当前状态" << endl
             << "2. 插入数据" << endl
             << "3. 弹出数据" << endl
             << "4. 退出" << endl
             << "> ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            info(DStack);
            break;
        case 2:
            insert(DStack);
            break;
        case 3:
            pop(DStack);
            break;
        case 4:
            flag = false;
            break;
        }
    }

    return 1;
}
