
//Bài toán: Xóa các phần tử trùng nhau, chỉ giữ lại một phần tử duy nhất.

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

void nhap(List &l){
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
}

void ReverseList(List& l){
    node *current = NULL;
    node *previous = NULL;

    while(l.pHead != NULL) {
        current = l.pHead;
        l.pHead = l.pHead->pNext;
        current->pNext = previous;
        previous = current;
    }
    l.pHead = current;
}

void DeleteNode(node *&previous, node *&check){
    previous->pNext = check->pNext;
}

void DeleteDuplicate(List& l){
    node *root = l.pHead;
    while(root != NULL){
        node *check = root->pNext; //trường hợp cuối danh sách
        node *previous = root;
        if(check == NULL)
            return;
        else{
            while(check != NULL){
                if(check->info == root->info){
                    DeleteNode(previous, check);
                }
                else{
                    previous = check;
                }
                check = check->pNext;
              
            }
        }
        root = root->pNext;
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
    if (l.pHead == NULL) cout << "Danh sach rong.";
    else {
        ReverseList(l);
        xuat(l);
        cout << endl;
        DeleteDuplicate(l);
        xuat(l);
    }
    return 0;
}

