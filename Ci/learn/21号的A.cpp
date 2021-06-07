#include<stdio.h>

int main()
{
	int s, a, i, j, k = 0;
	
	for(i = 9; i <= 900000; i++)
	{
		printf("%d\n", i);
		a = i;
		s = 0;
		for( ; a != 0; a/=10)
		{
		s += a%10;
		if(s>9||s!=0&&a==9) break;
		}
		if(s == 9) k++;
	}
	printf("%d\n", k);
	
	return 0;
}
