#include <bits/stdc++.h>

using namespace std;


#define MaxLength 100

typedef int ElementType;
typedef int Position;

typedef struct {
	ElementType Elements[MaxLength];
	Position Last;
} List;
// & khai bao tham so tham chieu
void MakeNull_List(List& L){
	L.Last = 0;
}

int Empty_List(List L){
	return L.Last == 0;
}

void Insert_List(ElementType x, Position p, List& L){
	if(L.Last == MaxLength){
		printf("full-Array");
	}else{
		if(L.Last + 1 < p || p < 1){
			printf("outscope");
		}else{
			Position q;
			for(int q = L.Last; q > p -1; q-- ){
				L.Elements[q] = L.Elements[q-1];
			}
			L.Elements[p-1] = x;
			L.Last++;
		}
	}
}

void Delete_List(Position p, List& L){
	if(L.Last + 1 < p || p < 1){
			printf("outscope");
	}else{
		
		for(Position start = p -1 ; start < L.Last; start++){
			L.Elements[start] = L.Elements[start+1];
		}
		L.Last--;
	}
}

void Print_List(List& L){
	for(int i = 0; i < L.Last; i++){
		printf("%d ", L.Elements[i]);
	}
}

int End_List(List L){
	return L.Last + 1; 
}

int Locate(ElementType x, List L){
	for(Position p = 1; p < L.Last; p++){
		if(L.Elements[p - 1] == x){
			return p;
		}
	}
	return End_List(L);
}

int main(){
	
	List L;
	MakeNull_List(L);
	Insert_List(1, 1,L);
	Insert_List(2, 2,L);
	Insert_List(3, 3,L);
	Insert_List(4, 4,L);
	Delete_List(4, L);
	Print_List(L);
	printf("\n %d",Locate(1, L));
	return 0;
}
