#include<bits/stdc++.h>
using namespace std;
#define M 1000

vector<int> vt[M];

int main()
{
    int n, m, total = 0;
    cin >> n >> m;
    while(m--)
    {
        int t1, t2;
        cin >> t1, t2;
        for(int i = 0; i < M; i++)
        {
            if(vt[i].empty())
            {
                vt[i].push_back(t1);
                vt[i].push_back(t2);
                break;
            }
            else if(t1 == vt[i].at(0) || t2 == vt[i].at(0) || find(vt[i].begin(),vt[i].end(),t1) != vt[i].end() || find(vt[i].begin(),vt[i].end(),t2) != vt[i].end())
            {
                vt[i].push_back(t1);
                vt[i].push_back(t2);
                break;
            }
        }
    }
    for(int i = 0; i < vt[0].size();i ++)
    {
        cout << vt[0].at(i) << endl;
    }
    for(int i = 0; !vt[i].empty() && i < M; i++) total++;
    cout << total << endl;
    return 0;
}
