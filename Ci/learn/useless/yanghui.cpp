#include<stdio.h>
#include<math.h>

int main()
{
	int a,i;
	for(i=0;i<4;i++){
		a = pow(11,i);
		for(;a!=0;a/=10){
			printf("%2d",a%10);
		}
	printf("\n");
	}
	return 0;
}

