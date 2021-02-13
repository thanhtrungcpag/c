#include <bits/stdc++.h>

using namespace std;

void hoandoi(int a, int b){
	int temp = a;
	a = b;
	b = temp;
}

void hoandoi1(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void hoandoi2(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

int main(){
	
	int a= 3, b = 4;
	hoandoi(a,b);
	cout <<a<<" "<<b<<endl;
	hoandoi1(&a, &b);
	cout <<a<<" "<<b<<endl;
	hoandoi2(a, b);
	cout <<a<<" "<<b<<endl;
	return 0;
}
