#include <stdio.h>

void transfer();

int main()
{
    transfer(37);
    return 0;
}

void transfer(int a)
{
    char buf[17];
    int i;
    for (i = 0; i < 15; i++) buf[i] = '0';
    for(i = 1; i < 16 && a != 0; i++, a/= 2) buf[16-i] = '0'+a%2;
    printf("%s",buf);
}
