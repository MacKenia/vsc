#include <stdio.h>
int main()


{ 
  int a,c, d,e;
    float b;

    printf("Enter item number:\n");
    scanf("%d", &a);
    printf("Enter unit price:\n");
    scanf("%f", &b);
    printf("Enter purchase date (yy mm dd):\n");
    scanf("%d%d%d", &c, &d, &e);
    printf("Item      Unit     Purchase\n");
    printf("%-9d$%-9.2f%02d/%02d/%02d\n", a, b, d, e, c);
  
	return 0;
}