#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream file("output.txt", ios::out);
    char t;
    int sum[36];
    if(file.fail())
    {
        cout << "open file fail";
        exit(0);
    }
    while(t = getchar() && t != '#')
    {
        if(t >= 'A' && t <= 'Z')
        {
            sum[t-'A']++;
        }
        else if(t >= '0' && t <= '9')
        {
            sum[t-'0']++;
        }
        for(int i = 0; i < 36; i++)
        {
            if(i < 26)
                file << (char)('A'+i) << ':' << sum[i] << "\t";
            else
                file << (char)('0'+i) << ':' << sum[i] << "\t";
        }
        file << '\n';
    }
    file.close();
    return 1;
}
