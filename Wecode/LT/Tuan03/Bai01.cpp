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

//###INSERT CODE HERE -
struct NODE
{
    long long data;
    NODE *next;
};

void Push(NODE *&head, long long data)
{
    NODE *temp = new NODE;
    if (head == NULL)
    {
        head = temp;
        head->data = data;
        head->next = NULL;
        return;
    }
    temp->data = data;
    temp->next = head;
    head = temp;
}

void output(NODE *head){
    if(head == NULL){
        cout << "Stack rong." << endl;
        return;
    }
    else{
        cout << "Cac gia tri co trong stack la: ";
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }
}

void Pop(NODE *&head)
{
    NODE *p = head;
    head = head->next;
    delete p;
    return;
}

void nhap(NODE *&head){
    int x; cin >> x;
    while(1){
        int info;
        cin >> info;
        if(info == 0){
            break;
        }
        else if(info == x){
            if(head == NULL){
                cout << "Stack rong." << endl;
            }
            else{
                Pop(head);
            }
        }
        else{
            Push(head, info);
        }
    }
}

int main()
{
    NODE *head = NULL;
    nhap(head);
    output(head);
    
}



