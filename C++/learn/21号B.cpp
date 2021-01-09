#include<stdio.h>

int main()
{
	int a, b, c;
	scanf("%d", &c);
//	printf("%d\n",c);
	for(a = 1; a < c; a++)
	{
		for(b = c; b > a; b--)
		{
//			printf("%d %d\n", a, b);
			if(a*a + b*b == c*c)
			{
				printf("a = %d, b = %d\n", a, b);
				break;
			}
		}
		
	}
	
	return 0;
}
