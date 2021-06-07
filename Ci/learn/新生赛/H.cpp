#include<stdio.h>
#include<math.h>

int main()
{
	double c(int n);
	int n, j;
	double a;
	scanf("%d", &n);
	a = c(n);
	printf("%lf\n", a);
	for(j = 0; fmod(a,10) == 0; a /= 10)
	{
		j++;
	}
	printf("%d", j);
	return 0;
}

double c(int n)
{
	int i;
	double a;
	for(i = 1, a = 1; i <= n; i++)
	{
		a *= i;
	}
	return a;
}
