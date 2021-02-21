#include<bits/stdc++.h>

using namespace std;

void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

int partition(int a[], int low, int high){
	int pivot = a[high];
	int left = low;
	int right = high - 1;
	while(true){
		while(left <= right && a[left] < pivot) left++;
		while(left <= right && a[right] > pivot) right--;
		if(left >= right) break;	
		swap(a[left], a[right]);
		left++;
		right--;
	}
	swap(a[left], a[high]);
	return left;
}


void quickSort(int a[], int l, int r){
	if(l < r){
		int ind = partition(a, l, r);
		quickSort(a, l, ind -1 );
		quickSort(a, ind +1 , r);
	}
}


void output(int a[], int n){
	for(int i = 0 ; i < n; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main(){
	int a[] = {3, 8, 1, 4, 7, 5};
	int n = sizeof(a)/sizeof(a[0]);
	quickSort(a, 0, n -1);
	output(a, n);
	return 0;
}
