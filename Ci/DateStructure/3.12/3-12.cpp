#include <bits/stdc++.h>

using namespace std;

int main()
{
    fstream file("output.txt", ios::out);
    char t;
    int sum[36];
    memset(sum, 0, sizeof(sum));
    if (file.fail())
    {
        cout << "open file fail";
        exit(0);
    }
    cout << "input a string end with '#': ";
    while (scanf("%c", &t) && t != '#')
    {
        if (t >= 'a' && t <= 'z')
        {
            sum[t - 'a']++;
        }
        else if (t >= '0' && t <= '9')
        {
            sum[t - '0' + 26]++;
        }
    }
    for (int i = 0; i < 36; i++)
    {
        if (i < 26)
            file << (char)('a' + i) << ':' << sum[i] << "\t";
        else
            file << (char)('0' + i - 26) << ':' << sum[i] << "\t";
        if(!((i + 1) % 6)) file << '\n';
    }
    file.close();
    return 1;
}
