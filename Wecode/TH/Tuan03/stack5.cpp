/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -

struct NODE
{
    int data;
    NODE *next;
};

NODE *Push(NODE *head, int data)
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
}
int getMin(NODE *head){
    int minE = (int)1e5;
    if(head == NULL){
        return 400;
    }
    while(head != NULL){
        minE = (minE > head->data) ? head->data : minE;
        head = head->next; 
    }
    return minE; 
}

int main()
{
    int minE = (int)1e5;
    NODE *head = NULL;
    int n;
    cin >> n;
    while(n--){
        int control;
        cin >> control;
        if(control == 1){
            int x;
            cin >> x;
            minE = (minE > x) ? x : minE;
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
            if(head != NULL){
                if(minE == head->data){
                    Pop(head);
                    minE = getMin(head);
                }
                else{
                    Pop(head);
                }
            }
        }
        else if(control == 4){
            if(minE == 400 || minE == (int)1e5){
                cout << "STACK: null" << endl;
            }
            else{
                cout << "min STACK: " << minE << endl;
            }
        }
    }
}