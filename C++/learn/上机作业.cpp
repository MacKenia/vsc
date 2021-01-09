#include<stdio.h>

int main()
{
	char a[80], b[80];
	int strcmp(char a[80], char b[80]);
	printf("Pleae enter the first string:\n");
	gets(a);
	printf("Pleae enter the second string:\n");
	gets(b);
	printf("%d", strcmp(a, b));
	return 0;
}

int strcmp(char a[80], char b[80])
{
	int c = 0, i;
	for(i = 0; a[i] != '\0'|| b[i] != '\0'; i++)
	{
		c = a[i] - b[i];
		if(c != 0) break;
	}
	return c;
}
