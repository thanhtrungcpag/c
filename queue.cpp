#include <bits/stdc++.h>

using namespace std;


typedef int ElementType;
typedef struct Node{
	ElementType data;
	Node *next;
};

typedef struct Queue{
	Node *front, *rear;
};

void makeQueue(Queue &q){
	q.front = NULL;
	q.rear = NULL;
}

Node *createNode(ElementType data){
	Node *p = (Node*)malloc(sizeof(Node));
	p->data = data;
	p->next = NULL;
	return p;
}

void push(Queue &q, ElementType data){
	Node *p = createNode(data);
	if(!q.front) q.front = q.rear = p;
	else{
		q.rear->next = p;
		q.rear = p;
	}
}

int top(Queue q){
	if(q.front == NULL){
		return 0;
	}
	return q.front->data;
}

int pop(Queue &q){
	if(q.front){
		Node *p = q.front;
		q.front = p->next;
		return p->data;	
	}
	return 0;
}

int main(){
	Queue q;
	makeQueue(q);
	push(q, 1);
//	push(q, 2);
//	push(q, 3);
	
	int t = pop(q);
	while(t){
		cout <<t<<endl;
		t = pop(q);
	}
	return 0;
}
