#include <bits/stdc++.h>
#include <windows.h>

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

int p()
{
    if(AllocConsole())
    cout << "mother fucker";
    getchar();
    return 0;
}


int main()
{
    char s[10];
    cin.getline(s,10);
    cout << s << endl;
    return 0;
}
