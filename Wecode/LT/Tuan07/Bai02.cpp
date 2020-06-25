typedef long long ll;
struct NODE
{
    ll key;
    NODE *left;
    NODE *right;
};
struct NODE_LIST{
    int info;
    NODE_LIST* pNext;
};
struct LIST{
    NODE_LIST* pHead;
    NODE_LIST* pTail;
};
void CreateLIST(LIST& l) {
    l.pHead = NULL;
    l.pTail = NULL;
}

NODE_LIST *createNODE(int value)
{
    //hàm tạo 1 Node mới
    NODE_LIST *newNODE = new NODE_LIST;
    newNODE->info = value;
    newNODE->pNext = NULL;
    return newNODE;
}
NODE *newNode(ll data)
{
    NODE *temp = new NODE;
    temp->key = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

//insert các nút theo từng tầng
void insertNode(NODE *&root, ll data)
{
    if (!root)
    {
        NODE *temp = newNode(data);
        root = temp;
        return;
    }
    if (data < root->key)
    {
        insertNode(root->left, data);
    }
    else if (data > root->key)
    {
        insertNode(root->right, data);
    }
    else{
      return;
    }
}
void xuat(NODE *root, ll key, bool &tag){
  if(root != NULL){
    if(root->key == key){
      tag = true;
      return;
    }
    else if(key < root->key){
      xuat(root->left, key, tag);
    }
    else if(key > root->key){
      xuat(root->right, key, tag);
    }
  }
}

int main()
{
    NODE *tree = NULL;
    while(true){
      ll data; cin >> data;
      if(data == 0){
        break;
      }
      insertNode(tree, data);
    }
    LIST l;
    CreateLIST(l);
    while(true){
        ll info;
        cin >> info;
        if(info == 0){
            break;
        }
        else{
            NODE_LIST *temp = createNODE(info);

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
    while(l.pHead != NULL){
      bool tag = false;
      xuat(tree, l.pHead->info, tag);
      if(tag){
        cout << "YES" << endl;
      }
      else{
        cout << "NO" << endl;
      }
      l.pHead = l.pHead->pNext;
    }
    return 0;
}