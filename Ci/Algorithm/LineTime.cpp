#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int partition(int a[], int p, int r)
{
	int i = p;
	int j = r + 1;
	int x = a[p];

	while (true)
	{
		while (a[++i] < x && i < r);
		while (a[--j] > x);
		if (i >= j)
			break;
		swap(a[i], a[j]);
	}
	a[p] = a[j];
	a[j] = x;
	return j;
}

int partition(int a[], int p, int r, int x)
{

	int i = p - 1;
	int j = r + 1;

	while (true)
	{
		while (a[++i] < x && i < r)
			;
		while (a[--j] > x)
			;
		if (i >= j)
			break;
		swap(a[i], a[j]);
	}
	a[p] = a[j];
	a[j] = x;
	return j;
}

void QuickSort(int a[], int p, int r)
{
	if (p < r)
	{
		int q = partition(a, p, r);
		QuickSort(a, p, q - 1);
		QuickSort(a, q + 1, r);
	}
}

int select(int a[], int p, int r, int k)
{

	if (r - p < 75)
	{
		QuickSort(a, p, r);
		return a[p + k - 1];
	}

	for (int i = 0; i <= (r - p - 4) / 5; i++)
	{

		QuickSort(a, p + i * 5, p + i * 5 + 4);
		swap(a[p + i], a[p + i * 5 + 2]);
	}

	int x = select(a, p, p + (r - p - 4) / 5, (r - p - 4) / 10);
	int pivot = partition(a, p, r, x);
	int j = pivot - p + 1;

	if (k <= j)
		return select(a, p, pivot, k);
	else
		return select(a, pivot + 1, r, k - j);
}

int main()
{
	int a[100];
	srand((int)time(NULL));
	for (int i = 0; i < 100; i++)
	{

		a[i] = rand() % 100;
	}

	cout << "原数组: " << endl;
	for (int i = 0; i < 100; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	int k;
	cout << "你要选择的数: ";
	cin >> k;
	cout << "第" << k << "大的数为: " << select(a, 0, 99, k) << endl;

	cout << "快随排序后数组: " << endl;
	QuickSort(a, 0, 99);
	for (int i = 0; i < 100; i++)
	{
		cout << a[i] << " ";
	}
}