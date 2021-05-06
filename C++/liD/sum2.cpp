#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num, sum = 0;
    do
    {
        printf("please input:");
        scanf("%d", &num);
        sum += num;
    } while (num != 0);
    printf("%d", sum);
    return 0;
}
