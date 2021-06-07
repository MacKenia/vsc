#include<stdio.h>

int main()
{
	int i, j, k, n;
	char arr[3][80];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%s",arr[i]);
	for(i = 0; i < n; i++)
	{
		for(j = 1; arr[i][j] != '%'; j++);
		puts(&arr[i][j+1]);
	}
	return 0;
}
