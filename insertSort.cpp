#include<bits/stdc++.h>

using namespace std;


void insertSort(int a[], int n){
	for(int  i = 1; i < n; i++){
		int key = a[i];
		int j = i-1;
		while(j >= 0 && key < a[j]){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
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
	insertSort(a, n);
	output(a, n);
	return 0;
}
