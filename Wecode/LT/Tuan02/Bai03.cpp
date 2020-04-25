//Bài toán: Sắp xếp Linked List

/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
[]
template
###End banned keyword*/

#include <iostream>
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

void xuat(List l){

    while(l.pHead){
        cout << l.pHead->info << " ";
        l.pHead = l.pHead->pNext;
    }
}

int main()
{
    List l;
    CreateList(l);
    nhap(l);
    if (l.pHead == NULL) cout << "Danh sach rong.";
    else {
        cout << "Danh sach vua nhap la: ";
        xuat(l);
        SortIncrease(l);
        cout << endl << "Danh sach sau khi sap xep la: ";
        xuat(l);
    }
    return 0;
}