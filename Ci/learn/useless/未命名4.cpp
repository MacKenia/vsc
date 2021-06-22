#include<stdio.h>

const int Max_N = 4;
int main()
{
	int AreTheyAlike(int a, int b);
	int n,a[Max_N],password = 0;
	scanf("%d",&n);
	for(int i = 0; i < n; i++) {
		scanf("%d",&a[i]);
	}
//数组循环	
	for(int j = 0; j < n; j++) {
		for(int k = j; k < n; k++) {
			//将中间夹有数字的组分开
			if((j + 1) < k||(j + 1) >k) {
				//判断其中不同的数
				int m,sum;
				m = k - j;
				const int Max_m = m;
				int h[Max_m],q = 0;
				int Exist_(h[Max_m],a);
				for (int i = 0; i < m; i++) {
					if (Exist_(h[Max_m],a[j]) sum += 1;
				}
				password += sum;
			} 
			else {
				if (AreTheyAlike(a[j],a[k])) password += 1;
				else password += 2;
			};
		}
	}
	return 0;
}

int AreTheyAlike(int a,int b)
{
	if (a > b||a < b) return 0;
	else return 1;
}

int Exist_(h[Max_m],int a)
{
	for (i = 0; i < Max_m; i++){
		if (h[i] != a) return 1;
		else return 0;
	}
}

