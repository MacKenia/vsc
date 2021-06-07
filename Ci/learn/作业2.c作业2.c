#include<stdio.h>

int main()
{
	char s[26],a[80];
	int i;
	printf("Please enter a string for add up its each character:\n");
	gets(a);
	for(i = 0; i < 26; i++)
	{
		s[i] = 0;
	}
	for(i = 0; a[i] != '\0'; i++)
	{
		if(a[i] >= 'a' && a[i] <= 'z')
		{
			s[a[i] - 97]++;
		}
	}
	for(i = 0; i < 26; i++)
	{
		printf("There are %d %C in the string\n", s[i], 97 + i);
	}
	return 0;
}
