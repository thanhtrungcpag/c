#include <bits/stdc++.h>

using namespace std;


int interpolationSearch(int a[], int l, int r, int val){
	int mid;
	while(l <= r && val >= a[l] && val <= a[r]){
		mid = l + (r-l)*(val - a[l])/(a[r] - a[l]);
		if(val == a[mid]) return mid;
		if(a[mid] > val){
			r = mid - 1;
		}else{
			l = mid + 1;
		}
	}
	return -1;
}

int main(){
	
	int a[] = {13, 2, 4, 5, 6, 7};
	int n = sizeof(a)/sizeof(a[0]);
	sort(a, a + n);
	for(int i = 0; i < n; i++){
		cout <<a[i]<<" ";
	}
	cout<<endl;
	cout <<"Search 4"<<endl;
	cout <<interpolationSearch(a, 0, n -1, 4)<<endl;
	cout <<"Search 5"<<endl;
	cout <<interpolationSearch(a, 0, n -1, 10)<<endl;
	
	
	return 0;
}
