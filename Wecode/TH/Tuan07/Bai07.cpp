typedef long long ll;

struct node {
    ll data;
    ll num;
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

node *createNode(ll value, ll num)
{
    node *newNode = new node;
    newNode->data = value;
    newNode->num = num;
    newNode->pNext = NULL;
    return newNode;
}

void nhap(List &l){
    while(1){
        ll data, num;
        cin >> data;
        if(data == 0){
            break;
        }
        else{
            cin >> num;
            node *temp = createNode(data, num);

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
void xuat(List l){
    ll bef = l.pHead->data;
    bool tag = true;
    cout << 1 << endl;
    while(l.pHead){
        ll check = l.pHead->data - bef;
        if(check > 500 && tag){
          cout << 2 << endl;
          tag = false;
        }
        cout << l.pHead->data << " " << l.pHead->num << endl;
        l.pHead = l.pHead->pNext;
    }
}
void swap(node *&a, node *&b) 
{ 
    ll temp_data = a->data;
    ll temp_num = a->num; 
    a->data = b->data; 
    a->num = b->num;
    b->data = temp_data;
    b->num = temp_num; 
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
            if (ptr1->data > ptr1->pNext->data) 
            {  
                swap(ptr1, ptr1->pNext); 
                swapped = 1; 
            } 
            ptr1 = ptr1->pNext; 
        } 
        lptr = ptr1; 
    } while (swapped); 
} 
int main()
{
    List l;
    CreateList(l);
    nhap(l);
    bubbleSort(l.pHead);
    bubbleSort(l.pHead);
    xuat(l);
    return 0;
}