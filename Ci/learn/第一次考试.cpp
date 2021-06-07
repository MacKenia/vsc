#include<stdio.h>

int main()
{
	int n, i, m = 0;
	scanf("%d", &n);
	for(i = 1; i < n; i++)
	{
		if(n%i==0) m += i;
	}
	if(n <= m)
	 {
	 	if(n==m) printf("0");
	 	else printf("1");
	 }
	 else printf("-1");
	return 0;
}
