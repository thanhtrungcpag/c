#include<bits/stdc++.h>

using namespace std;


void selectionSort(int a[], int n){
	for(int i = 0; i < n-1; i++){
		int min_in = i;
		for(int j = i +1 ; j < n; j++){
			if(a[j] < a[min_in]){
				min_in = j;
			}
		}
		int temp = a[i];
		a[i] = a[min_in];
		a[min_in] = temp;
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
	selectionSort(a, n);
	output(a, n);
	return 0;
	
	return 0;
}
