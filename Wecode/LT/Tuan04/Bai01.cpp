/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
template
###End banned keyword*/
#include <iostream>
#include <string.h>
using namespace std;
//###INSERT CODE HERE -

int count = 0;

struct NODE
{
    long long data;
    NODE *next;
};

void AddHead(NODE *&head, int data) {
	NODE *p = new NODE;
	p->data = data;
	if (head == NULL) {
		head = p;
		p->next = NULL;
	}
	else {
		p->next = head;
		head = p;
	}
}

void Integer(string s, NODE *&my_stack){
    if (s.size() == 0){
        AddHead(my_stack, 0);
    }
    for (int i = 0;i < s.size();i++) {
        int v = s[i] - '0';
        AddHead(my_stack, v);
        count++;
    }
}
int Top(NODE *&head){
    if(head == NULL){
        return 1;
    }
    int back = head->data;
    head = head->next;
    return back;
}

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

void multiple(NODE *head, const int mul) {
    bool tag = true;
    NODE *multip = NULL;
    int carry = 0;
    for (int i = 0; i < count; i++) {
        int num = Top(head);
        carry += num * mul;
        Push(multip, carry % 10);
        carry /= 10;
    }
    if (carry)
        Push(multip, carry); 
    while(multip){
        if(multip->data == 0 && tag && multip->next != NULL){
            //loại bỏ tất cả số 0 ở đầu, trường hợp số 0 là duy nhất trong dslk thì ko loại bỏ
            multip = multip->next;
        }
        else{
            tag = false;
            cout << multip->data;
            multip = multip->next;
        }
    }
}


int main(){
    NODE *my_stack = NULL;
    string num; cin >> num;
    long long b; cin >> b;
    Integer(num, my_stack);
    multiple(my_stack, b);
}