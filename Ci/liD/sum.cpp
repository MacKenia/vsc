#include <bits/stdc++.h>

using namespace std;

int main()
{
    float sum = 1 ,a;
    int i;
    for (i = 1, a = 3; (1/a) >= 1e-6; a += 2, i++)
    {
        sum += (1/a)*pow(-1,i);
    }
    printf("%.3f\n",sum);
    return 0;
}
