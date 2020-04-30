/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
struct
template
[]
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
	node* pTail;
};
void CreateList(List& l);
node* CreateNode(int x);
void AddTail(List& l, node* p);
void enqueue(List& l, int x);
void dequeue(List& l);
bool isEmpty(List l);
int main()
{
	List q;
	CreateList(q);
	long long x;
	cin >> x;
//###INSERT CODE HERE -
	while(1){
		enqueue(q, x % 10);
		x = x / 10;
		if(x == 0)
			break;
	}
	dequeue(q);
}
void CreateList(List& l){
	l.pHead = NULL;
	l.pTail = NULL;
}
node* CreateNode(int x){
	node *temp = new node;
    temp->info = x;
    temp->pNext = NULL;
    return temp;
}
bool isEmpty(List l){
	return (l.pHead == NULL) ? true : false;
}
void AddTail(List& l, node* p){
    if (isEmpty(l))
    {
        l.pHead = p;
        l.pTail = l.pHead;
		return;
    }
    l.pTail->pNext = p;
    l.pTail = p;
}
void enqueue(List& l, int x){
	node *temp = CreateNode(x);
	AddTail(l, temp);
}

void dequeue(List& l){
	node *ptr = l.pHead;
	bool check = false;
	while(ptr != NULL){
		if(ptr->info != 0){
			check = true;
		}
		if(check){
			cout << ptr->info;
		}
		ptr = ptr->pNext;
	}
	if(!check){
		cout << "0";
	}
}


