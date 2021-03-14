#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a(int a, int b);
    int b(int a, int b);
    int c(int a, int b);
    int (*p)(int, int);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char num1, num2, num3;
        
        cout << (*p)(num2, num3) << endl;
    }
    return 0;
}

int a(int a, int b)
{
    return a+b;
}

int b(int a, int b)
{
    return a-b;
}

int c(int a, int b)
{
    return a*b;
}
