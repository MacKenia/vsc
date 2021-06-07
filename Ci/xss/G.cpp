#include<stdio.h>

int main()
{
	int i, j, k, n, v;
	float p[1000][3];
	scanf("%d%d", &n, &v);
	for(i = 0; i < n; i++)
	{
		scanf("%d%d", &p[i][0], &p[i][1]);
		p[i][2] = p[i][1] / p[i][0];
	}
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n - i - 1; j++)
		{
			if(p[j][2] < p[j][2])
			{
				
			}
		}
	}
	return 0;
}