#include<iostream>
#include<queue>
#include<string>
#include<fstream>
#define FOR(a) for(int i = 0; i < (a); i++)
using namespace std;

struct NODE{
  int value;
  NODE *right;
  NODE *left;
};

NODE *createNode(int value){
  NODE *temp = new NODE;
  temp->value = value;
  temp->right = temp->left = NULL;
  return temp;
};

void insertNodeHaveDirect(NODE *&root,queue<char> &text,int value){
  if(root == NULL && text.empty()){
    root = createNode(value);
    return;
  }
  else{
    char key = text.front();
    text.pop();
    if(key == 'L'){
      insertNodeHaveDirect(root->left,text,value);
    }
    else if(key == 'R'){
      insertNodeHaveDirect(root->right,text,value);
    }
  }
}

void insertNode(NODE *&root,int value,queue<NODE *> &my_queue){
  NODE *temp = NULL;
  NODE *new_nodes = createNode(value);
  if(root == NULL){
    root = new_nodes;
  }
  else{
    while(1){
      temp = my_queue.front();
      if(temp->left != NULL && temp->right != NULL)
        my_queue.pop();
      else
        break;
    }
    if(temp->left == NULL){
      temp->left = new_nodes;
    }
    else
      temp->right = new_nodes;
  }
  my_queue.push(new_nodes);
}

void preOder(NODE *root){
  if(root == NULL){
    return;
  }
  cout << root->value << " ";
  preOder(root->left);
  preOder(root->right);
}

//Hàm tìm chiều cao của cây tính cả gốc
int findHeight(NODE *root){
  if(root == NULL)
    return 0;
  else{
    int left_height = findHeight(root->left);
    int right_height = findHeight(root->right);
    if(left_height > right_height)
      return left_height + 1;
    else
      return right_height + 1;
  }
}

//Hàm tìm khoảng cách giữa 2 nút xa nhau nhất trong cây
int diameterTree(NODE *root){
  if(root == NULL){
    return 0;
  }
  int left_height = findHeight(root->left);//chiều cao cây trái
  int right_height = findHeight(root->right);
  int left_diameter = diameterTree(root->left);// số nút cây trái
  int right_diameter = diameterTree(root->right);// số nút cây phải
  int result = max(left_height + right_height + 1,max(left_diameter,right_diameter));
  return result;
}

int main() {

  //INSERT NODE HAVE DIRECT LR 
  //========================================================

  // ifstream fi;
  // fi.open("input.txt");
  // if(!fi){
  //   cout << "ko tim thay file";
  //   return 0;
  // }

  // int num_nodes, value_root;
  // int value_nodes,result_diameter;
  // string direct_nodes;
  // fi >> num_nodes;
  // fi >> value_root;
  // queue<char> text;
  // NODE *root = createNode(value_root);
  // FOR(num_nodes - 1){
  //   fi >> direct_nodes;
  //   fi >> value_nodes;
  //   //cout << "direct: " << direct_nodes << " ";
  //   //cout << "value: " << value_nodes;
  //   for(int i = 0;i < direct_nodes.length();i++){
  //     text.push(direct_nodes[i]);
  //     cout << "queue size: " << text.size() << endl;
  //   }
  //   insertNodeHaveDirect(root,text,value_nodes);
  // }
  //preOder(root);
  //result_diameter = diameterTree(root);
  //cout << endl;
  //cout << "result diameter: " << result_diameter;


  //==============================================================================

  //INSERT LEFT TO RIGHT, NOT HAVE DIRECT
  int num_nodes,value;
  queue<NODE *> my_queue;
  NODE *root = NULL;
  cin >> num_nodes;
  for(int i = 0;i < num_nodes;i++){
    cin >> value;
    insertNode(root,value,my_queue);
  }
  preOder(root);
}