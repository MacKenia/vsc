#include<stdio.h>
#include<string.h>

int main()
{
    int fun1(char *p);
    char array[150][20], t[100000];
    int i = 0, j = 0, k = 0;
    gets(t);
    for (i = 0; t[i] != '\0'; i++)
    {
        if(t[i] == ' ')
        {
            k=0;
            i++;
            j++;
        }
        array[j][k++] = t[i];
    }

    for(i = 0; i <= j; i++)
    {
        fun1(array[i]);
    }

    for(i = 0;i <= j; i++)
    {
        printf(array[i]);
        printf(" ");
    }
    return 0;
}

int fun1(char *p)
{
    int fun2(char *p);
    int i = strlen(p);
    char *t = p;
    if (*p == 'A'|| *p == 'E'|| *p == 'I'|| *p == 'O'|| *p == 'U'||*p == 'a'|| *p == 'e'|| *p == 'i'|| *p == 'o'|| *p == 'u')
    {
            p[i++] = 'a';
            p[i] = 'y';
    }
    else fun2(p);
    char te;
    for(; *t != '\0'; t++)
    {
        if(!(*t>='A' && *t<='Z'||*t>='a' && *t<='z'))
        {
            te = *t;
            strcpy(t,t+1);
        }
    }
    *t = te;
    return 0;
}

int fun2(char *p)
{
    char t = *p;
    for ( ;*p != '\0'; p++) *(p-1) = *p;
    *(p-1) = t;
    *(p++) = 'a';
    *p = 'y';    
    return 0;
}

