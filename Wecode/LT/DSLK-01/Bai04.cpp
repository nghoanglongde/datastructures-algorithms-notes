/*
Bài toán: Xóa tất cả các node có giá trị = x trong danh sách liên kết đơn

Viết chương trình nhập danh sách liên kết đơn với mỗi phần tử là một số nguyên và không biết trước lượng phần tử được nhập vào.
Việc nhập danh sách kết thúc khi giá trị nhập vào là 0 – không được tính trong danh sách.          
Tiếp theo, nhập vào số nguyên dương y, xóa tất cả node có info bằng y trong danh sách.

Input:

Danh sách gồm các số nguyên dương x ( 1 ≤ x ≤ 105) cách nhau bởi khoảng trắng. Dãy số kết thúc khi gặp số 0 (số 0 này không nằm trong danh sách).
Dòng tiếp theo chứa số nguyên y ( 1 ≤ y ≤ 106) cần xóa.
Tổng số lượng phần tử được nhập vào danh sách không quá 106.

Output:

Nếu danh sách ban đầu rỗng, in ra "Danh sach rong.".
Nếu danh sách ban đầu không rỗng và tìm thấy y trong danh sách:
Chương trình xuất danh sách sau khi xóa các node có info bằng y.
Nếu sau khi xóa các node có info bằng y ta thu được danh sách rỗng thì in “Danh sach rong.”.
Nếu danh sách ban đầu không rỗng và không tìm thấy y trong danh sach:
Dòng đầu chương trình xuất ra thông báo “Khong tim thay <y> trong danh sach:” 
Dòng thứ hai xuất danh sách đã nhập.

*/
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


