/**
 * 在一维数组a中顺序查找某个值等于e的元素，并返回其所在的位置
 * for(i = 0; i < n; i++)
 *      if(a[i] == e) return i + 1;
 * return 0;
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[1000];
    int e;
    cin >> e;
    for(int i = 0; i < 1000; i++)
    {
        a[i] = rand() % 100;
    }
    for(int i = 0; i < 1000; i++)
    {
        if(a[i] == e) cout << i + 1 << " " << a[i] << endl;
    }
    return 1;
}
