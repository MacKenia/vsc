#include <bits/stdc++.h>
#define N 5
using namespace std;

int main()
{
    FILE *input = fopen("input.mp4", "rb");
    // FILE *output = fopen("output.txt","wb+");
    int Bsize, Ksize, Lsize, Fsize;
    char buf[1024];
    char tmpname[] = "t1";

    fseek(input, 0, SEEK_END);
    Bsize = ftell(input);
    fseek(input, 0, SEEK_SET);


    if (Bsize <= 1024)
        return 0;

    Ksize = Bsize / 1024;
    Fsize = Ksize / N * N / N;
    Lsize = Bsize - Fsize * 1024 * (N - 1);

    // log
    cout << "总大小(B): " << Bsize << endl;
    cout << "总大小(KB): " << Ksize << "\t" << "分片大小(KB): " << Fsize << "\t";
    cout << "最后一片的大小(B): " << Lsize << endl;

    for (int i = 0; i < N; i++)
    {
        // break;
        int flen = Ksize / N;
        int len = 1024;

        FILE *op = fopen(tmpname, "wb+");
        FILE *p = input;

        if (i == N - 1)
        {
            if (Lsize % 1024 == 0)
                flen = Lsize / 1024;
            else
                flen = Lsize / 1024 + 1;
            cout << Lsize/1024 << ", " << flen << endl;
        }

        fseek(p, i * Fsize * 1024, SEEK_SET);

        for (int j = 0; j < flen; j++)
        {
            memset(buf, 0, sizeof(buf));
            if (i == N - 1 && j == flen - 1 && Lsize % 1024)
            {
                len = Lsize % 1024;
                cout << len << endl;
            }
            // cout << len << "\tj:" << j << "\t";
            // cout << fread(&buf, len, 1, p) << "\t";
            // cout << fwrite(&buf, len, 1, op) << endl;
            fread(&buf, len, 1, p);
            fwrite(&buf, len, 1, op);
        }
        tmpname[1]++;
        fclose(op);
    }

    fclose(input);

    FILE *t[N];
    int total = 0;
    for (int i = 0; i < N; i++)
    {
        tmpname[1]--;
        t[i] = fopen(tmpname, "rb");
        fseek(t[i], 0, SEEK_END);
        cout << ftell(t[i]) << " ";
        total += ftell(t[i]);
        fclose(t[i]);
    }
    cout << total << " - " << Bsize << " = " << total - Bsize << endl;

    return 0;
}
