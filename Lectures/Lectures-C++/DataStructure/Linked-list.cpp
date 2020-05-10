#include<iostream>
using namespace std;

struct NODE {
    int info;
    NODE* pNext;
};
struct LIST {
    NODE* pHead;
    NODE* pTail;
};
void CreateLIST(LIST& l) {
    l.pHead = NULL;
    l.pTail = NULL;
}

NODE *createNODE(int value)
{
    //hàm tạo 1 Node mới
    NODE *newNODE = new NODE;
    newNODE->info = value;
    newNODE->pNext = NULL;
    return newNODE;
}

void addHead(LIST &l, int value){
    //Thêm node vào đầu
    NODE *temp = createNODE(value);
    if(l.pHead){
        temp->pNext = l.pHead;
        l.pHead = temp;
    }
    else{
        l.pHead = temp;
    }
}

void addTail(LIST &l, int value){
    //Thêm node vào cuối
    NODE *temp = createNODE(value);
    if(l.pHead){
        l.pTail->pNext = temp;
        l.pTail = temp;
    }
    else{
        l.pHead = temp;
        l.pTail = l.pHead;
    }
}

void ReverseList(LIST &l){
    //hàm đảo ngược linked list, có trong câu hỏi của microsoft
    NODE *current = NULL;
    NODE *previous = NULL;

    while(l.pHead != NULL)    {
        current = l.pHead;
        l.pHead = l.pHead->pNext;
        current->pNext = previous;
        previous = current;
    }
    l.pHead = current;
}

void nhap(LIST &l){
    //hàm nhập này có thể add Tail hoặc add Head tùy chỉnh, đã có sẵn hàm add Head và add Tail
    while(1){
        int info;
        cin >> info;
        if(info == 0){
            break;
        }
        else{
           addHead(l, info);
        }
    }
}

void xuat(LIST l){
    while(l.pHead){
        cout << l.pHead->info << " ";
        l.pHead = l.pHead->pNext;
    }
}

int main(){
    LIST l;
    CreateLIST(l);
    nhap(l);
    xuat(l);
}
