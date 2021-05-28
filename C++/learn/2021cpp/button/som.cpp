#include <stdio.h>
#include <windows.h>
#include <string.h>
#define NUM 101      //101设置原因在于字符串结束标志'\0'不能缺失
#define SPEED 100    //控制进度增长速度

void process()
{
	char bar[NUM];
	memset(bar, '\0', sizeof(bar));  //初始化空间
	const char *dynamic = "-\\|/";   //指示标志
	for (int i = 0; i < NUM; i++)
    {
		printf("[%-100s][%d%%][%c]\r ", bar, i, dynamic[i%4]);
		bar[i] = '#';
		fflush(stdout);  //强制刷新缓冲区
		Sleep(100);    //动态假象
	}
	printf("\n");
}

int main() 
{
	system("cls");
	system("@echo off");
    printf("\n");
	process();
	return 0;
}