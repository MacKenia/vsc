#include <bits/stdc++.h>
#define N 10

using namespace std;

int main()
{
    int A[N];
    memset(A, 0, sizeof(A));
    for (int i = 0; i < N; i++)
    {
        if(i%3) A[i] = i+1;
        else A[i] = -(i+1);
    }
    for(int i = 0; i < N; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    for (int i = 0, j = N-1; i < j;)
    {
        int tmp;
        if(A[i] < 0 && A[j] > 0)
        {
            i++, j--;
        }
        else if(A[i] < 0 && A[j] < 0)
        {
            i++;
        }
        else if(A[i] > 0 && A[j] > 0)
        {
            j--;
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
