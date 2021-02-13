#include <bits/stdc++.h>

using namespace std;

#define MaxLength 100;
typedef int ElementType;

typedef struct Node{
	ElementType data;
	Node* Top;
};

typedef Node* Stack;

void MakeNull_Stack(Stack& s){
	s = (Node*)malloc(sizeof(Node));
	s = NULL;	
}

int Empty_Stack(Stack s){
	return (s == NULL);
}

Node *createNode(ElementType n){
//	Node* p = new Node();
	Node* p = (Node*)malloc(sizeof(Node));
	if(p == NULL){
		return NULL;
	}
	p->data = n;
	p->Top = NULL;
	return p;
}

void Push_Stack(ElementType data, Stack& s){
	Node* p = createNode(data);
	if(s == NULL){
		s = p;
	}else{
		p->Top = s;
		s = p;
	}
}

int pop_stack(Stack& s){
	if(s == NULL){
		cout <<"Stack Empty"<<endl;
	}else{
		int temp = s->data;
		Node *t = s;
		s = s->Top;
		free(t);
		return temp;
	}
}
ElementType Top_Stack(Stack s){
	if(s == NULL){
		cout <<"Empty Stack"<<endl;
	}else{
		return s->data;
	}
}
int main(){
	
	Stack s;
	MakeNull_Stack(s);
	Push_Stack(2, s);
	Push_Stack(4, s);
//	Push_Stack(5, s);
	cout<<pop_stack(s)<<endl;
	cout<<pop_stack(s)<<endl;
	
	return 0;
}
