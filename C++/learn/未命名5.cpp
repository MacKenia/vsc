
#include<stdio.h>

const int Max_P = 6;
int main()
{
	int Have(int n, int a[]);
	int sort(int a, int b);
	int a[Max_P], n;
	float rp, sum;
    scanf("%d %d", &n, &rp);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	
	if ( Have(n, a[]) ) {
		for (int j = 0; j < n; j++) {
			sort(a[j], a[j + 1]);
			j++;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d",a[i]);
	}

}

int sort(int a, int b)
{
	if (a < b);
	else {
		a = a + b;
		b = a - b;
		a = a - b;
	}
	return 0;
}

int Have(int n, int a[])
{
	bool f = false;
	for (int i = 1; i < n; i++) {
		if (a[0] < a[i]) f = true;
	}
	return f;
}

