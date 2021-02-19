#include<bits/stdc++.h>

using namespace std;


void bubbleSort(int a[], int n){

	for(int i = 0 ; i < n - 1; i++){
		int flag = 0;
		for(int j = 0; j < n - i - 1;j++){
			if(a[j] > a[j+1]){
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				flag = 1;
			}
		}
		if(!flag){
			break;
		}
	}
}


void bubbleSort2(int a[], int n){
	for(int i = 0; i < n - 1; i++){
		int flag = 0;
		for(int j = 0; j < n - i - 1; j++){
			if(a[j] > a[j+1]){
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				flag = 1;
			}
		}
		if(!flag) break;
	}
}

void output(int a[], int n){
	for(int i = 0 ; i < n; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main(){
	
	int a[] = {3, 2, 1, 4, 6, 5};
	int n = sizeof(a)/sizeof(a[0]);
	bubbleSort2(a, n);
	output(a, n);
	return 0;
}
