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

int height(NODE *node)  
{  
    if (node == NULL)  
        return 0;  
    else
    {  
        int lheight = height(node->left);  
        int rheight = height(node->right);  
  

        if (lheight > rheight)  
            return(lheight + 1);  
        else return(rheight + 1);  
    }  
}  
void printGivenLevel(NODE *root, int level)  
{  
    if (root == NULL)  
        return;  
    if (level == 1)  
        cout << root->key << " ";  
    else if (level > 1)  
    {  
        printGivenLevel(root->left, level-1);  
        printGivenLevel(root->right, level-1);  
    }  
}  

void printLevelOrder(NODE *root)  
{  
    int h = height(root);  
    int i;  
    for (i = 1; i <= h; i++)  
        printGivenLevel(root, i);  
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
    printLevelOrder(root);
    return 0;
}