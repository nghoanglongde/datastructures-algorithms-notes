//Bài toán: Hoán đổi phần tử trong danh sách liên kết đơn theo cặp

/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
[
]
###End banned keyword*/

#include <iostream>
using namespace std;

struct node {
    long long info;
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

node *createnode(long long value)
{
    node *newnode = new node;
    newnode->info = value;
    newnode->pNext = NULL;
    return newnode;
}

void nhap(List &l,long long &count){
    while(1){
        long long info;
        cin >> info;
        if(info == 0){
            return;
        }
        else{
            count++;
            node *temp = createnode(info);

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
void swapNODE(List &l, long long count) {
    node *A = l.pHead;
    while(1){
        if(A == NULL)
            return;
        long long temp;
        node *B = A->pNext;
        if(B == NULL)
            break;
        temp = A->info;
        A->info = B->info;
        B->info = temp;
        A = B->pNext;
    }
    
    
}
void xuat(List l){
    if(l.pHead == NULL){
        cout << "null";
    }
    else{
        while(l.pHead){
            cout << l.pHead->info << " ";
            l.pHead = l.pHead->pNext;
        }
    }
}
int main(){
    List l;
    long long count = 0;
    CreateList(l);
    nhap(l, count);
    swapNODE(l, count);
    xuat(l);
}

