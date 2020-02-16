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

//insert các nút theo từng tầng
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

NODE *FindMax(NODE *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
/* Hàm xóa một node khỏi BST */
NODE *Delete(NODE *root, int key)
{
    if (root == NULL)
        return root;
    else if (key < root->key)
        root->left = Delete(root->left, key);
    else if (key > root->key)
        root->right = Delete(root->right, key);
    else
    {
        /* Case 1:  Node lá, không có con */
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        /* Case 2: Có một con  */
        else if (root->left == NULL)
        {
            NODE *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            NODE *temp = root;
            root = root->left;
            delete temp;
        }
        /* case 3: Có hai con */
        else
        {
            NODE *temp = FindMax(root->left);
            root->key = temp->key;
            root->left = Delete(root->left, temp->key);
        }
    }
    return root;
}
void InOrder(NODE *root)
{
    if (root != NULL)
    {
        InOrder(root->left);
        cout << root->key << " ";
        InOrder(root->right);
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

void PostOrder(NODE *root)
{
    if (root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->key << " ";
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
    InOrder(root);
    cout << endl;
    PreOrder(root);
    cout << endl;
    PostOrder(root);
    cout << endl;
    return 0;
}