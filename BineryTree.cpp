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

void NLR2(Tree t){
	if(t != NULL){
		stack<Node*> st;
		st.push(t);
		while(!st.empty()){
			Node* t = st.top();
			cout<<t<<endl;
			if(t->left != NULL){
				st.push(t->left);
			}
			if(t->right != NULL){
				st.push(t->right);
			}
		}
		
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

void ReplaceNode(Tree &x, Tree &y){
	if(y->left != NULL){
		ReplaceNode(x, y->left);
	}else{
		x->data = y->data;
		x = y;
		y = y->right;
	}
}


int countLeaf(Tree t){
	if(t == NULL){
		return 0;
	}
	if(t->left == NULL && t->right == NULL){
		return 1;
	}
	return countLeaf(t->left) + countLeaf(t->right);
}


void deleteNode(Tree &t, ElementType data){
	if(t == NULL){
		return;
	}
	if(t->data > data){
		deleteNode(t->left, data);
	}else if(t->data < data){
		deleteNode(t->right, data);
	}else{
		Node *temp = t;
		if(t->left == NULL){
			t = t->right;
		}else if(t->right == NULL){
			t = t->left;
		}else {
			ReplaceNode(temp, t->right);
		}
		free(temp);
	}
}

int main(){
	Tree t;
	InitTree(t);
	input(t);
	cout <<"NLR"<<endl;
	NLR(t);
	cout <<"NLR2"<<endl;
	NLR(t);
	cout <<"Leaf "<<countLeaf(t)<<endl;
//	cout <<"LNR"<<endl;
//	LNR(t);
//	cout <<"LRN"<<endl;
//	LRN(t);
	if(search(t, 8) != NULL){
		cout<<"Exist"<<endl;
	}else{
		cout<<"Not Exist"<<endl;
	}
	deleteNode(t, 6);
		cout <<"NLR"<<endl;
	NLR(t);	
	return 0;
}
