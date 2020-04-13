//Bài toán: Chèn một phần tử vào danh sách liên kết đơn sao cho danh sách luôn giữ đc trạng thái tăng dần

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

node *createnode(long long value)
{
    node *newnode = new node;
    newnode->info = value;
    newnode->pNext = NULL;
    return newnode;
}

void nhap(List &l, long long &x){
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
    cin >> x;
}
bool checkIncrease(List l){
    int count_duplicate = 1;
    int num_node = 1;
    int temp = l.pHead->info;
    l.pHead = l.pHead->pNext;
    if(l.pHead == NULL){
        return false;
    }
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
node * Search(List l, long long x){
    node *root = l.pHead;
    if(root->info > x){
        return root;
    }
    else{
        node *current = NULL;
        while(l.pHead != NULL){
            current = l.pHead->pNext;
            if(current == NULL)
                break;
            if(l.pHead->info <= x && x <= current->info)
                return l.pHead;
            l.pHead = l.pHead->pNext;
        }
        return NULL;
    }
}
void addHead(List &l, long long value){
    node *temp = createnode(value);
    if(l.pHead){
        temp->pNext = l.pHead;
        l.pHead = temp;
    }
    else{
        l.pHead = temp;
    }
}
void addTail(List &l, long long value){
    node *temp = createnode(value);
    if(l.pHead){
        l.pTail->pNext = temp;
        l.pTail = temp;
    }
    else{
        l.pHead = temp;
        l.pTail = l.pHead;
    }
}
void addPos(List &l, node *ptr, long long value){
    node *root = l.pHead;
    while(root){
        if(root == ptr){
            node *temp = createnode(value);
            temp->pNext = root->pNext;
            root->pNext = temp;
            return;
        }
        root = root->pNext;
    }
}
void xuat(List &l, long long x){
    node *root = l.pHead;
    cout << "Danh sach vua nhap la: ";
    while(root){
        cout << root->info << " ";
        root = root->pNext;
    }
    cout << endl;
    if(checkIncrease(l)){
        node *ptr = Search(l, x);
        if(ptr){
            if(ptr == l.pHead && l.pHead->info >= x){
                addHead(l, x);
            }
            else{
                node *temp = createnode(x);
                temp->pNext = ptr->pNext;
                ptr->pNext = temp;
            }
        }
        else{
            addTail(l, x);
        }
    }
    else{
        cout << "Danh sach khong tang.";
        return;
    }
    cout << "Danh sach sau khi chen so " << x << " la: ";
    node *head = l.pHead;
    while(head){
        cout << head->info << " ";
        head = head->pNext;
    }
}
int main(){
    List l;
    long long x;
    CreateList(l);
    nhap(l, x);
    if(l.pHead == NULL){
        cout << "Danh sach rong.";
        return 0;
    }
    xuat(l, x);
}
