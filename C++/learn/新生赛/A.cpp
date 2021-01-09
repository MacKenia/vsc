#include<stdio.h>

int main()
{
	int n, i, j, m, n, k, count, a[5];
	scanf("%d", &n);
	for(i = 0;  i < n; i++)
	{
		scanf("%d",&a[i]);
	}
	m = a[0];
	for(i = 0; i < n; i++)
	{
		count = 0;
		
		for(j = 0; j < n; j++)
		{
			if(a[j] == m) count++;
			if(m == count) break;
		}
		
		for(j = 0; a[j] == 0; j++)
		{
			a[j] -= m;
		}
		
		for(j = 0; a[j] != 0; j++)
		{
			if(a[j] != 0) m = a[j];
		}
	}
	
	if(count == m) printf("%d", m);
	else printf("-1");
	
	return 0;
}