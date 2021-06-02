#include<stdio.h>
#include<string.h>
int main()
{
	int i, j, k=0, n;
	char arr[1000];
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%s", arr);
		for(j = 0; j < strlen(arr); j++)
		{
			if((arr[j] == 'a' || arr[j] == 'A') && (arr[j+1] == 'l' || arr[j+1] == 'L') && (arr[j+2] == 'a' || arr[j+2] == 'A') && (arr[j+3] == 'n' || arr[j+3] == 'N'))
				{
					k++;
					printf("%d\n", k);
					break;
				}
		}
	}

	printf("%d",k);
	return 0;
}