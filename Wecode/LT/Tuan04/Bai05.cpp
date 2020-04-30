/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
struct
template
###End banned keyword*/
#include <string>
#include <iostream>
using namespace std;
struct node {
    char info;
    node* pNext;
};
struct List {
    node* pHead;
    node* pTail;
};
void CreateList(List& l);
node* CreateNode(char x);
void AddTail(List& l, node* p);
void Xuat(List l);
void enqueue(List& l, char x);
int dequeue(List& l,char& trave);
bool isEmpty(List l);
int main()
{
    char c;
    cin >> c;
    string s = "";
    cin >> s;
    List queue;
    CreateList(queue);
//###INSERT CODE HERE -
    if(s.empty()){
        cout << "Chuoi rong.";
        return 0;
    }
    for(int i = 0;i < s.length();i++){
        if(c != s[i]){
            enqueue(queue, s[i]);
        }
        else{
            dequeue(queue, s[i]);
        }
    }
    Xuat(queue);
}
void CreateList(List& l){
	l.pHead = NULL;
	l.pTail = NULL;
}
node* CreateNode(char x){
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
void enqueue(List& l, char x){
	node *temp = CreateNode(x);
	AddTail(l, temp);
}

int dequeue(List& l,char& trave){
    if(isEmpty(l)){
        cout << "Hang doi rong khong xuat duoc." << endl;
        return 0;
    }
    node *ptrdel = l.pHead;
    cout << l.pHead->info << endl;
    l.pHead = l.pHead->pNext;
    delete ptrdel;
    return 0;
}

void Xuat(List l){
    if(isEmpty(l)){
        cout << "Hang doi rong.";
        return;
    }
    cout << "Cac gia tri co trong hang doi la: ";
    while(l.pHead){
        cout << l.pHead->info;
        l.pHead = l.pHead->pNext;
    }
}
