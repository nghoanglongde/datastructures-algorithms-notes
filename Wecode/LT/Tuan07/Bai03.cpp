struct NODE
{
    double key;
    NODE *left;
    NODE *right;
};

NODE *newNode(double data)
{
    NODE *temp = new NODE;
    temp->key = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void insertNode(NODE *&root, double data)
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
void LNR(NODE *root)
{
    if (root != NULL)
    {
        LNR(root->left);
        cout << root->key << " ";
        LNR(root->right);
    }
}
void check(NODE *root, double key, bool &tag){
  if(root != NULL){
    if(root->key - key == 0){
      tag = true;
      return;
    }
    else if(key - root->key < 0){
      check(root->left, key, tag);
    }
    else if(key - root->key > 0){
      check(root->right, key, tag);
    }
  }
}

int main()
{
    int n; cin >> n;
    NODE *tree = NULL;
    double average = 0;
    for(int i = 0;i < n;++i){
      double data; cin >> data;
      average = average + data;
      insertNode(tree, data);
    }
    average = (average * 1.0) / n;
    bool tag = false;
    check(tree, average, tag);
    if(tag){
      cout << "1" << endl;
    }
    else{
      cout << "0" << endl;
    }
    LNR(tree);
    return 0;
}