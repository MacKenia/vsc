#include<stdio.h>
#include<string.h>
int main()
{
	char a[80], b[80];
	int con(char a[], char *b);
	gets(a);
	gets(b);
	con(a,b);
	puts(a);
	return 0;
}

int con(char a[], char *b)
{
	int i;
	for(i = strlen(a); *b != '\0'; b++)
	{
		if(*b%2==1)
		{
			a[i] = *b;
			i++;
		}
	}
//	a[i] = '\0';
	return 0;
}

