#include <bits/stdc++.h>

using namespace std;

int main()
{
    int key;
    char t[100];
    scanf("%d", &key);
    key %= 26;
    cin >> t;
    for(int i = 0; t[i] != '\0'; i++)
    {
        int j;
        j = t[i] + key;
        // t[i] += key;
        if(j > 'z') j -= 26;
        t[i] = j;
    }
    cout << t << endl;
    return 0;
} 
