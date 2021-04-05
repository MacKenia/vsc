#include <bits/stdc++.h>

using namespace std;

int main()
{
    char a[12][20];
    for (int i = 0; i < 12; i++)
    {
        cin >> a[i];
        a[i][0] = toupper(a[i][0]);
    }
    for (int i = 0; i <12; i++)
    {
        cout << "\"" << a[i] << "\", ";
    }
    return 0;
}
