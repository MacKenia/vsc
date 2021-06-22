#include<stdio.h>

int main()
{
	int separate(int a);
	int a;
	scanf("%d", &a);
	printf("%d\n", separate(a));
	return 0;
}

int separate(int a)
{
	int i, m;
	for(i = 1; a != 0; a /= 10)
	{
		m = a % 10;
		i *= m;
	}
	return i;
}

