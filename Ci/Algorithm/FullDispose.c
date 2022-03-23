#include <stdio.h>
#include <string.h>

void dispose(const char *s, int n)
{
    if(n==1)
    {
        printf("%s ", s);
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
    char *s = "ABCD";
    dispose(s, strlen(s));
    return 0;
}
