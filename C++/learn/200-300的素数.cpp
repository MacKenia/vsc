#include<stdio.h>

int main()
{
	int i, j = 0, k;
	int pd(int a);
	for(i = 200; i <= 300; i++)
	{
		if(pd(i))
		{
			j++;
			printf("%5d", i);
			if(j % 5 == 0) printf("\n");
		}
	}
	return 0;
}

int pd(int a)
{
	int i ,j = 1;
	for(i = 2; i < a; i++)
	{
		if(a % i == 0)
		{
			j = 0;
			break;
		}
	}
	return j;
}
