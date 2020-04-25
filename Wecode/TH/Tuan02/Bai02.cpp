//Đảo chiều danh sách liên kết trong khoảng n -> m

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

node *createNode(long long value)
{
    node *newNode = new node;
    newNode->info = value;
    newNode->pNext = NULL;
    return newNode;
}

void nhap(List &l, long long &n, long long &m, long long &count){
    while(1){
        long long data;
        cin >> data;
        if(data == 0){
            break;
        }
        else{
            count++;
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
    cin >> n >> m;
}
node * search(List l, node *batdau){
    while(l.pHead){
        if(l.pHead->pNext == batdau){
            return l.pHead;
        }
        l.pHead = l.pHead->pNext;
    }
    return NULL;
}

void ReverseList(List& l, long long n, long long m, long long count){
    node *copy_root = l.pHead;
    node *current = NULL;
    node *previous = NULL;
    node *tail = NULL;
    node *search_node = NULL;
    
    for(long long i = 1;i <= count;i++){
        if(i >= n && i <= m){
            current = copy_root;
            if(i == n){
                search_node = current;
                tail = current;
            }
            copy_root = copy_root->pNext;
            current->pNext = previous;
            previous = current;
        }
        else if(i < n){
            copy_root = copy_root->pNext;
        }
        else{
            tail->pNext = copy_root;
            copy_root = copy_root->pNext;
            tail = tail->pNext;
        }
    }
    copy_root = current;
    if(n != 1){
        node *temp = search(l, search_node);
        temp->pNext = copy_root;
        while(l.pHead){
            cout << l.pHead->info << " ";
            l.pHead = l.pHead->pNext;
        }

    }
    else{
        while(copy_root){
            cout << copy_root->info << " ";
            copy_root = copy_root->pNext;
        }
    }
}

int main()
{
    List l;
    long long n, m, count = 0;
    CreateList(l);
    nhap(l, n, m, count);
    if (l.pHead == NULL) cout << "Danh sach rong.";
    else {
        ReverseList(l, n, m, count);
    }
    return 0;
}