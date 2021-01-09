#include<stdio.h>

int main()
{
	int a;
	scanf("%d\n",&a);
	printf("%d",a);
	char *p = "xyz";
	int i;
	for (; *p != '\0'; p++) {
		printf("%c", *p);
	}


	return 0;
}
