#include<stdio.h>
#include<algorithm>
//定义Max_N
const int Max_N = 100;
int main()
{
	int n, k[Max_N];
	//要求用户输入
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &k[i]);
	}
	//以由小到大顺序重新排列数组
	std::sort(k,k+n);
	
	//判断循环
	for (int c = 0; c < n; c++) {
		for (int b = c+1; b < n; b++) {
			for (int a = b+1; a < n; a++) {
//				int x=k[a]+k[b]+k[c];
				if (k[a] - k[b] < k[c]){
				printf("%d\n", k[a] + k[b] + k[c]);
				}
				else puts("0");
			}
		}
	}
	return 0;
}




