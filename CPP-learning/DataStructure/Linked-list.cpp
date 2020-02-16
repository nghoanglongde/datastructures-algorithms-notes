#include <iostream>
using namespace std;
struct NODE
{
    int data;
    NODE *next;
};

NODE *createNODE(int value)
{
    NODE *newNode = new NODE;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

//Nối vòng 1 hướng
void insertHead(NODE *&head, NODE *&tail, int data)
{
    NODE *newNode = createNODE(data);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->next = head;
    tail = newNode;
}

//=======================================================================================
//Nối vòng 2 hướng, cần thêm trường NODE *prev
// void addTail(NODE *&head, NODE *&tail, int data)
// {
//     NODE *temp = createNode(data);
//     if (head == NULL)
//     {
//         head = temp;
//         tail = temp;
//         temp->next = head;
//         return;
//     }
//     tail->next = temp;
//     temp->prev = tail;
//     temp->next = head;
//     head->prev = temp;
//     tail = temp;
// }

int main()
{
    NODE *head = NULL;
    NODE *tail = NULL;
    NODE *ptr = NULL;
    int data, n;
    cout << "So node: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cout << "Nhap value: ";
        cin >> data;
        insertHead(head, tail, data);
    }
    ptr = head;
    do
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != head);
    return 0;
}