struct NODE
{
    int key;
    NODE *left;
    NODE *right;
};

NODE *newNode(int data)
{
    NODE *temp = new NODE;
    temp->key = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void insertNode(NODE *&root, int data)
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
}

void PreOrder(NODE *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

int main()
{
    NODE *root = NULL;
    int n, data;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> data;
        insertNode(root, data);
    }
    PreOrder(root);
    return 0;
}