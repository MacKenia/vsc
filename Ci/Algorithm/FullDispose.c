#include <stdio.h>
#include <string.h>

void dispose(const char *s, int n)
{
    if(n==1)
    {
        printf("%s\n", s);
        return;
    }
    char ss[10];
    for (int i = strlen(s)-n; i < strlen(s); i++)
    {
        memset(ss, 0, sizeof(ss));
        strcpy(ss,s);
        int tmp = ss[strlen(s)-n];
        ss[strlen(s)-n] = ss[i];
        ss[i] = tmp;
        dispose(ss, n-1);
    }
}

int main()
{
    char s[80];
    printf("输入字符串: ");
    scanf("%s", s);
    dispose(s, strlen(s));
    return 0;
}
