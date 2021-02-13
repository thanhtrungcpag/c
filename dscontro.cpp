#include <bits/stdc++.h>

using namespace std;


typedef long ELementType;

struct Node{
	ELementType Element;
	Node* Next;
};

typedef Node* Position;
typedef Position List;

void MakeNull_List(List& Header){
	Header = (Node*)malloc(sizeof(Node));
	Header->Next = NULL;
}

int EmptyList(List L){
	return L->Next == NULL; 
}

void Insert_List(ELementType x, Position p, List& Header){
	Position T = (Node*)malloc(sizeof(Node));
	T->Element = x;
	T->Next = p->Next;
	p->Next = T;
}

void Delete_List(Position p, List& L){
	Position T;
	if(p->Next != NULL){
		T = p->Next;
		p->Next = T->Next;
		free(T);
	}
}

Position Locate(ELementType x, List L){
	Position P = L;
	while(P->Next != NULL){
		if(P->Element == x) return P;
		P = P->Next;
	}
	return P;
}

int main(){
	List L;
	
	MakeNull_List(L);
	cout <<EmptyList(L)<<endl;
	return 0;
}

//https://nguyenvanhieu.vn/danh-sach-lien-ket-don/
