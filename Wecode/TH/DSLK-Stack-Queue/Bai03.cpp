//Hoán đổi giá trị nhỏ nhất lên đầu

/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
[
]
###End banned keyword*/

#include <iostream>
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
void xuat(List l){
    while(l.pHead){
        cout << l.pHead->info << " ";
        l.pHead = l.pHead->pNext;
    }
}
void calculate(List &l){
    long long minE = (int)1e6;
    node *root = l.pHead;
    node *temp = NULL;
    while(root){
        if(root->info < minE){
            minE = root->info;
            temp = root;
        }
        root = root->pNext;
    }
    int temp_change;
    temp_change = l.pHead->info;
    l.pHead->info = minE;
    temp->info = temp_change;
}


int main()
{
    List l;
    CreateList(l);
    nhap(l);
    if (l.pHead == NULL) cout << "Danh sach rong.";
    else {
        calculate(l);
        xuat(l);
    }
    return 0;
}