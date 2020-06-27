struct NODE_TREE
{
    int key;
    NODE_TREE *left;
    NODE_TREE *right;
};

NODE_TREE *newNode(int data)
{
    NODE_TREE *temp = new NODE_TREE;
    temp->key = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void insertNode(NODE_TREE *&root, int data)
{
    if (!root)
    {
        NODE_TREE *temp = newNode(data);
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
int height(NODE_TREE *root){
   if(root == NULL){
       return 0;
   }
   int h_left = height(root->left);
   int h_right = height(root->right);
   int max_h = (h_left >= h_right) ? h_left : h_right;
   return 1 + max_h;
}

struct Node {
	int data;
	Node* pNext;
};
struct CreateList {
	Node* pHead;
	Node* pTail;
	CreateList() {
		pHead = NULL;
		pTail = NULL;
	}
};
void AddHead(CreateList& l, int data) {
	Node* p = new Node;
	p->data = data;
	if (l.pHead == NULL) {
		l.pHead = p;
		l.pTail = p;
		p->pNext = NULL;
	}
	else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void AddTail(CreateList& l, int data) {
	Node* p = new Node;
	p->data = data;
	p->pNext = NULL;
	if (l.pHead == NULL) {
		l.pHead = p;
		l.pTail = p;
	}
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
int TimKiem(CreateList l, int v) {
	Node* p = l.pHead;
	if (p == NULL) {
		return -1;
	}
	int dem = 0;
	while (p != NULL) {
		if (p->data == v) {
			return dem;
		}
		dem++;
		p = p->pNext;
	}
	return -1;
}

void AddNode(CreateList& l, int v, int p) {
	Node* temp = l.pHead;
	if (p == -1 || l.pHead == NULL) {
		AddHead(l, v);
	}
	else {
        int dem = 0;
		while (temp != NULL) {
			if (dem == p) {
				if(temp == l.pTail){
                    AddTail(l, v);
                    break;
				}
				else{
                    Node* a = new Node;
                    a->data = v;
					a->pNext = temp->pNext;
					temp->pNext = a;
					break;
				}
			}
			++dem;
			temp = temp->pNext;
		}
	}
}
void XuatList(CreateList l) {
	Node* p = l.pHead;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->pNext;
	}
}
void Nhap() {
	CreateList l;
	NODE_TREE *tree = NULL;
	while(1){
        int query, num;
        cin >> query;
        if(query == 3){
            break;
        }
        cin >> num;
        switch(query){
            case 0:
                {
                    AddHead(l, num);
                    break;
                }
            case 1:
                {
                    AddTail(l, num);
                    break;
                }
            case 2:
                {
                    int num_add; cin >> num_add;
                    int pos = TimKiem(l, num);
                    AddNode(l, num_add, pos);
                    break;
                }
        }
	}
	while(l.pHead){
        insertNode(tree, l.pHead->data);
        l.pHead = l.pHead->pNext;
	}
	int height_tree = height(tree);
	cout << height_tree - 1;
}
int main()
{
	Nhap();
	return 0;
}