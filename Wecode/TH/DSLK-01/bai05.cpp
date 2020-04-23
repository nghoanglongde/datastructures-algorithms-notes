/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
[]
template
###End banned keyword*/

#include <iostream>
#include <math.h>
using namespace std;

//###INSERT CODE HERE -

struct NODE
{
    int data;
    int count = 0;
    NODE *next;
};

NODE * Search(NODE *root, int value){
    while(root){
        if(root->data == value)
            return root;
        else
            root = root->next;
    }
    return NULL;
}

NODE *createNode(int value)
{
    NODE *newNode = new NODE;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertTail(NODE *&head, NODE *&tail,int data){
    NODE *temp;
    temp = createNode(data);
    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }
    else{
        tail->next = temp;
        tail = temp;
        return;
    }
}

void outputNode(NODE *root){
    if(root){
        NODE *copy_root = root;
        cout << "Danh sach vua nhap la: ";
        while(root){
            cout << root->data << " ";
            root = root->next;
        }
        cout << endl;
        cout << "So lan xuat hien cua tung phan tu trong danh sach la:" << endl;
        while(copy_root){
            if(copy_root->count != 0){
                cout << copy_root->data << ": " << copy_root->count << endl; 
            }
            copy_root = copy_root->next;
        }
        return;
    }
    else
        cout << "Danh sach rong.";
}

int main(){
    NODE *head = NULL, *tail = NULL;
    int count = 0;
    while(1){
        int data;
        cin >> data;
        if(data == 0){
            outputNode(head);
            return 0;
        }
        else{
            insertTail(head, tail, data);
            NODE *ptr = Search(head, data);
            if(ptr){
                ptr->count++;
            }
        }
    }
}