#include<stdio.h>

void constring(char s[], char t[], char q[]); //函数声明

int main(void)
{
    char s[100];
    char q[100];
    char t[200];
    printf("Input a string:");//提示输入字符串
    gets(s); //输入字符串
    printf("Input another string:");
    gets(q);
    constring(s, q, t);//调用函数
    printf("Concatenate results:%s\n", t);
}

void constring(char s[], char t[], char q[])
{
    int i, j;
    for (i = 0; s[i] != '\0'; i++)
    {
        q[i] = s[i];
    }
    for (j = 0; t[j] != '\0'; j++)
    {
        q[i + j] = t[j];
    }
    q[i + j] = '\0';
}