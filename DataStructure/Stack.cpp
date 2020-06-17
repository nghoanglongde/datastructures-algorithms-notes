#include <bits/stdc++.h>
using namespace std;
struct NODE
{
    int data;
    NODE *next;
};

NODE *Push(NODE *&head, int data)
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

//Hàm in ra các phần tử
void output(NODE *head)
{
    NODE *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}
void Pop(NODE *&head)
{
    if (head == NULL)
    {
        cout << "Stack is empty";
        return;
    }
    cout << "Pop: " << head->data << endl;
    head = head->next;
    return;
}

//Tạo stack bằng thư viện trong STL
void createStackByLib()
{
    stack<int> mystack;

    for (int i = 0; i < 5; ++i)
        mystack.push(i);

    cout << "Popping out elements...";
    while (!mystack.empty())
    {
        cout << ' ' << mystack.top();
        mystack.pop();
    }
    cout << '\n';
}

int main()
{
    NODE *head = NULL;
    int n, value;
    cout << "Nhap so node: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> value;
        head = Push(head, value);
    }
    Pop(head);
    cout << "Stack left:" << endl;
    output(head);
    return 0;
}
