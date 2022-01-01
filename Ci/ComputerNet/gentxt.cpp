#include <bits/stdc++.h>

using namespace std;

int main()
{
    fstream t;
    t.open("test.txt", ios::app);
    for (int i = 0; i < 1024*2; i++)
    {
        t << setw(4) << right << setfill('0')<< i << "\n";
    }
    
    return 0;
}
