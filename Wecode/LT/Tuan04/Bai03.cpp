/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
struct
template
###End banned keyword*/
#include <iostream>
using namespace std;
struct node
{
	int info;
	node* pNext;
};
struct List
{
	node* pHead;
};
void CreateList(List& l)
{
	l.pHead = NULL;
}
node* CreateNode(int x);
void AddHead(List& l, node* p);
void enstack(List& l, int x);
void destack(List& l);
bool isEmpty(List l);
int main()
{
	List st;
	CreateList(st);
	long long x;
	cin >> x;
//###INSERT CODE HERE -
	enstack(st, x);
	destack(st);
	
}
bool isEmpty(List l){
	if(l.pHead == NULL){
		return true;
	}
	return false;
}
void enstack(List& l, int x){
	while(x != 0){
		int temp = x % 2;
		node *p = CreateNode(temp);
		AddHead(l, p);
		x = x / 2;
	}
}
void destack(List& l){
	if(isEmpty(l)){
		cout << "0";
		return;
	}
	while(l.pHead){
		cout << l.pHead->info;
		l.pHead = l.pHead->pNext;
	}
}
node* CreateNode(int x){
	node *newNode = new node;
    newNode->info = x;
    newNode->pNext = NULL;
    return newNode;
}

void AddHead(List& l, node* p){
	if (isEmpty(l)) {
		l.pHead = p;
	}
	else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
