#include<stdio.h>

int main()
{
	int array[6] = {1, 2, 3, 4, 5, 6};
	int a = 7, b = 4;
	char p1[] = {"wo diao ni ma de."};
//	scanf("%d", array);
	printf("%d,%d\n", a, b);
	int print(int *p, int *q);
	print(&a, &b);
	printf("%d,%d\n", a, b);
	return 0;
}

int print(int *p, int *q)
{
	int i;
//	printf("%s", p);
//	for(i = 0; i < 6; i++){
//		printf("%d", *(p + i));
//	}
	i = *p;
	*p = *q;
	*q = i;
	return 0;
}

