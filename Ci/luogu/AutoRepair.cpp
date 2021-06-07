#include<bits/stdc++.h>
using namespace std;

int main()
{
    char t;
    while(scanf("%c", &t) && t != '\n')
    {
        if(t>='a'&&t<='z') t-=32;
        printf("%c", t);
    }
    return 0;
}

