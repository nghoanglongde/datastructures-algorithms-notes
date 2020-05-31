/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
template
[
]
###End banned keyword*/
#include <iostream>
using namespace std;
//###INSERT CODE HERE -

typedef long long ll;
struct node{
    ll tu;
    ll mau;
    node *pNext;
};

struct LIST{
    node *pHead;
    node *pTail;
};

void createList(LIST &l){
    l.pHead = NULL;
    l.pTail = NULL;
}

node * createNode(ll tu, ll mau){
    node *temp = new node;
    temp->tu = tu;
    temp->mau = mau;
    temp->pNext = NULL;
    return temp;
}

ll GCD(ll A, ll B){
    if(B == 0){
        return A;
    }
    return GCD(B, A % B);
}

bool checkEqual(node *a, node *b){
    ll check = a->tu * b->mau - b->tu * a->mau;
    if(check == 0){
        return true;
    }
    return false;
}

void nhap(LIST &l, node *&target){
    while(1){
        ll tu; cin >> tu;
        ll mau; cin >> mau;
        if(mau == 0){
            break;
        }
        node *new_node = createNode(tu, mau);
        if(l.pHead == NULL){
            l.pHead = new_node;
            l.pTail = l.pHead;
        }
        else{
            l.pTail->pNext = new_node;
            l.pTail = new_node;
        }
        
    }
    if(l.pHead == NULL){
        return;
    }
    else{
        ll tu_target, mau_target; cin >> tu_target >> mau_target;
        node *x = createNode(tu_target, mau_target);
        target = x;
    }
}
void xuat(LIST l, node *target){
    if(l.pHead == NULL){
        cout << "Danh sach rong.";
    }
    else{
        bool flag = false;
        LIST result;
        createList(result);
        cout << "Danh sach vua nhap la: ";
        while(l.pHead){
            if(checkEqual(l.pHead, target)){
                flag = true;
                node *n_node = createNode(l.pHead->tu, l.pHead->mau);
                if(result.pHead == NULL){
                    result.pHead = n_node;
                    result.pTail = n_node;
                }
                else{
                    result.pTail->pNext = n_node;
                    result.pTail = n_node;
                }
            }
            cout << l.pHead->tu << "/" << l.pHead->mau << " ";
            l.pHead = l.pHead->pNext;
        }
        cout << endl;
        if(flag){
            cout << "Cac phan so bang " << target->tu << "/" << target->mau << " co trong danh sach la: ";
            while(result.pHead){
                cout << result.pHead->tu << "/" << result.pHead->mau << " ";
                result.pHead = result.pHead->pNext;
            }
        }
        else{
            cout << "Khong co phan so nao bang " << target->tu << "/" << target->mau << " trong danh sach.";
        }
    }
}
int main(){
    LIST l;
    node *target = NULL;
    createList(l);
    nhap(l, target);
    xuat(l, target);
}