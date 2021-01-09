#include<stdio.h>

int main()
{
	int i, j = 0, k = 0, n, l, q, p;
	scanf("%d%d", &l, &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d%d", &q, &p);
		j = p;
		if(j >= p) k += p-j;
		else k += p-q+1;
	}
	printf("%d", l-k);
	return 0;
}