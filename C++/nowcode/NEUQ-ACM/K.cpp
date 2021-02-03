#include<bits/stdc++.h>
using namespace std;

void unt(char *w, int *n)
{
    for (int i = 0; i < 4; i++, w++, n++)
    {
        for (int j = 1; j <= *n; j++)
        {
            (*w)++;
            if(*w == 'Z'+1) *w = 'b';
            else if(*w == 'z'+1) *w = 'B';
        }
    }
    swap(*(w-1),*(w-4));
    swap(*(w-2),*(w-3));
}

int main()
{
    char s[33], w[17];
    int n[16];
    cin >> s;
    for (int j=0, k=0, i = 0; i < 32; i++)
    {
        if(s[i]>='A'&&s[i]<='Z'||s[i]>='a'&&s[i]<='z') w[j++] = s[i];
        else if(s[i]>='0'&&s[i]<='9') n[k++] = s[i]-48;
    }
    w[16] = '\0';
    for(int i = 0; i < 16; i+=4) unt(&w[i], &n[i]);
    cout << w;
    return 0;
}

