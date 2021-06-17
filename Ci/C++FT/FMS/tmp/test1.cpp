#include <bits/stdc++.h>

using namespace std;

char* intTochar(char *s,int a)
{
    for(int i = 0; i < 3; i++, a/=10)
    {
        s[3-i] = '0' + a % 10;
    }
    s[4] = '\0';
    return s;
}

int main()
{
    int a;
    char s[4];
    cin >> a;
    cout << intTochar(s,a) << endl;
    return 0;
}
