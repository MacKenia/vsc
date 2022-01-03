#include <bits/stdc++.h>

#define N 5
using namespace std;

int main()
{
    FILE *output, *input;
    // fstream Input, Output;
    char tmpname[] = "t0";
    char buf[1024];
    output = fopen("merge.mp4","wb+");
    // Output.open("merge.txt",ios::binary | ios::out);
    for (int i = 0; i < N; i++)
    {
        int size = 0, Ksize = 0, Rsize = 0;
        tmpname[1]++;

        input = fopen(tmpname, "rb");
        fseek(input, 0, SEEK_END);
        size = ftell(input);
        fseek(input, 0, SEEK_SET);

        // Input.open(tmpname,ios::in | ios::binary);
        // Input.seekg(0,ios::end);
        // size = Input.tellg();
        // Input.seekg(0);

        cout << tmpname << ":" << size << endl;
        Ksize = size%1024 ? size/1024 + 1 : size/1024;
        Rsize = 1024;
        for (int j = 0; j < Ksize; j++)
        {
            if(i == N - 1 && j == Ksize - 1 && size%1024) Rsize = size%1024;
            memset(buf, 0, sizeof(buf));

            fread(&buf,Rsize,1,input);
            fwrite(&buf,Rsize,1,output);
            // Input.read(buf,Rsize);
            // Output.write(buf,Rsize);
        }
        fclose(input);
        // Input.close();
    }
    fclose(output);
    // Input.close();
    return 0;
}
