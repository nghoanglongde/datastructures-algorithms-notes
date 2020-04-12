//Bài toán: Thao tác trên danh sách liên kết

/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
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

void DeleteInfo(List& l, long long num_del){
    if(l.pHead == NULL){
        return;
    }
    else{
        if(l.pHead->info == num_del && l.pHead->pNext == NULL){
            l.pHead = l.pHead->pNext;
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
}

void addnode(List &l, long long q, long long value){
    node *temp = createnode(value);
    if(q == 1){
        if(l.pHead == NULL){
            l.pHead = temp;
            l.pTail = l.pHead;
            return;
        }
        temp->pNext = l.pHead;
        l.pHead = temp;
    }
    else if(q == 2){
        if(l.pHead == NULL){
            l.pHead = temp;
            l.pTail = l.pHead;
            return;
        }
        l.pTail->pNext = temp;
        l.pTail = temp;
    }
    else{
        DeleteInfo(l, value);
    }

}
void nhap(List &l){
    while(1){
        long long info;
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
    while(1){
        long long q, k;
        cin >> q;
        if(q == 0)
            return;
        cin >> k;
        addnode(l, q, k);
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
    CreateList(l);
    nhap(l);
    xuat(l);
}

