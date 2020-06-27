struct node {
    string info;
    node* pNext;
};
struct List {
    node* pHead;
    node* pTail;
};
void CreateList(List& l) {
    l.pHead = NULL;
    l.pTail = NULL;
}

node *createNode(string value)
{
    node *newNode = new node;
    newNode->info = value;
    newNode->pNext = NULL;
    return newNode;
}

void nhap(List &l){
    while(1){
        string data;
        cin >> data;
        if(data == "0"){
            break;
        }
        else{
            node *temp = createNode(data);

            if(l.pHead == NULL){
                l.pHead = temp;
                l.pTail = l.pHead;
            }
            else{
                l.pTail->pNext = temp;
                l.pTail = temp;
            }
        }
    }
}
void swap(node *&a, node *&b){
    string temp = a->info;
    a->info = b->info;
    b->info = temp;
}
void bubbleSort(node *&start) {
    int swapped, i;
    node *ptr1;
    node *lptr = NULL;
    if (start == NULL)
        return;
    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->pNext != lptr)
        {
            string compare_1 = ptr1->info.substr(3, 7);
            string compare_2 = ptr1->pNext->info.substr(3, 7);
            if (compare_1 > compare_2)
            {
                swap(ptr1, ptr1->pNext);
                swapped = 1;
            }
            ptr1 = ptr1->pNext;
        }
        lptr = ptr1;
    } while (swapped);
}

void xuat(List l){
    while(l.pHead){
        cout << l.pHead->info << endl;
        l.pHead = l.pHead->pNext;
    }
}


int main()
{
    List l;
    CreateList(l);
    nhap(l);
    bubbleSort(l.pHead);
    xuat(l);
    return 0;
}