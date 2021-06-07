#include<stdio.h>

int main()
{
	int a[10000], n, k, i, j, t;
	scanf("%d%d", &n, &k);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	for(i = 0; i < k; i++)
	{
		for(j = 0; j < n - i - 1; j++)
		{
			if(a[j] > a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
	
	for(i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}