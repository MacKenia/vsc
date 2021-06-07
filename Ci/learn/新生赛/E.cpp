#include<stdio.h>

int main()
{
	int t[3], a, i;
	scanf("%d:%d:%d",&t[0],&t[1],&t[2]);
	scanf("%d", &a);
	for(i = 0; a > 0; a -= 60)
	{
		if(a < 60)
		{
			t[2] += a;
			if(t[2]>=60) 
			{
				t[1] ++;
				t[2] -= 60;
				if(t[1] == 60)
				{
					t[0] ++;
					t[1] -= 60;
					if(t[0] == 24) t[0] = 0;
				}
			}
		}
		else
		{
			t[1] ++;
			if(t[1] >= 60)
			{
				t[1] -= 60;
				if(t[0] < 23) t[0]++;
				else t[0] = 0;
			}
		}
	}
	for(i = 0; i < 3; i++)
	{
		if(t[i]<10) printf("0%d",t[i]);
		else printf("%d", t[i]);
		if(i < 2) printf(":");
	}
	return 0;
}