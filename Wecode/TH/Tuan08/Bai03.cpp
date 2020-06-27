struct NODE_TREE
{
    string key;
    NODE_TREE *left;
    NODE_TREE *right;
};

NODE_TREE *newNode(string data)
{
    NODE_TREE *temp = new NODE_TREE;
    temp->key = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void TheMang(NODE_TREE *&copy_root, NODE_TREE *&root) {
    if (root->left != NULL) {
        TheMang(copy_root, root->left);
    }
    else {
        copy_root->key = root->key;
        copy_root = root;
        root = root->right;
    }
}

void delTree(NODE_TREE *&root, string key) {
    if (root == NULL)
        return;
    else if (key < root->key)
        delTree(root->left, key);
    else if (key > root->key)
        delTree(root->right, key);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL)
        {
            NODE_TREE *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            NODE_TREE *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            NODE_TREE *X = root;
            TheMang(X, root->right);
            delete X;
        }
    }
}
void insertNode(NODE_TREE *&root, string data)
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
NODE_TREE * SearchTNode(NODE_TREE *T, string x)
{
	if (T != NULL)
	{
		if (T->key == x) return T;
		else
		{
			if (x > T->key)
				return SearchTNode(T->right, x);
			else
				return SearchTNode(T->left, x);
		}
	}
	return NULL;
}
int main()
{
    NODE_TREE *tree = NULL;
    while(1){
        int query;
        string text;
        cin >> query;
        if(query == 0){
            break;
        }
        cin >> text;
        switch(query){
        case 1:
            {
                insertNode(tree, text);
                break;
            }
        case 2:
            {
                NODE_TREE *temp = SearchTNode(tree, text);
                if(temp){
                    cout << 1 << endl;
                }
                else{
                    cout << 0 << endl;
                }
                break;
            }
        case 3:
            {
                delTree(tree, text);
                break;
            }
        }
    }
}