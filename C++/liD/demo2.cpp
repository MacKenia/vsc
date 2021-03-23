#include <math.h>
#include <stdio.h>
int main()

{  
    int year,money;
	float rate,sum;

	printf("Enter money:");
	scanf("%d",&money);
	printf("Enter year:");
	scanf("%d",&year);
	printf("Enter rate:");
	scanf("%f",&rate);

 
	sum = (pow((1+rate),year))*money;
	printf("sum = %.2f\n",sum);
	return 0;

}