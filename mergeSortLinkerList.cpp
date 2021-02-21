#include <bits/stdc++.h>

using namespace std;


typedef struct Node{
	int value;
	Node *Next;
	
};

typedef Node* List;

void init(List &L){
	L = (Node*)malloc(sizeof(Node));
	L = NULL;
}

int lengthList(List L){
	int n = 0;
	Node *Q = L;
	if(Q != NULL){
		n++;
		Q = Q->Next;
	}
	return n;
}

Node *createNode(int val){
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->value = val;
	temp->Next = NULL;
	return temp;
}

void pushHead(List &L, int val){
	Node *temp = createNode(val);
	temp->Next = L;
	L = temp;
}

void out(List L){
	Node *Q = L;
	while(Q != NULL){
		cout <<Q->value<<endl;
		Q = Q->Next;
	}
}

Node *getMid(List L){
	if(L == NULL) return L;
	Node *q, *p;
	p = q = L;
	while(q->Next != NULL && q->Next->Next !=  NULL){
		p = p->Next;
		q = q->Next->Next;
	}
	return p;
}

void split(List L, List &L1, List &L2){
	Node *mid = getMid(L);
	L1 = L;
	L2 = mid->Next;
	mid->Next = NULL;
}

Node *merge(List L1, List L2){
	if(!L1) return L2;
	else if(!L2) return L1;
	List L = NULL;
	if(L1->value < L2->value){
		L = L1;
		L->Next = merge(L1->Next, L2);
	}else{
		L = L2;
		L->Next = merge(L1, L2->Next);
	}
	return L;
}

void mergeSort(List &L){
	if(!L || !L->Next) return;
	Node *L1 = NULL, *L2 = NULL;
	split(L, L1, L2);
	mergeSort(L1);
	mergeSort(L2); 
	L =  merge(L1, L2);
	
}

int main(){
	List L;
	init(L);
	pushHead(L , 3);
	pushHead(L , 5);
	pushHead(L , 2);
	pushHead(L , 6);
	pushHead(L , 1);
	pushHead(L , 9);
	mergeSort(L);
	out(L);
	
	return 0;
}
