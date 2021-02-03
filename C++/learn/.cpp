#include <math.h>
#include <string.h>
#include <iostream>

using namespace std;
typedef long long LL;
const int inf=0x3f3f3f3f;
const double pi= acos(-1.0);
int prime[1000010];
int Euler(int n)//筛选素数+求<=n的与n互素的数
{
    int i,j;
    int m=n;//因为下面的n是要变得，所以先将n存起来
    int c=n;//返回的是pji[m]
    memset(prime,0,sizeof(prime));
    for(i=2;i*i<=n;i++){
        if(n%i==0){
            n/=i;
            for(j=1;i*j<=m;j++)//用筛选法标记所有与n不互素的数
                prime[i*j]=1;
            c=c/i*(i-1);
            while(n%i==0)
                n=n/i;
        }
    }
    if(n>1){
        for(j=1;n*j<=m;j++)// 当n>1的时候，n本身也是一个素因子
            prime[n*j]=1;
        c=c/n*(n-1);
    }
    return c;
}
 
int main()
{
    int m,k,i;
    int cnt;
    int sum;
    int t;
    while(~scanf("%d %d",&m,&k)){
        cnt=Euler(m);
        t=k/cnt;
        sum=0;
        if(k%cnt==0)
            t--;
        k=k-cnt*t;
        for(i=1;i<=m;i++){
            if(!prime[i])
                sum++;
            if(sum==k)
                break;
        }
        printf("%d\n",m*t+i);
    }
    return 0;
}
