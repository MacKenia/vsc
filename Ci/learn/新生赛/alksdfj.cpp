#include <stdio.h>

int main()
{
	int i, j, k;
	for(i = 0; i < 7; i++)
	{
		for(j = 0; j < 4; j++)
		{
			if(i == 0 && j == 0 || i == 5 && j == 0 || i == 6 && j== 1) printf("\\");
			if(i == 0 && j == 3 || i == 5 && j == 3 || i == 6 && j == 2) printf("/");
			if((i == 0 && (j == 1 || j ==2)) || (j == 0 || j == 3) && (i > 0 && i < 5)) printf("|");
			if((i > 0 && i < 6) && (j == 1 || j == 2) || (i == 6 && j == 0)) printf(" ");
		}
		printf("\n");
	}
	return 0;
}
