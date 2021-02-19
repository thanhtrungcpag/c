#include<bits/stdc++.h>

using namespace std;

// uoc cua N, N chia het cho uoc.
// uoc chung lon nhat A, B. so lon nhat chia het cho a va b
// boi cua N, la nhung so chia het cho N du 0
// boi chung AB. so nho nhat chia het cho AB

//UCLN
int GCD1(int a, int b){
	if(a == 0){
		return b;
	}
	if(b == 0){
		return a;
	}
	if(a == b) return a;
	if(a > b){
		return GCD(a - b, b);
	}else{
		return(a, b - a);
	}
}

int GCD2(int a, int b){
	if(a == 0){
		return b;
	}
	if(b == 0){
		return a;
	}
	while(a != b){
		if(a > b){
			a = a -b;
		}else{
			b = b - a;
		}
	}
	return a;
}

int GCD3(int a, int b){
	while(b != 0){
		int x = b;
		b = a%b;
		a = x;
	}
}

int BCNN(int a, int b){
	return a*b/GCD(a,b);
}

int main(){
	return 0;
}
