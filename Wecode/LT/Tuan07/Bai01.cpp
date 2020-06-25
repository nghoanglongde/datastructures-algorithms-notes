#include <iostream>
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

//insert các nút theo từng tầng
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

void NLR(NODE *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        NLR(root->left);
        NLR(root->right);
    }
}

void LRN(NODE *root)
{
    if (root != NULL)
    {
        LRN(root->left);
        LRN(root->right);
        cout << root->key << " ";
    }
}
void RNL(NODE *root)
{
    if (root != NULL)
    {
        RNL(root->right);
        cout << root->key << " ";
        RNL(root->left);
    }
}
void RLN(NODE *root)
{
    if (root != NULL)
    {
        RLN(root->right);
        RLN(root->left);
        cout << root->key << " ";
    }
}
void NRL(NODE *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        NRL(root->right);
        NRL(root->left);
    }
}

int main()
{
    NODE *root = NULL;
    while(true){
      ll data; cin >> data;
      if(data == 0){
        break;
      }
      insertNode(root, data);
    }
    cout << "LNR: "; LNR(root); cout << endl;
    cout << "LRN: "; LRN(root); cout << endl;
    cout << "RNL: "; RNL(root); cout << endl;
    cout << "RLN: "; RLN(root); cout << endl;
    cout << "NLR: "; NLR(root); cout << endl;
    cout << "NRL: "; NRL(root);
    return 0;
}