//Bài toán: Kiểm tra dãy tăng, giảm hoặc không tăng không giảm

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

bool checkIncrease(List l){
    int count_duplicate = 1;
    int num_node = 1;
    int temp = l.pHead->info;
    l.pHead = l.pHead->pNext;
    while(l.pHead != NULL){
        if(l.pHead->info < temp)
            return false;
        else if(l.pHead->info == temp)
            count_duplicate++;
        temp = l.pHead->info;
        l.pHead = l.pHead->pNext;
        num_node++;
    }
    if(count_duplicate == num_node)
        return false;
    else 
        return true;
}

bool checkDecrease(List l){
    int count_duplicate = 1;
    int num_node = 1;
    int temp = l.pHead->info;
    l.pHead = l.pHead->pNext;
    while(l.pHead != NULL){
        if(l.pHead->info > temp)
            return false;
        else if(l.pHead->info == temp)
            count_duplicate++;
        temp = l.pHead->info;
        l.pHead = l.pHead->pNext;
        num_node++;
    }
    if(count_duplicate == num_node)
        return false;
    else 
        return true;
}

void nhap(List &l){
    int count = 1;
    int check;
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
                check = l.pHead->info;
            }
            else{
                if(check <= temp->info){

                }
                l.pTail->pNext = temp;
                l.pTail = temp;
            }
        }
    }
}


void xuat(List l){
    bool check[] = {false, false};
    node *root = l.pHead;
    cout << "Danh sach vua nhap la: ";
    while(root){
        cout << root->info << " ";
        root = root->pNext;
    }
    cout << endl;
    if(l.pHead->pNext == NULL){
        cout << "Danh sach khong tang cung khong giam.";
    }
    else{
        check[0] = checkIncrease(l);
        check[1] = checkDecrease(l);
        if(check[0]){
            cout << "Danh sach tang.";
        }
        else if(check[1]){
            cout << "Danh sach giam.";
        }
        else{
            cout << "Danh sach khong tang cung khong giam.";
        }
    }
}

int main(){
    List l;
    CreateList(l);
    nhap(l);
    if(l.pHead == NULL){
        cout << "Danh sach rong.";
        return 0;
    }
    xuat(l);
}