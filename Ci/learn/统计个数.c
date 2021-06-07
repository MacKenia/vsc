#include<stdio.h>

int main()
{
	int i, j;
	char d2[80];
	printf("Please enter a string which includes some spaces:\n");
	gets(d2);
	for(i = 0, j = 0; d2[i] != '\0'; i++, j++)
	{

		if(d2[i] == ' ') i++;
		d2[j] = d2[i];
	}
	d2[j] = '\0';
	puts(d2);
	return 0;
}
