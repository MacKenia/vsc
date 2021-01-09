#include<stdio.h>
#include<string.h>

int main()
{
	int i, j;
	char a[80], b[80];
	printf("Please enter a string:\n");
	scanf("%s", a);
	printf("Please enter another string:\n");
	scanf("%s", b);
	for(i = strlen(a), j = 0; b[j] != '\0'; j++)
	{
		if(b[j] % 2 == 0) a[i++] = b[j];
	}
	puts(a);
	return 0;
}
