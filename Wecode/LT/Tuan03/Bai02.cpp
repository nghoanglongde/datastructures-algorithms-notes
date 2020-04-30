/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
[
]
template

###End banned keyword*/

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//###INSERT CODE HERE -
struct node {
    int info;
    node* pNext;
};
struct List {
    node* pHead;
    node* pTail;
};
void CreateList(List& l) {
    l.pHead = NULL;
    l.pTail = NULL;
}

node *createNode(int value)
{
    node *newNode = new node;
    newNode->info = value;
    newNode->pNext = NULL;
    return newNode;
}

void nhap(List &l, int &x){
    while(1){
        int data;
        cin >> data;
        if(data == 0){
            break;
        }
        else{
            node *temp = createNode(data);
            if(l.pHead == NULL){
                l.pHead = temp;
                l.pTail = l.pHead;
            }
            else{
                l.pTail->pNext = temp;
                l.pTail = temp;
            }
        }
    }
    cin >> x;
}
void xuat(List l){
    while(l.pHead){
        cout << l.pHead->info << " ";
        l.pHead = l.pHead->pNext;
    }
}
void Push(List &l, int data){
    node *temp = createNode(data);
    if(l.pHead == NULL){
        l.pHead = temp;
        l.pTail = l.pHead;
    }
    else{
        l.pTail->pNext = temp;
        l.pTail = temp;
    }
}
void mergelist(List l, int x){
    List l_chiahet, l_kochiahet;
    CreateList(l_chiahet);
    CreateList(l_kochiahet);
    while(l.pHead){
        if(l.pHead->info % x == 0){
            Push(l_chiahet, l.pHead->info);
        }
        else{
            Push(l_kochiahet, l.pHead->info);
        }
        l.pHead = l.pHead->pNext;
    }
    l_chiahet.pTail->pNext = l_kochiahet.pHead;
    xuat(l_chiahet);
}

int main(){
    List l;
    CreateList(l);
    int x;
    nhap(l, x);
    if (l.pHead == NULL) cout << "Danh sach rong.";
    else {
        mergelist(l, x);
    }
    return 0;
}


