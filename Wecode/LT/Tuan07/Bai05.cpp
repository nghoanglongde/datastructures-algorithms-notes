#include<iostream>
using namespace std;

typedef long long ll;

struct NODE
{
    ll key;
    NODE *left;
    NODE *right;
};
NODE *newNode(ll data)
{
    NODE *temp = new NODE;
    temp->key = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
bool isPrime(ll data)
{
    for (ll i = 2; i * i <= data; i++)
    {
        if (data % i == 0)
        {
            return false;
        }
    }
    return data > 1;
}
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
    else
    {
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

void SP_Delete(NODE *&copy_root,NODE *&root)
{
    if(root->left != NULL){
        SP_Delete(copy_root, root->left);
    }
    else{
        copy_root->key = root->key;
        copy_root = root;
        root = root->right;
    }
}
void DeleteSNT(NODE *&tree, ll &count){
    if(tree != NULL){
        DeleteSNT(tree->left, count);
        bool tag = false;
        if(isPrime(tree->key) && count > 0){
            NODE *copy_root = tree;
            if(tree->left == NULL){
                tree = tree->right;
            }
            else if(tree->right == NULL){
                tree = tree->left;
            }
            else{
                SP_Delete(copy_root, tree->right);
            }
            delete copy_root;
            count--;
            tag = true;
        }
        if(tree != NULL && tag){
            DeleteSNT(tree, count);
        }
        else if(tree != NULL){
            DeleteSNT(tree->right, count);
        }
    }
}
void inputTree(NODE *&root, ll &t){
    while (1)
    {
        ll data;
        cin >> data;
        if (data == 0)
        {
            break;
        }
        insertNode(root, data);
    }
    cin >> t;
}
int main()
{
    NODE *root = NULL;
    ll t;
    inputTree(root, t);
    if (root == NULL)
    {
        cout << "Not found tree!";
        return 0;
    }
    DeleteSNT(root, t);
    if (root == NULL)
    {
        cout << "Not found tree!";
        return 0;
    }
    LNR(root);

    return 0;
}