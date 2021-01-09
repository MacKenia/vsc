#include<stdio.h>

int main()
{
	int a,n,i,j,k,x,y;
	for(n=6;n<=100;n+=2){
		for(i=2;i<n;i++){
			x=0;
			y=0;
			a = n - i;
//			printf("%d\n",a);
			for(j=2;j<i;j++)
			if(i%j==0) x++;
			
			for(k=2;k<a;k++)
			if(a%k==0) y++;
			
			if(x==0&&y==0){
			printf("%d+%d=%d\n",a,i,n);
			break;
			}
		}
	}
	return 0;
	
	
	
	
}

