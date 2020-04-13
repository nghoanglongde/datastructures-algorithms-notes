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
void middleNode(node *head, long long count) {
    node *A = head;
    for(long long i = 1;i <= (count / 2);i++){
        A = A->pNext;
    }
    cout << A->info;
}

int main(){
    List l;
    long long count = 0;
    CreateList(l);
    nhap(l, count);
    middleNode(l.pHead, count);
}
