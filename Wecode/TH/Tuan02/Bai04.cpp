//Dùng stack kiểm tra dấu ngoặc hợp lệ

/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
[
]
###End banned keyword*/

#include <iostream>
#include <String>
using namespace std;

//###INSERT CODE HERE -

struct NODE
{
    char data;
    NODE *next;
};

NODE *Push(NODE *&head, char data)
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

void Pop(NODE *&head)
{
    if (head == NULL)
    {
        cout << "Stack is empty";
        return;
    }
    head = head->next;
    return;
}

char Top(NODE *head){
    return head->data;
}

bool calculate(NODE *head ,string s){
    for(int i = 0;i < s.length();i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            head = Push(head, s[i]);
        }
        else{
            if(head != NULL){
                char top = Top(head);
                Pop(head);
                if(s[i] == ']'){
                    if(top != '[')
                        return false;
                }
                else if(s[i] == '}'){
                    if(top != '{')
                        return false;
                }
                else{
                    if(top != '(')
                        return false;
                }
            }
            else
                return false;
        }
    }
    if(head == NULL){
        return true;
    }
    return false;
}

int main()
{
    NODE *head = NULL;
    string s;
    cin >> s;
    if(calculate(head ,s)){
        cout << "true";
    }
    else
        cout << "false";
    return 0;
}