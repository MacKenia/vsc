#include <bits/stdc++.h>

using namespace std;

int main()
{
    char filename[] = "data.dat";
    char s[] = "alsdfjlkasdf";
    char Data[40];
    fstream f(filename,ios::binary | ios::in | ios::out);
    cin.getline(Data,20);
    cin.getline(&Data[20],20);
    f.seekg(0L,ios::end);
    f.write((char*)Data,sizeof(Data));
    f.close();
    return 0;
}
