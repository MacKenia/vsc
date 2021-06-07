#include<iostream>
#include<set>
// #include<algorithm>
using namespace std;

set<int> s;
set<int>::iterator p = s.end();

// void fun(int a)
// {
//     cout << a << ' ';
// }

int bpath(int k, int n, int a, int b, int f, int ins[105], int sum)
{
    if(f>=n&&k>=0) return 1;
    else if(f<=n&&k<=0) return 0;
    else for(int i=a, sum = 0;i<=b;i++) if(bpath(k,n,a,b,f+i,ins,sum+=ins[f])) s.insert(sum);
    return 0;
}

int main()
{
    int nn, n, a, b, k, f = 0, ins[100], sum;
    cin>>nn;
    while(nn--)
    {
        cin >> n >> a >> b >> k;
        for(int i = 0; i < n; i++) cin >> ins[i];
        bpath(k, n, a, b, f, ins,sum);
        // for_each(s.begin(), s.end(), fun);
        cout << *(--p) <<endl;
        s.clear();
    }
    return 0;
}
