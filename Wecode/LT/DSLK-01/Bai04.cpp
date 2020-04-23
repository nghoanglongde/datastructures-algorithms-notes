
//Bài toán: Xóa tất cả các node có giá trị = x trong danh sách liên kết đơn

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

node *createnode(int value)
{
    node *newnode = new node;
    newnode->info = value;
    newnode->pNext = NULL;
    return newnode;
}

void nhap(List &l){
    while(1){
        int info;
        cin >> info;
        if(info == 0){
            break;
        }
        else{
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

void ReverseList(List& l){
    node *current = NULL;
    node *previous = NULL;

    while(l.pHead != NULL)    {
        current = l.pHead;
        l.pHead = l.pHead->pNext;
        current->pNext = previous;
        previous = current;
    }
    l.pHead = current;
}

bool Search(List l, int x){
    node *check = l.pHead;
    while(check != NULL){
        if(check->info == x)
            return true;
        check = check->pNext;
    }
    return false;
}

void DelHead(node *&head){
    head = head->pNext;
}

void DeleteInfo(List& l, int num_del){
    if(l.pHead->info == num_del && l.pHead->pNext == NULL){
        DelHead(l.pHead);
    }
    else{
        node *previous = l.pHead;
        node *check = previous->pNext; //trường hợp cuối danh sách
        if(check == NULL)
            return;
        while(check != NULL){
            if(check->info == num_del){
                previous->pNext = check->pNext;
            }
            else{
                previous = check;
            }
            check = check->pNext;
        }
        if(l.pHead->info == num_del)
            l.pHead = l.pHead->pNext;
    }
}

void xuat(List l){
    while(l.pHead){
        cout << l.pHead->info << " ";
        l.pHead = l.pHead->pNext;
    }
}

int main(){
    List l;
    int num_del;
    CreateList(l);
    nhap(l);
    cin >> num_del;
    if (l.pHead == NULL) 
        cout << "Danh sach rong.";
    else if(Search(l, num_del)){
        DeleteInfo(l, num_del);
        if(l.pHead == NULL)
            cout << "Danh sach rong.";
        else
            xuat(l);
    }
    else{
        cout << "Khong tim thay " << num_del << " trong danh sach:" << endl;
        xuat(l);
    }
}


