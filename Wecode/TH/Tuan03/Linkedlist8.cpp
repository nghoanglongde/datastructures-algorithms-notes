/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
[
]
template
###End banned keyword*/

#include <iostream>
#include <math.h>
using namespace std;

//###INSERT CODE HERE -

struct Node {
	int data;
	Node* pNext;
};
struct CreateList {
	Node* pHead;
	Node* pTail;	
	CreateList() {
		pHead = NULL;
		pTail = NULL;
	}
};
void AddHead(CreateList& l, int data) {
	Node* p = new Node;
	p->data = data;
	if (l.pHead == NULL) {
		l.pHead = p;
		l.pTail = p;
		p->pNext = NULL;
	}
	else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void AddTail(CreateList& l, int data) {
	Node* p = new Node;
	p->data = data;
	p->pNext = NULL;
	if (l.pHead == NULL) {
		l.pHead = p;
		l.pTail = p;
	}
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void DeleteHead(CreateList& l) {
	if (l.pHead != NULL) {
		Node* p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
	}
}
void DeleteTail(CreateList& l) {
	if (l.pHead != NULL) {
		Node* p = l.pHead;
		if (l.pHead == l.pTail) {
			l.pHead = NULL;
		}
		else {
			while (p->pNext != l.pTail) {
				p = p->pNext;
			}
			delete l.pTail;
			l.pTail = p;
			l.pTail->pNext = NULL;
		}
	}
}
void AddNode(CreateList& l, int v, int p) {
	int dem = 0;
	Node* temp = l.pHead;
	if (p == 0) {
		AddHead(l, v);
	}
	else {
		while (temp != NULL) {
			dem++;
			if (dem == p) {
				if (temp == l.pTail) {
					AddTail(l, v);
					break;
				}
				else {
					Node* a = new Node;
					a->pNext = temp->pNext;
					a->data = v;
					temp->pNext = a;
					break;
				}
			}
			
			temp = temp->pNext;
		}
	}
}
int TimKiem(CreateList l, int v) {
	Node* p = l.pHead;
	if (p == NULL) {
		return -1;
	}
	int dem = 0;
	while (p != NULL) {
		if (p->data == v) {
			return dem;
		}
		dem++;
		p = p->pNext;
	}
	return -1;
}
void XuatList(CreateList l) {
	Node* p = l.pHead;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->pNext;
	}
}
void Nhap() {
	int n, t;
	cin >> n >> t;
	CreateList l;
	for (int i = 1; i <= n; i++) {
		int data;
		cin >> data;
		AddTail(l, data);
	}
	while(t--){
		int control; cin >> control;
		switch (control)
		{
			case 0:
				int data; cin >> data;
				AddHead(l, data);
				break;
			case 1:
				int data; cin >> data;
				AddTail(l, data);
				break;
			case 2:
				DeleteHead(l);
				break;
			case 3:
				DeleteTail(l);
				break;
			case 4:
				int data, vitri;
				cin >> data;
				cin >> vitri;
				AddNode(l, data, vitri);
				break;
			case 5:
				int v;
				cin >> v;
				cout << TimKiem(l, v) << endl;
				break;

			default:
				break;
		}
	}

	XuatList(l);
}
int main()
{
	Nhap();
	return 0;
}