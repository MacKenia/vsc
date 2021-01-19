#include<stdio.h>
#include<string.h>

int main()
{
    int fun1(char *p);
    char array[150][20], t[100000];
    int i = 0, j = 0, k = 0;
    gets(t);
    //分离单词，放入不同的行中
    for (i = 0; t[i] != '\0'; i++)
    {
        if(t[i] == ' ')
        {
            k=0;
            i++;
            j++;
        }
        array[j][k++] = t[i];
        t[i] = '\0';
    }
    //调用函数
    for(i = 0; i <= j; i++)
    {
        fun1(array[i]);
    }
    //输出结果
    for(i = 0;i <= j; i++)
    {
        printf(array[i]);
        printf(" ");
    }
    return 0;
}
//对不同的单词进行处理
int fun1(char *p)
{
    int fun2(char *p);
    int i = strlen(p);
    char *t = p;
    if (*p == 'A'|| *p == 'E'|| *p == 'I'|| *p == 'O'|| *p == 'U'||*p == 'a'|| *p == 'e'|| *p == 'i'|| *p == 'o'|| *p == 'u')
    {
        strcpy(t+strlen(p), "ay");
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
    strcpy(p,p+1);
    *(p + strlen(p)) = t;
    strcpy(p+strlen(p), "ay");
    return 0;
}

