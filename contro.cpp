#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int x = 10;
	// in dia chi cua x
	cout << &x<<endl;
	// gia tri o bo nho dia chi cua bien x
	cout << *(&x)<<endl;
	// gia tri cua bien x
	cout << x <<endl;
	int y = 2;
	int *m;
	m = &y; 
	*m = 7;
	// khai bao dung: int *m, int* m, int * m
	//con tro chi den dia chi so nguyen
	// m dia chi cua gia tri
	cout <<m<<endl;
	cout <<*m<<endl;
	cout <<y<<endl;
	
	char *cAdd; // 1byte
	int *iAdd; //4 byte
	struct something{
		int a1, a2, a3;
	};
	
	something *st;
	cout <<sizeof(cAdd)<<endl;
	cout <<sizeof(iAdd)<<endl;
	cout <<sizeof(st)<<endl;
	
	
	return 0;
}
