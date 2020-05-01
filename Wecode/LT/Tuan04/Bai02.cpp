/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
[
]
template
###End banned keyword*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

//###INSERT CODE HERE -

struct node
{
	char info;
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
node* CreateNode(char x){
	node *newNode = new node;
    newNode->info = x;
    newNode->pNext = NULL;
    return newNode;
}
bool isEmpty(List l){
	if(l.pHead == NULL){
		return true;
	}
	return false;
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
void enstack(List& l, char x){
	node *p = CreateNode(x);
    AddHead(l, p);
}

void pop(List &l){
    if(isEmpty(l)){
        return;
    }
    node *p = l.pHead;
    l.pHead = l.pHead->pNext;
    delete p;
}

char top(List l){
    if(isEmpty(l)){
        return 'r';
    }
    return l.pHead->info;
}
void xuly(List l, string text){
    int socapngoac = 0, ngoac_open = 0, ngoac_close = 0;
    for(int i = 0;i < text.length();i++){
        if(text.at(i) == '('){
            char temp = top(l);
            enstack(l, text.at(i));
            ngoac_open++;
        }
        else if(text.at(i) == ')'){
            ngoac_close++;
            char compare = top(l);
            if(compare == '('){
                pop(l);
                socapngoac++;
                --ngoac_close;
                --ngoac_open;
            }
            else{
                enstack(l, text.at(i));
            }
        }
    }
    if(isEmpty(l)){
        cout << "So cap dau ngoac tron hop le la: " << socapngoac;
    }
    else{
        if(ngoac_open == ngoac_close){
            cout << "Ngoac dat sai vi tri";
        }
        else if(ngoac_open > ngoac_close && (ngoac_close > 0)){
            cout << "Ngoac dat sai vi tri va thieu ngoac dong";
        }
        else if(ngoac_open < ngoac_close && (ngoac_open > 0)){
            cout << "Ngoac dat sai vi tri va thieu ngoac mo";
        }
        else if(ngoac_open > ngoac_close && (ngoac_close == 0)){
            cout << "Thieu ngoac dong";
        }
        else if(ngoac_open < ngoac_close && (ngoac_open == 0)){
            cout << "Thieu ngoac mo";
        }
    }
}

int main()
{
	List l;
	CreateList(l);
	string text; getline(cin, text);
    xuly(l, text);
}