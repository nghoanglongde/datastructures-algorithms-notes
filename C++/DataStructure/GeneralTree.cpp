#include <bits/stdc++.h>
using namespace std;

struct NODE
{
    int key;
    vector<NODE *> child;
};

NODE *Search(int x, NODE *root)
{
    NODE *beingcheck, *child_beingcheck;

    queue<NODE *> arr_node;
    arr_node.push(root);
    while (1)
    {
        if (arr_node.empty())
        {
            return NULL;
        }
        beingcheck = arr_node.front();
        arr_node.pop();
        if (beingcheck->key == x)
        {
            return beingcheck;
        }
        for (int i = 0; i < beingcheck->child.size(); i++)
        {
            child_beingcheck = beingcheck->child[i];
            if (child_beingcheck != NULL)
            {
                if (child_beingcheck->key == x)
                {
                    return child_beingcheck;
                }
                else if (!child_beingcheck->child.empty())
                {
                    for (int i = 0; i < child_beingcheck->child.size(); i++)
                    {
                        arr_node.push(child_beingcheck->child[i]);
                    }
                }
            }
        }
    }
}

void printTree(NODE *root)
{
    NODE *beingcheck, *child_beingcheck;
    queue<NODE *> arr_node;
    arr_node.push(root);
    while (1)
    {
        if (arr_node.empty())
        {
            return;
        }
        beingcheck = arr_node.front();
        arr_node.pop();
        cout << beingcheck->key << endl;
        for (int i = 1; i <= beingcheck->child.size(); i++)
        {
            child_beingcheck = beingcheck->child[i];
            cout << child_beingcheck->key << endl;
            if (!child_beingcheck->child.empty())
            {
                for (int i = 1; i <= child_beingcheck->child.size(); i++)
                {
                    arr_node.push(child_beingcheck->child[i]);
                }
            }
        }
    }
}

void preOrder(NODE *root)
{
    if (root != NULL)
    {
        cout << root->key << endl;
        if (!root->child.empty())
        {
            for (int i = 0; i < root->child.size(); i++)
            {
                preOrder(root->child[i]);
            }
        }
    }
}

void insertNode(int x, NODE *&root)
{
    NODE *parent = NULL;
    NODE *temp = NULL;
    int parent_key, child_i, num_child;

    temp = new NODE;
    temp->key = x;
    cout << "Nhap so luong con cua node " << temp->key << ": ";
    cin >> num_child;

    for (int i = 0; i < num_child; i++)
    {
        temp->child.push_back(NULL);
    }

    if (root == NULL)
    {
        root = temp;
        return;
    }

    else
    {
        while (1)
        {
            cout << "Nhap key's node parent cua node " << temp->key << ": ";
            cin >> parent_key;
            parent = Search(parent_key, root);
            if (parent == NULL)
            {
                cout << "This parent doesn't exist in this tree please enter another parent" << endl;
            }
            else
            {
                if (parent->child.empty())
                {
                    cout << "This parent has no child please enter another parent" << endl;
                }
                else
                {
                    num_child = parent->child.size();
                    do
                    {
                        cout << "Nhap vi tri node tu [1..." << num_child << "] = ";
                        cin >> child_i;
                    } while (child_i < 1 || child_i > num_child);
                    parent->child[child_i - 1] = temp;
                    return;
                }
            }
        }
    }
}
int main()
{
    NODE *root = NULL;
    int key, numOfNode;
    cout << "Nhap so luong node: ";
    cin >> numOfNode;
    for (int i = 1; i <= numOfNode; i++)
    {
        cout << "Nhap key cua node: ";
        cin >> key;
        insertNode(key, root);
    }
    //printTree(root);
    preOrder(root);
}