#include <stdio.h>
// #include <windows.h>
#include <cstdlib>
#include <unistd.h>
#include <string.h>
#define NUM 101      //101设置原因在于字符串结束标志'\0'不能缺失
#define SPEED 100    //控制进度增长速度

void process()
{
	char bar[NUM];
	memset(bar, '=', sizeof(bar));  //初始化空间
	const char *dynamic = "-\\|/";   //指示标志
	for (int i = 0; i < NUM; i++)
    {
		bar[i] = '>';
		printf("[%-100s][%d%%][%c]\r ", bar, i, dynamic[i%4]);
		fflush(stdout);  //强制刷新缓冲区
		usleep(100000);    //动态假象
	}
	printf("\n");
}

int main() 
{
	system("clear");
	// system("@echo off");
    // printf("\n");
	process();
	return 0;
}