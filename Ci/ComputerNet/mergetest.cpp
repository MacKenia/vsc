#include <bits/stdc++.h>
#include <stdio.h>
#define N 5
using namespace std;

int main()
{
    FILE *output, *input;
    char tmpname[] = "t0";
    char buf[1024];
    output = fopen("merge.mp4","wb+");
    for (int i = 0; i < N; i++)
    {
        int size = 0, Ksize = 0, Rsize = 0;
        tmpname[1]++;
        input = fopen(tmpname, "rb");
        fseek(input, 0, SEEK_END);
        size = ftell(input);
        fseek(input, 0, SEEK_SET);
        cout << tmpname << ":" << size << endl;
        Ksize = size%1024 ? size/1024 + 1 : size/1024;
        Rsize = 1024;
        for (int j = 0; j < Ksize; j++)
        {
            if(i == N - 1 && j == Ksize - 1) Rsize = size%1024;
            memset(buf, 0, sizeof(buf));
            fread(&buf,Rsize,1,input);
            fwrite(&buf,Rsize,1,output);
        }
        fclose(input);
    }
    fclose(output);
    
    return 0;
}
