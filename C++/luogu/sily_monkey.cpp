#include <bits/stdc++.h>

using namespace std;

int main()
{
    bool ju(int n);
    int arr[26] = {0}, maxn = 0, minn = 99;
    char t;
    while (scanf("%c", &t) && t != '\n')
    {
        arr[t-'a'] ++;
    }
    for(int i = 0; i < 26; i++)
    {
        if(arr[i] > maxn) maxn = arr[i];
        if(arr[i] != 0 && arr[i] < minn) minn = arr[i];
    }
    if(ju(maxn-minn)) printf("Lucky Word\n%d",maxn-minn);
    else printf("No Answer \n0");
    return 0;
}

bool ju(int n)
{
    if(n == 0||n == 1) return false;
    for(int i = 2; i < sqrt(n); i++)
    {
        for(int j = 2; j < sqrt(n); j++)
        {
            if(n == i * j) return false;
        }
    }
    return true;
}
