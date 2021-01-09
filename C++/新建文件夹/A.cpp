#include<stdio.h>

int main()
{
	double td(int n);
	double n;
	int a, i;
	scanf("%d", &a);
	n = td(a);
	printf("%lf\n", n);
	for(i = 0; n >= 1; n /= 10, i++);
	printf("%d", i);
	return 0;
}

double td(int n)
{
	double f = 1;
	int i;
	for(i = 1; i <= n; i++)
		f *= 2;
	return f;
}
