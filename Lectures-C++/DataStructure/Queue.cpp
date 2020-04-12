#include <bits/stdc++.h>
using namespace std;
//cài đặt queue có thể dùng dslk đơn hoặc dslk vòng đơn
struct NODE
{
    int data;
    NODE *next;
};
NODE *createnode(int data)
{
    NODE *temp = new NODE;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
NODE *push(NODE *&head, NODE *&tail, int value)
{
    NODE *temp = createnode(value);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return head;
    }
    tail->next = temp;
    tail = temp;
    return head;
}
void pop(NODE *&head)
{
    NODE *ptrdel = head;
    cout << "Pop: " << head->data << endl;
    head = head->next;
    delete ptrdel;
}
void output(NODE *head)
{
    NODE *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}
int main()
{
    int n, value;
    NODE *head = NULL;
    NODE *tail = NULL;
    cout << "Nhap so node: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> value;
        head = push(head, tail, value);
    }
    pop(head);
    cout << "============================" << endl;
    output(head);
    return 0;
}