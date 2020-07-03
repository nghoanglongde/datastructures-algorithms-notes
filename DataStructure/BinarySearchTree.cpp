#include <iostream>
#include <fstream>
#include <queue>
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

void FindAndDelete(NODE *&copy_tree, NODE *&root){
    while(root->left != NULL){
        root = root->left;
    }
    copy_tree->key = root->key;
    copy_tree = root;
    root = root->right;
}

/* Hàm xóa một node khỏi BST */
void Delete(NODE *&root, int key)
{
    if (root == NULL)
        return;
    else if (key < root->key)
        Delete(root->left, key);
    else if (key > root->key)
        Delete(root->right, key);
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
            NODE * temp = root;
            FindAndDelete(temp, root->right);
            delete temp;
        }
    }
}

int heightTree(NODE *root){
    if(root == NULL)
        return 0;
    int max_left = heightTree(root->left);
    int max_right = heightTree(root->right);
    return 1 + ((max_left > max_right) ? max_left : max_right);
}

//Các cách duyệt cây
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

void LevelOrder(NODE *root){
    queue<NODE *> li_node;
    li_node.push(root);
    while(!li_node.empty()){
        auto node = li_node.front();
        cout << node->key << " ";
        if(node->left){
            li_node.push(node->left);
        }
        if(node->right){
            li_node.push(node->right);
        }
        li_node.pop();
    }
}

int main()
{
    ifstream fi;
    fi.open("BST.txt");
    if(!fi){
        cout << "cant open this file" << endl;
        return 0;
    }

    //input cây
    NODE *root = NULL;
    int n;
    fi >> n;
    for (int i = 0; i < n; i++)
    {
        int data; fi >> data;
        insertNode(root, data);
    }

    //Chiều cao cây
    cout << heightTree(root) - 1 << endl;

    //Duyệt cây
    InOrder(root);
    cout << endl;
    PreOrder(root);
    cout << endl;
    PostOrder(root);
    cout << endl;
    LevelOrder(root);
    cout << endl;
    return 0;
}