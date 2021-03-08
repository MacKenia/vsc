/**
 * 先排序，再求中值
 */
#include <bits/stdc++.h>

using namespace std;

int main()
{
    float arr[80];
    int len;
    int culCen(float *p, int len);
    cout << "输入个数：";
    cin >> len;
    for (int i = 0; i < len; i++) cin >> arr[i];
    culCen(arr,len);
    return 0;
}

int culCen(float *p, int len)
{
    sort(p,p+len-1);
    if(len%2 == 0) printf("%.1f",(*(p+len/2-1) + *(p+len/2))/2);
    else printf("%.0f",*(p+len/2));
    return 1;
}
