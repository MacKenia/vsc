#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int main()
{
    fstream file;
    char Data[40];
            file.open("data.dat",ios::binary | ios::in);
    while (true)
    {
        file.read((char *)Data,sizeof(Data));
        if (file.fail()) break;
        for(int i = 0; i < 40; i++) Data[i] -= 1;
        for (int i = 0; i < 40; i++) cout <<Data[i] ;
        cout << endl;
        Sleep(1000);
    }
    return 0;
}
