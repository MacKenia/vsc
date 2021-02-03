#include<iostream>
#include<set>
using namespace std;

set<int> m;
set<int>::iterator ma = m.end();


int main()
{
    int nn, n, a, b, k, f = 0, ins[100], sum = 0;
    cin>>nn;
    while(nn--)
    {
        cin >> n >> a >> b >> k;
        for(int i = 0; i < n; i++) cin >> ins[i];
        for(int i = 0, sum = 0; i < n; i++)
            for(int j = 0; j < k; j++)
                for(int k = i + a; k < i + b&& k <= n; k++) m.insert(sum += ins[k]);
        cout << *(--ma) << endl;
        m.clear();
    }
    return 0;
}
