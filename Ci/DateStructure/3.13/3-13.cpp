#include <bits/stdc++.h>

using namespace std;

void insert(char* s, char* t, int pos)
{
    int i, j;
    for (i = 0; s[i] != '\0'; i++);
    for (j = 0; s[j] != '\0'; j++);
    for ( ; i > pos; i--)
    {
        s[i] = s[i - j];
    }
    for(i = 0; i < j; i++)
    {
        s[i + pos] = t[i];
    }   
}

int main()
{
    char a[6] = "ad";
    char b[3] = "bc";
    insert(a, b, 1);
    cout << a;
    return 0;
}