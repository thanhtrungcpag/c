#include <bits/stdc++.h>

using namespace std;


int findSmallInterVal(int a[], int n){
	int res = 1;
//	int n = sizeof(a)/sizeof(a[0]);
//	cout <<n;
	for(int i = 0; i < n && res >= a[i]; i++){
		res += a[i];
	}
	return res;
}

int main(){
	
	int a[] = {1, 1,1,1};
	int n = sizeof(a)/sizeof(a[0]);
//	cout <<n;
	cout<<findSmallInterVal(a, n);
	return 0;
}
