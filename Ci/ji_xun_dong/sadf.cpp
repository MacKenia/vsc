#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
typedef long long LL;
#define mem(x,y) memset(x,y,sizeof(x))
#define T_T while(T--)
#define F(i,x) for(i=1;i<=x;i++)
#define SI(x) scanf("%d",&x)
#define SL(x) scanf("%lld",&x)
#define PI(x) printf("%d",x)
#define PL(x) printf("%lld",x)
#define P_ printf(" ")
const int MAXN=500010;
int dt[MAXN],b[MAXN];
LL ans;
void mergesort(int l,int mid,int r){
    int ll=l,rr=mid+1,pos=l;
    while(ll<=mid&&rr<=r){
        if(dt[ll]<=dt[rr])b[pos++]=dt[ll++];
        else{
            ans+=rr-pos;
            b[pos++]=dt[rr++];
        }
    }
    for(int i=ll;i<=mid;i++)b[pos++]=dt[i];
    for(int i=rr;i<=r;i++)b[pos++]=dt[i];
    for(int i=l;i<=r;i++)dt[i]=b[i];
}
void ms(int l,int r){
    if(l<r){
        int mid=(l+r)>>1;
        ms(l,mid);
        ms(mid+1,r);
        mergesort(l,mid,r);
    }
}
int main(){
    int N;
    while(~scanf("%d",&N),N){
        int i,j;
        ans=0;
        F(i,N)
            SI(dt[i]);
            ms(1,N);
        PL(ans);puts("");
    }
    return 0;
}