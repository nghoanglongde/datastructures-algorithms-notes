
//Bài toán: Xóa phần tử có giá trị x được nhập vào, phần tử đc xóa là phần tử đầu tiên đc tìm thấy


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

    while(l.pHead != NULL)    {
        current = l.pHead;
        l.pHead = l.pHead->pNext;
        current->pNext = previous;
        previous = current;
    }
    l.pHead = current;
}


void DeleteNode(List& l, node *&ptr, int num_del){
    if(l.pHead->info == num_del && l.pHead->pNext == NULL){
        //trường hợp phần tử cần xóa là ô ở vị trí đầu tiên và list chỉ có 1 phần tử
        l.pHead = l.pHead->pNext;
    }
    else if(l.pHead->info == num_del && l.pHead->pNext != NULL){
        //trường hợp phần tử cần xóa là ô ở vị trí đầu tiên nhưng list có > 1 phần tử
        //điều kiện l.pHead->info == numdel là để kiểm tra phần tử cần xóa là ô ở vị trí đầu tiên hay là ô thứ 2 vì
        //hàm Search cơ chế trả về là ô nằm trước ô cần xóa nhưng nếu là ô pHead thì nó trả về ô pHead chứ k có ô nào trước pHead cả
        l.pHead = l.pHead->pNext;
    }
    else{
        //Các trường hợp không phải ô nằm ở đầu
        ptr->pNext = ptr->pNext->pNext;
    }
}

node * Search(List l, int x){
    node *root = l.pHead;
    if(root->info == x){
        return root;
    }
    else{
        while(root->pNext != NULL){
            if(root->pNext->info == x)
                return root;
            root = root->pNext;
        }
        return NULL;
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
    if (l.pHead == NULL) cout << "Danh sach rong.";
    else {
        ReverseList(l);
        node *ptr = Search(l, num_del);
        if(ptr){
            DeleteNode(l, ptr, num_del);
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
    return 0;
}
