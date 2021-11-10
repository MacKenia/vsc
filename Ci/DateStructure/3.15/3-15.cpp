#include <bits/stdc++.h>
#define N 100

using namespace std;

int main()
{
    int A[N];
    memset(A, 0, sizeof(A));
    for (int i = 0; i < N; i++)
    {
        if(i%2) A[i] = i+1;
        else A[i] = -(i+1);
    }
    for(int i = 0; i < N; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    for (int i = 0, j = N-1; i < j; i++, j--)
    {
        int tmp;
        if(A[i] < 0 && A[j] > 0)
        {
            continue;
        }
        else if(A[i] < 0 && A[j] < 0)
        {
            i++;
            continue;
        }
        else if(A[i] > 0 && A[j] > 0)
        {
            j--;
            continue;
        }
        else
        {
            tmp = A[i];
            A[i] = A[j];
            A[j] = tmp;
            continue;
        }
    }
    for(int i = 0; i < N; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
