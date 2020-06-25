#include <iostream>
using namespace std;

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
    else{
      return;
    }
}
bool isLeaf(NODE *root){
  return (root->left == NULL) && (root->right == NULL);
}
int countNode(NODE *root){
    if(root == NULL){
      return 0;
    }
    else{
      if(isLeaf(root)){
        return 1;
      }
      else{
        return countNode(root->left) + countNode(root->right);
      }
    }
}
void LNR(NODE *root)
{
    if (root != NULL)
    {
        if(isLeaf(root)){
          cout << root->key << " ";
        }
        else{
          LNR(root->left);
          LNR(root->right);
        }
    }
}

int main()
{
    int n; cin >> n;
    NODE *tree = NULL;
    int average = 0;
    for(int i = 0;i < n;++i){
      int data; cin >> data;
      insertNode(tree, data);
    }
    cout << countNode(tree) << endl;
    LNR(tree);
    return 0;
}