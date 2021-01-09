#include<stdio.h>

int main()
{
	int arr[4][3] = {{1,2,3},{4,5,6},{7,8, 9},{10,11,12}}, i, j = 0, k;
	int *a;
	a = &arr[0][0];
//	for(a = 0; a < 4; a++)
//	{
//		printf("Please enter the %d raw's data(contain 3 numbers):", a + 1);
//		scanf("%d%d%d", &arr[a][0], &arr[a][1], &arr[a][2]);
//	}
	for(i = 0; i < 4; i++)
	{
		for(k = 0; k < 3; k++)
		{
			printf("arr[%d][%d] = %d\n", i, k, arr[i][k]);
			printf("*(*(arr + %d) + %d) = %d\n\n", i, k, *(a + j++));
		}
	}
	return 0;
}

