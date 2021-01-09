#include<stdio.h>

int main()
{
	int n, i, a, all = 0;
	scanf("%d", &n);
	for(i = 0: i < n; i++)
	{
		scanf("%d", &a);
		all += a;
	}
	printf("%d", all);
	return 0;
}