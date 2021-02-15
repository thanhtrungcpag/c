#include <bits/stdc++.h>

using namespace std;

typedef int ElementType;
typedef struct Node{
	ElementType data;
	Node *left, *right;
};

typedef Node *Tree;

void InitTree(Tree &t){
	t = NULL;
}

Node *createNode(ElementType data){
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void AddNodeIntoTree(Tree &t, ElementType data){
	
	if(t == NULL){
		Node *temp = createNode(data);
		t = temp;
	}else{
		if(t->data >= data){
			AddNodeIntoTree(t->left, data);
		}else{
			AddNodeIntoTree(t->right, data);
		}
	}
}

void NLR(Tree t){
	if(t != NULL){
		cout <<t->data<<endl;
		NLR(t->left);
		NLR(t->right);
	}
}
void LNR(Tree t){
	if(t != NULL){
		NLR(t->left);
		cout <<t->data<<endl;
		NLR(t->right);
	}
}

void LRN(Tree t){
	if(t != NULL){
		NLR(t->left);
		NLR(t->right);
		cout <<t->data<<endl;
	}
}

void input(Tree &t){
	int data;
	cin >>data;
	while(data != -1){
		AddNodeIntoTree(t, data);
		cin >>data;
	}
}

Node *search(Tree t, ElementType val){
	if(t == NULL) return NULL;
	if(t->data > val){
		search(t->left, val);
	}else if(t->data < val){
		search(t->right, val);
	}else{
		return t;
	}
}

int main(){
	Tree t;
	InitTree(t);
	input(t);
	cout <<"NLR"<<endl;
	NLR(t);
	cout <<"LNR"<<endl;
	LNR(t);
	cout <<"LRN"<<endl;
	LRN(t);
	if(search(t, 8) != NULL){
		cout<<"Exist"<<endl;
	}else{
		cout<<"Not Exist"<<endl;
	}
	
	return 0;
}
