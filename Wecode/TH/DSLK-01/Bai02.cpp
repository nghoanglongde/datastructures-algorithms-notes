//Bài toán: Cộng 2 danh sách liên kết đơn

/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
[
]
###End banned keyword*/

#include <iostream>
using namespace std;

struct NODE {
	int n;
	NODE* next;
};
struct LIST {
	NODE* Head;
	NODE* Tail;
};
void createLIST(LIST& l) {
	l.Head = NULL;
	l.Tail = NULL;
}
void inputList(LIST& l) {
	while (1) {
		long long x;
		cin >> x;
		if (x == -1) {
			break;
		}
		else {
			NODE* newnode = new NODE;
			newnode->n = x;
			newnode->next = NULL;
			if (l.Head == NULL) {
				l.Head = newnode;
				l.Tail = newnode;
			}
			else {
				l.Tail->next = newnode;
				l.Tail = newnode;
			}
		}
	}
}

void ReverseList(LIST& l) {
	if (l.Head == l.Tail)
		return;
	NODE* p = l.Head;
	NODE* q = p->next;
	l.Head = q->next;
	if (l.Head == NULL)
	{
		l.Head = p;
		q = p->next;
		int temp;
		temp = p->n;
		p->n = q->n;
		q->n = temp;
	}
	else
	{
		p->next = NULL;
		l.Tail = p;
		q->next = p;
		while (l.Head->next != NULL)
		{
			p = q;
			q = l.Head;
			l.Head = l.Head->next;
			q->next = p;
		}
		q->next = p;
		l.Head->next = q;
	}
}
LIST sumLIST(LIST l1 , LIST l2, LIST &result) {
	ReverseList(l1);
	ReverseList(l2);
	NODE* p = l1.Head;
	int a = 0;
	while (p != NULL) {
		a = a * 10;
		a = a + p->n;
		p = p->next;
	}
	NODE* q = l2.Head;
	int b = 0;
	while (q != NULL) {
		b = b * 10;
		b = b + q->n;
		q = q->next;
	}
	NODE* temp = new NODE;
	temp->n = a + b;
	temp->next = NULL;
	result.Head = temp;
	result.Tail = temp;
	return result;
}

void printLIST(LIST &list)
{
	NODE*p = list.Head;
	if (p == NULL)
		cout << "null";
	else
	{
		while (p != NULL)
		{
			cout << p->n;
			p = p->next;
		}
	}
}


int main()
{
	
	LIST L1;
	createLIST(L1);
	LIST L2;
	createLIST(L2);
	LIST result;
	createLIST(result);

	inputList(L1);
	inputList(L2);
	
	sumLIST(L1, L2,result);

	printLIST(result);


	return 0;
}
