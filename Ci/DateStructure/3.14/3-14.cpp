#include <bits/stdc++.h>
#define M 10
#define N 10

using namespace std;

int main()
{
    int A[M][N];
    memset(A, 0, sizeof(A));
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
        {
            A[i][j] = rand() % 20;
        }
    for(int i = 0; i < M*N; i++)
        for(int j = i; j < M*N; j++)
        {
            if(*(A+i) == *(A+j))
            {
                cout << "There are two same number." << endl;
                return 1;
            }
        }
    cout << "Yes" << endl;
    return 1;
}
