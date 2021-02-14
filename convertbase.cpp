#include<bits/stdc++.h>

using namespace std;

typedef int ElementType;

typedef struct Node{
	ElementType data;
	Node *Top;
};

typedef Node *Stack;

void makeNullStack(Stack &s){
	s = (Node*)malloc(sizeof(Node));
	s->Top = NULL;
}


int EmptyStack(Stack s){
	return s->Top == NULL;
}

Node *createNode(ElementType n){
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->data = n;
	temp->Top = NULL;
	return temp;
}

void Push_Stack(ElementType data, Stack& s){
	Node *temp = createNode(data);
	if(s == NULL){
		s = temp;
	}else{
		temp->Top = s;
		s = temp;
	}
}

bool Pop_Stack(Stack& s, int &data){
	if(s->Top == NULL){
		return false;
	}else{
		data = s->data;
		Node *temp  = s;
		s = s->Top;
		free(temp);
		return true;
	}
}

void convertBase(Stack &s, int number, int base){
	while(number != 0){
		int x = number%base;
		Push_Stack(x, s);
		number /= base;
	}
}

void XuatStack(Stack &s)
{
    while (EmptyStack(s) != true)
    {
        int x;
//        Pop(s, x);
        Pop_Stack(s, x);
    //n?u x < 10 thi xu?t bình thu?ng
        if (x < 10)
        {
            cout << x;
        }
    //n?u x >= 10 thì xu?t ch? cái tuong ?ng
        else
        {
            if (x == 10)
            {
                cout << "A";
            }
            else if (x == 11)
            {
                cout << "B";
            }
            else if (x == 12)
            {
                cout << "C";
            }
            else if (x == 13)
            {
                cout << "D";
            }
            else if (x == 14)
            {
                cout << "E";
            }
            else if (x == 15)
            {
                cout << "F";
            }
        }
    }
}

int main(){
	Stack s;
	makeNullStack(s);
	convertBase(s, 15, 16);
	XuatStack(s);
	
	return 0;
}
