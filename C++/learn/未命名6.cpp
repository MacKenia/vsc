#include<stdio.h>
#include<string.h>

int main()
{
	int reverse(char a[]);
	char a[80];
	gets(a);
	reverse(a);
	puts(a);
	return 0;
}


int reverse(char a[])
{
	int i,j;
	char t;
	for(i = 0, j = strlen(a) - 1; i < j; i++, j--)
	{
		t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
	
	
	return 0;
}
