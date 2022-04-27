#include <stdio.h>
#define N 9

void track(int *ar, int *a, int tar, int len)
{
    int s = 0, e = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        if(a[i] == tar)
            e = i;
        else if (a[i + 1] == ar[i])
        {
            s = i;
            break;
        }
    }
    for (int i = s; i <= e; i++)
    {
        printf("%d, ", ar[i]);
    }
    printf("\n");
}

int main()
{
    int S = 0, arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4}, dp[N + 1] = {arr[0]};
    for (int i = 1; i < N + 1; i++)
        dp[i] = dp[i - 1] + arr[i - 1] >= arr[i - 1] ? dp[i - 1] + arr[i - 1] : arr[i - 1];

    for (int i = 1; i < N; i++)
        S = dp[i] > dp[i - 1] ? i - 1 : i - 2;

    for (int i = 0; i < N; i++)
        printf("%d, ", dp[i + 1]);

    printf("\n%d\n", S);

    track(arr, dp, dp[S], N);
    return 0;
}
