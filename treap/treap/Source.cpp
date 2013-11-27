#include<iostream>
using namespace std;

// Structure of Treap
//lchild: left pointer pointing to treap
//rchild: right pointer pointing to treap
struct treap{
	treap* lchild;
	char key;
	int data;
	treap* rchild;
};

//left rotation function
void leftR(treap* &T){
			treap* Y;

			Y = T->rchild;
			T->rchild = Y->lchild;
			Y->lchild = T;
			T = Y;
}

//right rotation function
void rightR(treap* &T){
			treap* Y;

			Y = T->lchild;
			T->lchild = Y->rchild;
			Y->rchild = T;
			T = Y;
}

//Double left rotation function
void doubleL(treap* &T){
	rightR(T->rchild);
	leftR(T);
}

//insert function for inserting key and data to TREAP
// c is key
// k is data
void insert(treap* &T , char c , int k){
	if(T==NULL){
		//cout<<"ohh";
		T = new(treap);
		T->key  = c;
		T->data = k;
		T->lchild = NULL;
		T->rchild =  NULL;
	}

	else{
		if(T->key > c){
			insert(T->lchild , c , k);
			if(T->data < k){
				rightR(T);
		}
		}
		else{
			insert(T->rchild , c, k);
			if(T->data < k)
				leftR(T);
		}
	}
}

//post order printing of TREAP Tree
void print(treap* T ){
	if(T!=NULL){
		cout<<endl<<T->key<<" "<<T->data;
		print(T->lchild);
		print(T->rchild);
	}
}

//function for searching a key in TREAP and returning a pointer to it
treap* search(treap* T , char k){
	if(T!=NULL){
		if(k < T->key ){
			return search(T->lchild , k);
		}
		else if(k > T->key){
			return search(T->rchild , k);
		}
		else{
			return T;
		}
	}
}


//Delete function for deleting a TREAP node T
void deleten(treap* T ){
	if( T->rchild != NULL || T->lchild != NULL){
		if(T->lchild == NULL || T->rchild == NULL){
			if(T->lchild == NULL){
				leftR(T);
				print(T);
				cout<<endl;
				deleten(T->lchild);
			}
			else{
				rightR(T);
				print(T);
				cout<<endl;
				deleten(T->rchild);
			}
		}
		else{
			if( T->rchild->data > T->lchild->data ){
				leftR(T);
				print(T);
				cout<<endl;
				deleten(T->lchild);
			}
			else{
				rightR(T);
				print(T);
				cout<<endl;
				deleten(T->rchild);
			}
		}
	}
}

////MAIN FUNCTION
int main(){
	treap *S , *L;
	L = new(treap); S = L;
	char c;
	int x;

	cout<<"enter the value: ";
	cin>>x;
	cout<<endl<<"enter the key: ";
	cin>>c;

	L->key = c;
	L->data = x;
	L->lchild = NULL;
	L->rchild = NULL;

	cout<<endl<<"enter the value: ";
	cin>>x;
	cout<<endl<<"enter the key: ";
	cin>>c;

	while(x!=-1){
		insert(L , c, x);

		cout<<endl<<"enter the value: ";
		cin>>x;
		cout<<endl<<"enter the key: ";
		cin>>c;
	}

	//cout<<S->lchild->key;
	print(S);	
	S = search(S , 'C');
	cout<<S->data<<endl<<endl;
	deleten(S);
	print(L);
	return 0;
}