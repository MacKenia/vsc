#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int partition(int a[], int p, int r){
	int i = p;
	int j = r + 1;
	int x = a[p];      //设置轴

	while(true){
		while(a[++i] < x && i < r) ;
		while(a[--j] > x) ;
		if(i >= j)
			break;
		swap(a[i], a[j]);
	}
	a[p] = a[j];
	a[j] = x;
	return j;
}

int partition(int a[], int p, int r, int x){   //重载partition方法 
	
	int i = p-1;
	int j = r + 1;

	while(true){
		while(a[++i] < x && i < r) ;
		while(a[--j] > x) ;
		if(i >= j)
			break;
		swap(a[i], a[j]);
	}
	a[p] = a[j];
	a[j] = x;
	return j;
}

void quickSort(int a[], int p, int r){
	if(p < r){
		int q = partition(a, p, r);
		quickSort(a, p, q - 1);   //左边排序
		quickSort(a, q + 1, r);    //
	}
}

int select(int a[], int p, int r, int k){
	
	if(r - p < 75) {
		
		quickSort(a, p , r);   //其他排序也可以 
		return a[p+k - 1];
	}
	
	for(int i = 0; i <= (r-p-4) / 5; i++){  //r-p-4表示最后一组的中位数所在组数 （有几组就有几个中位数，所以(r-p-4)/5也可以表示中位数个数） 
		
		quickSort(a, p+i*5, p+i*5+4);   //将元素每5个分成一组，分别排序
		swap(a[p+i], a[p+i*5+2]); 	   //并将该组中位数与a[p+i]交换位置使所有中位数都排列在数组最左侧，以便进一步查找中位数的中位数		
	}
	//找中位数的中位数
	int x = select(a, p, p+(r-p-4) / 5, (r-p-4) / 10); //(r-p-4) / 10：中位数的中位数的下标 
	int pivot = partition(a, p, r, x);
	int j = pivot-p + 1;
	
	if(k <= j)
		return select(a, p, pivot, k);
	else
		return select(a, pivot + 1, r, k - j);
}


int main(){
	//初始化数组 
	int a[100];
	srand((int)time(0));  // 产生随机种子  把0换成NULL也行
	for(int i = 0; i < 100; i++){
		
		a[i] = rand() % 100;
	}
	int k;
	cout << "please input k: "; cin >> k;
	cout << select(a, 0, 99, k) << endl;
	for(int i = 0; i < 100; i++){
		cout << a[i] << " ";
	}	
	cout << endl << "-------------检验组----------"<< endl;
	quickSort(a, 0, 99);
	for(int i = 0; i < 100; i++){
		cout << "a[" << i << "]="<< a[i]  << " ";
	}	
	
}