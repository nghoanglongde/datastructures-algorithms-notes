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

int height(NODE *root){
   if(root == NULL){
       return 0;
   }
   int h_left = height(root->left);
   int h_right = height(root->right);
   int max_h = (h_left >= h_right) ? h_left : h_right;
   return 1 + max_h;
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
    int ans = height(root);
    cout << ans - 1;
    return 0;
}