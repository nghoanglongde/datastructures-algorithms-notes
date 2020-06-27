struct NODE_TREE
{
    string eng;
    string new_lan;
    NODE_TREE *left;
    NODE_TREE *right;
};

NODE_TREE *newNode(string eng, string new_lan)
{
    NODE_TREE *temp = new NODE_TREE;
    temp->eng = eng;
    temp->new_lan = new_lan;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

NODE_TREE * SearchTNode(NODE_TREE *T, string x)
{
	if (T != NULL)
	{
		if (T->new_lan == x) return T;
		else
		{
			if (x > T->new_lan)
				return SearchTNode(T->right, x);
			else
				return SearchTNode(T->left, x);
		}
	}
	return NULL;
}

void insertNode(NODE_TREE *&root, string eng, string new_lan)
{
    if (!root)
    {
        NODE_TREE *temp = newNode(eng, new_lan);
        root = temp;
        return;
    }
    if (new_lan < root->new_lan)
    {
        insertNode(root->left, eng, new_lan);
    }
    else if (new_lan > root->new_lan)
    {
        insertNode(root->right, eng, new_lan);
    }
    else{
        return;
    }
}
int main()
{
    NODE_TREE *tree = NULL;
    int n, m; cin >> n >> m;
    for(int i = 0;i < m;i++){
        string eng, new_lan; cin >> eng >> new_lan;
        insertNode(tree, eng, new_lan);
    }
    while(n--){
        string query; cin >> query;
        NODE_TREE *temp = SearchTNode(tree, query);
        if(temp){
            cout << temp->eng << " ";
        }
        else{
            cout << "eh" << " ";
        }
    }
}