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
void countSum(NODE_TREE *tree, int &sum){
    if(tree != NULL){
        countSum(tree->left, sum);
        sum = sum + tree->key;
        countSum(tree->right, sum);
    }
}
void LNR(NODE_TREE *tree, int &sum){
    if(tree != NULL){
        LNR(tree->left, sum);
        sum = sum - tree->key;
        if(sum != 0){
            cout << sum << " ";
        }
        LNR(tree->right, sum);
    }
}
int main()
{
    NODE_TREE *tree = NULL;
    int n; cin >> n;
    int sum = 0;
    for(int i = 0;i < n;i++){
        int data; cin >> data;
        insertNode(tree, data);
    }
    countSum(tree, sum);
    cout << sum << " ";
    LNR(tree, sum);
}