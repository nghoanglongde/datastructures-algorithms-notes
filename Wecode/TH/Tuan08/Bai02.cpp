typedef long long ll;

struct NODE
{
    ll data;
    ll count = 0;
    NODE *next;
};

NODE * Search(NODE *root, ll value){
    while(root){
        if(root->data == value)
            return root;
        else
            root = root->next;
    }
    return NULL;
}

NODE *createNode(ll value)
{
    NODE *newNode = new NODE;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertTail(NODE *&head, NODE *&tail,ll data){
    NODE *temp;
    temp = createNode(data);
    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }
    else{
        tail->next = temp;
        tail = temp;
        return;
    }
}
void swap(NODE *&a, NODE *&b){
    ll temp_i = a->data;
    ll temp_c = a->count;
    a->data = b->data;
    a->count = b->count;
    b->data = temp_i;
    b->count = temp_c;
}
void bubbleSort(NODE *&start) {
    int swapped, i;
    NODE *ptr1;
    NODE *lptr = NULL;
    if (start == NULL)
        return;
    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}
void outputNode(NODE *root){
    NODE *copy_root = root;
    bubbleSort(copy_root);
    while(copy_root){
        if(copy_root->count != 0){
            cout << copy_root->data << " " << copy_root->count << endl;
        }
        copy_root = copy_root->next;
    }
}

int main(){
    NODE *head = NULL, *tail = NULL;
    int count = 0;
    while(1){
        int data;
        cin >> data;
        if(data == 0){
            outputNode(head);
            return 0;
        }
        else{
            insertTail(head, tail, data);
            NODE *ptr = Search(head, data);
            if(ptr){
                ptr->count++;
            }
        }
    }
}