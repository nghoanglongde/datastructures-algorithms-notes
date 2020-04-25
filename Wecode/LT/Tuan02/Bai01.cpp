//Bài toán: Đếm và in ra những phần tử xuất hiện nhiều nhất trong danh sách liên kết đơn

#include<iostream>

using namespace std;

struct node {
    int info;
    node* pNext;
    int count = 0;
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

    while(l.pHead != NULL){
        current = l.pHead;
        l.pHead = l.pHead->pNext;
        current->pNext = previous;
        previous = current;
    }
    l.pHead = current;
}

node * Search(node *root, int value){
    while(root){
        if(root->info == value)
            return root;
        else
            root = root->pNext;
    }
    return NULL;
}

void outputNode(node *root, int maxE){
    if(root){
        node *copy_root = root;
        while(root){
            cout << root->info << " ";
            root = root->pNext;
        }
        cout << endl;
        while(copy_root){
            if(copy_root->count != 0 && copy_root->count == maxE){
                cout << copy_root->info << ": " << copy_root->count << endl; 
            }
            copy_root = copy_root->pNext;
        }
        return;
    }
    else
        cout << "Danh sach rong.";
}
int main(){
    List l;
    int maxE = (int)-1e6;
    CreateList(l);
    nhap(l);
    ReverseList(l);
    node *copy_root = l.pHead;
    while(copy_root != NULL){
        node *ptr = Search(l.pHead, copy_root->info);
        if(ptr){
            ptr->count++;
            maxE = (maxE < ptr->count) ? ptr->count : maxE; 
        }
        copy_root = copy_root->pNext;
    }
    outputNode(l.pHead, maxE);
}