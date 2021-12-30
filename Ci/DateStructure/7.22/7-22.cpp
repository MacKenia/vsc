#include <bits/stdc++.h>

using namespace std;

int halfsearch(int tar, int a[], int beg, int end)
{
    if(beg < end)
    {
        if(a[(beg+end)/2] >= tar) return halfsearch(tar, a, beg, (beg+end)/2);
        else return halfsearch(tar, a, ((beg+end)/2)+1, end);
    }
    else
    {
        if(a[beg] == tar) return beg;
    }
    return -1;
}

int main()
{
    int arr[] = {5, 16, 20, 27, 30, 36, 44, 55, 60, 67, 71};
    int tmp, pos;
    cout << "输入需要查找的值: ";
    cin >> tmp;
    pos = halfsearch(tmp, arr, 0, 11);
    cout << "在数组中的位置: " << pos << ",值为: " <<arr[pos] << endl;
    return 0;
}
