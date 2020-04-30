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
            return;
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
}
bool isPrime(int n) {
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return n > 1;
}
void xuat(List l){
    int pos = 1;
    while(l.pHead){
        if(pos % 2 == 0 && isPrime(l.pHead->info)){
            cout << l.pHead->info << " ";
        }
        l.pHead = l.pHead->pNext;
        ++pos;
    }
}

int main(){
    List l;
    CreateList(l);
    int x;
    nhap(l, x);
    if (l.pHead == NULL) cout << "Danh sach rong.";
    else {
        xuat(l);
    }
    return 0;
}



