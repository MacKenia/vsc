#include <stdio.h>
#include <string.h>

void dispose(const char *s, int sb, int n)
{
    if(!n) return;
    char ss[80];
    memset(ss, 0, sizeof(ss));
    for (int i = 0; i < strlen(s); i++)
    { 
        strcpy(ss,s);
        int tmp = ss[sb];
        ss[sb] = ss[i];
        ss[i] = tmp;
        dispose(ss, i, n-1);
    }
    printf("%s ",s);
}

int main()
{
    char *s = "ABC";
    dispose(s, 0, strlen(s));
    return 0;
}
