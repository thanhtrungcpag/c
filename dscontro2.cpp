#include <bits/stdc++.h>

using namespace std;

typedef int ElementType;

typedef struct Node{
	ElementType data;
	Node* next;
};

typedef Node* Position;
typedef Position List;

void Make_Null(List &Header){
	Header = (Node*) malloc(sizeof(Node));
	Header = NULL;
}

int Empty_List(List L){
	return L->next == NULL;
}

int LenghList(List L){
	int l = 0;
	Node *P = L;
	while(P != NULL){
		l++;
		P = P->next;
	}
	
	
	return l;
}

Node *createNode(ElementType n){
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->data = n;
	temp->next = NULL;
	return temp;
}

void InsertHeadNode(List &L, ElementType n){
	Node *P = createNode(n);
	P->next = L;
	L = P;
}

void InsertNode(List &L, ElementType n, int k){
	int start = 1;
	if(k < 1 || k > LenghList(L) + 1){
		cout<<"Out of scope"<<endl;
	}else{
		Node *P = createNode(n);
		if( k == 1 ){
			InsertHeadNode(L, n);
		}else{
			Node *Q = L;
			while(Q != NULL && start != k -1){
				start++;
				Q = Q->next;
			}
			P->next = Q->next;
			Q->next = P;
		}
	}
}


int searchElement(ElementType n, List L){
	Node* Q = L;
	int i = 1;
	while(Q != NULL){
		if(Q->data == n) return i;
		Q = Q->next;
		i++;
	}
	return 0;
}

void RemoveHeader(List &L, ElementType &n){
	n = L->data;
	L = L->next;
}

void Remove(List &L, ElementType &x, int k){
	if(k < 1 || k > LenghList(L) + 1){
		cout<<"Out of scope"<<endl;
	}else{
		if(k == 1) {
			RemoveHeader(L, x);
			return;
		}
		int start = 1;
		Node *Q = L;
		while(Q->next != NULL && start != k - 1 ){
			Q = Q->next;
			start++;
		}
		Node *T = Q->next;
		Q->next = T->next;
		free(T);
	}
	
}

void Output(List L){
	Node *Q = L;
	while(Q != NULL){
		cout <<Q->data<<endl;
		Q = Q->next;
	}
}

int main(){
	
	List L;
	Make_Null(L);
	InsertNode(L, 1, 1);
	InsertNode(L, 2, 2);
	InsertNode(L, 3, 3);
	InsertNode(L, 4, 4);
	int temp;
	Remove(L, temp, 1);
	Output(L);
	return 0;
}
