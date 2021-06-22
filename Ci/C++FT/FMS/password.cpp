#include <bits/stdc++.h>

using namespace std;

char fuck()
{
    cout << "asdfjlasldfjasldjfk";
    return 0;
}

int main()
{
    cout << fuck << endl;
    cout << "┌─────────────────────┤ LOGIN IN ├────────────────────┐" << endl;
    cout << "│                                                     │" << endl;
    cout << "│                        请登录                       │" << endl;
    cout << "│                                                     │" << endl;
    cout << "│         用户名：__________________________          │" << endl;
    cout << "│                                                     │" << endl;
    cout << "│           密码：__________________________          │" << endl;
    cout << "│                                                     │" << endl;
    cout << "│                                                     │" << endl;
    cout << "│               <登录>             <注册>             │" << endl;
    cout << "│                                                     │" << endl;
    cout << "└─────────────────────────────────────────────────────┘" << endl;
    struct frame
    {
        char lt[4] = "┌";
        char rt[4] = "┐";
        char ml[4] = "┤";
        char mr[4] = "├";
        char lb[4] = "└";
        char rb[4] = "┘";
        char row[4] = "─";
        char col[4] = "│";
    }fr;
    char title[] = "Hello Hi ok.";
//定义一个宽55高11的窗口
    int w = 55, h = 11;
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            bool flag = true;
            // 第一行
            if(i == 0 && j == 0)
            {
                cout << fr.lt;
                flag = false;
            }
             else if(i == 0 && j > 0 && j < w-1)
            {
                cout << fr.row;
                flag = false;
            }
            else if(i == 0 && j == w-1)
            {
                cout << fr.rt;
                flag = false;
            }
            // 最后一行
            if(i == h-1 && j == 0)
            {
                cout << fr.lb;
                flag = false;
            }
            else if(i == h-1 && j > 0 && j < w-1)
            {
                cout << fr.row;
                flag = false;
            }
            else if(i == h-1 && j == w-1)
            {
                cout << fr.rb;
                flag = false;
            }
            // 其他行
            if((i > 0 && i < h-1)&&(j == 0 || j == w-1))
            {
                cout << fr.col;
                flag = false;
            }
            if(flag) cout << ' ';
        }
        cout << endl;
    }
    return 0;
}


