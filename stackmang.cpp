#include <bits/stdc++.h>

using namespace std;

#define MaxLength 100
typedef int ElememtType;
typedef struct Stack{
	ElememtType data[MaxLength];
	int top;
};

void MakeNull_Stack(Stack &s){
	s.top = 0;
}

int Empty_Stack(Stack s){
	return s.top == 0;
}



void Push_Stack(ElememtType data, Stack& s){
	if(s.top == MaxLength){
		cout<<"FullStack"<<endl;
	}else{
		int p = 1;
		for(int i = s.top; i > p - 1; i-- ){
			s.data[i] = s.data[i-1];
		}
		s.top++;
		s.data[p-1] = data; 
	}
}

int pop_stack(Stack& s){
	if(s.top == 0){
		cout<<"empty stack"<<endl;
		return 0;
	}else{
		ElememtType data = s.data[0];
		int q = 1;
		for(int i = q; i < s.top; i++ ){
			s.data[i-1] = s.data[i];
		}
		s.top--;
		return data;
	}
}

int Top_Stack(Stack s){
	if(s.top == 0){
		cout<<"Empty stack"<<endl;
		return 0;
	}else{
		return s.data[0];
	}
}

int main(){
	Stack s;
	MakeNull_Stack(s);
	Push_Stack(2, s);
	Push_Stack(4, s);
	Push_Stack(6, s);
	cout<<pop_stack(s)<<endl;
	cout<<pop_stack(s)<<endl;
	cout<<Top_Stack(s)<<endl;
	cout<<pop_stack(s)<<endl;
	
	return 0;
}
