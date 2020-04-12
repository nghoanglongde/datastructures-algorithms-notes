//Bài toán: Tìm kiếm phần tử nằm ở giữa danh sách liên kết

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

void nhap(List &l){
    while(1){
        long long info;
        cin >> info;
        if(info == 0){
            return;
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
node * middleNode(node *head) {
        node *A = head;
        node *B = head;
        while(B != NULL) {
            B = B->pNext;
            if(B == NULL) {
                return A;
            }
            A = A->pNext;
            B = B->pNext;
        }
        return A;
    }

int main(){
    List l;
    CreateList(l);
    nhap(l);
    node *ptr = middleNode(l.pHead);
    cout << ptr->info;
}

