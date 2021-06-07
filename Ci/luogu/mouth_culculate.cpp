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
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        char num2, num3;
        if(cin.peek()=='a')
        {
            p = a;
            cin.ignore();
        }
        else if(cin.peek()=='b')
        {
            p = b;
            cin.ignore();
        }
        else if(cin.peek()=='c')
        {
            p = c;
            cin.ignore();
        }
        cin >> num2 >> num3;
        cout << num2 << '+' << num3 << '=' << (*p)(num2, num3) << endl;
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
