#include<bits/stdc++.h>
#include<map>
using namespace std;
typedef map<string,int> msi;
typedef pair<string,int> sPair;

int m[4505][5];

int main()
{
    msi moc;
    int nc, nm, na[305];
    scanf("%d%d",&nc, nm);
    for(int i=0; i < nm; i++)
    {
        scanf("%d%d%d", &m[i][0], &m[i][1], &m[i][2]);
        char t[3] = {48+m[i][0], 48+m[i][1],'\0'};
        moc.insert(sPair(t ,i));
        
    }

    return 0;
}
