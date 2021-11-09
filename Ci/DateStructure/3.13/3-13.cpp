#include <bits/stdc++.h>

using namespace std;

void insert(char* s, char* t, int pos)
{
    int i, j;
    for (i = 0; s[i] != '\0'; i++); //get length of each string
    for (j = 0; t[j] != '\0'; j++);
    for ( ; i >= pos; i--) // move char to get enough space
    {
        s[j + i - 1] = s[i - 1];
    }
    for(i = 0; i < j; i++) // insert t into s
    {
        s[i + pos - 1] = t[i];
    }
}

int main()
{
    char a[6] = "ad";
    char b[3] = "bc";
    insert(a, b, 2);
    cout << a << endl;
    return 0;
}