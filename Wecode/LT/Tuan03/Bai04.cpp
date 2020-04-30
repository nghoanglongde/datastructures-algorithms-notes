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
bool isPrime(int n) {
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return n > 1;
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
void nhap(List &l, List &snt){
    while(1){
        int data;
        cin >> data;
        if(data == 0){
            return;
        }
        else{
            Push(l, data);
            if(isPrime(data)){
                Push(snt, data);
            }
        }
    }
}
void SortIncrease(List &l){
    node *root_count = l.pHead;
    int count = 0;
    while(root_count){
        count++;
        root_count = root_count->pNext;
    }
    while(count--){
        node *B = NULL;
        node *sort_in = l.pHead;
        while(sort_in){
            B = sort_in->pNext;
            if(B == NULL)
                break;
            if(sort_in->info > B->info){
                long long temp = sort_in->info;
                sort_in->info = B->info;
                B->info = temp;
            }
            sort_in = sort_in->pNext;
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
void xuat(List l){
    while(l.pHead){
        cout << l.pHead->info << " ";
        l.pHead = l.pHead->pNext;
    }
}

void changelist(List l, List snt){
    SortIncrease(snt);
    while(l.pHead){
        if(isPrime(l.pHead->info)){
            l.pHead->info = snt.pHead->info;
            snt.pHead = snt.pHead->pNext;
        }
        cout << l.pHead->info << " ";
        l.pHead = l.pHead->pNext;
    }
}
int main(){
    List l, snt;
    CreateList(l);
    CreateList(snt);
    nhap(l, snt);
    if (l.pHead == NULL) cout << "Danh sach rong.";
    else {
        ReverseList(l);
        xuat(l);
        cout << endl;
        changelist(l, snt);
    }
    return 0;
}



