/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
[
]
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
struct NODE
{
    long long data;
    NODE *next;
};

NODE *Push(NODE *head, long long data)
{
    NODE *temp = new NODE;
    if (head == NULL)
    {
        head = temp;
        head->data = data;
        head->next = NULL;
        return head;
    }
    temp->data = data;
    temp->next = head;
    head = temp;
    return head;
}
void output(NODE *head){
    cout << "STACK: ";
    if(head == NULL){
        cout << "null" << endl;
        return;
    }
    else{
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }
}

int Top(NODE *head){
    if(head == NULL){
        return 400;
    }
    return head->data;
}

void Pop(NODE *&head)
{
    if (head == NULL)
    {
        return;
    }
    head = head->next;
    return;
}
int getMin(NODE *head){
    int minE = (int)1e8;
    if(head == NULL){
        return 0;
    }
    while(head != NULL){
        minE = (minE > head->data) ? head->data : minE;
        head = head->next; 
    }
    return minE; 
}

int main()
{
    NODE *head = NULL;
    int n;
    cin >> n;
    while(n--){
        int control;
        long long x;
        cin >> control;
        if(control == 1){
            cin >> x;
            head = Push(head, x);
        }
        else if(control == 2){
            if(Top(head) == 400){
                cout << "STACK: null" << endl;
            }
            else{
                cout << Top(head) << endl;
            }
        }
        else if(control == 3){
            Pop(head);
        }
        else if(control == 4){
            int minE = getMin(head);
            if(minE == 0){
                cout << "STACK: null" << endl;
            }
            else{
                cout << "min STACK: " << minE << endl;
            }
        }
    }
}