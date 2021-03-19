#include <stdio.h>

int main()
{
    char a;
    printf("please input a lowercase:\n");
    a = getchar();
    a -= 32;
    printf("%c %d %d", a, a, sizeof(a));
    return 0;
}
