#include<stdio.h>

int main()
{
	int  sb(int a);
	int n, num[1000], i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}
	
	for(i = 0; i < n; i++)
	{
		for(j = num[i]; j > 0; j--)
		{
			if(sb(j) == 0)
			{
				printf("%d\n", j);
				break;
			}
		}
	}
	
	return 0;
}

int sb(int a)
{
	int i, m = 0;
	for(i = a; i > 0; i/=10)
	{
		if(i % 10 < (i/10)%10) m++;
	}
	return m;
}