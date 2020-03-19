#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>
#include <stack>
#include <math.h>
using namespace std;

struct NODE
{
    char data;
    NODE *right;
    NODE *left;
    NODE()
    {
        this->right = this->left = NULL;
    }
};

struct ExpressionTree
{
    NODE *root;
    ExpressionTree()
    {
        this->root = NULL;
    }
};

bool isOperand(char x)
{
    int temp = static_cast<int>(x);
    if ((temp > 47 && temp < 58))
        return true;
    return false;
}

bool isOperator(char x)
{
    return x == '+' || x == '-' || x == '*' || x == '/';
}

void chuanhoastr(string &text, string &destination)
{
    int tag = 0; // th đầu chuỗi là space
    for (int i = 0; i <= text.length() - 1; i++)
    {
        //trường hợp (4 5)
        if (text[i] == ' ')
        {
            //trường hợp 2 space liên tiếp nhau
            if (text[i + 1] != ' ' && tag == 1)
            {
                destination.push_back(' ');
            }
            tag = 1;
        }
        //th text[i] là toán tử 5/4
        else if (isOperator(text[i]))
        {
            //nếu text[i - 1] không phải là space và không phải là vị trí đầu chuỗi     ( /5...)
            if (text[i - 1] != ' ' && tag == 1)
            {
                destination.push_back(' ');
            }
            destination.push_back(text[i]); //push toán tử vào
            tag = 1;
            //nếu text[i + 1] không phải là space và là một toán hạng 5 /4
            if (text[i + 1] != ' ' && isOperand(text[i + 1]))
            {
                destination.push_back(' ');
                destination.push_back(text[i + 1]);
                i = i + 1; //cho i di chuyển tới qua vị trí text[i + 1] để xét tiếp
            }
        }
        else
        {
            destination.push_back(text[i]);
            tag = 1;
        }
    }
}

int evaluatepostfix(string &text)
{
    int i = 0;
    int num1, num2, result;
    int mu = 0;
    int num = 0;
    stack<int> mystack;
    while (text[i] != '\0')
    {
        if (text[i] == ' ' && isOperand(text[i - 1]))
        {
            mystack.push(num);
            num = 0;
            mu = 0;
        }
        else if (isOperand(text[i]))
        {
            num = num * pow(10, mu) + (static_cast<int>(text[i]) - 48); //gặp lỗi ascii, text[i] convert sang là bảng mã ascii
            mu++;
        }
        else if (text[i] != ' ' && isOperator(text[i]))
        {
            num1 = mystack.top();
            mystack.pop();
            num2 = mystack.top();
            mystack.pop();
            switch (text[i])
            {
            case '+':
                result = num2 + num1;
                break;
            case '-':
                result = num2 - num1;
                break;
            case '/':
                result = num2 / num1;
                break;
            case '*':
                result = num2 * num1;
                break;
            }
            mystack.push(result);
        }
        i++;
    }
    result = mystack.top();
    mystack.pop();
    return result;
}

int getPriority(char text)
{
    if (text == '+' || text == '-')
        return 1;
    if (text == '*' || text == '/')
        return 2;
    return 0;
}

string infixToPostfix(string text)
{
    stack<char> temp_stack;
    string result = "";
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == '(')
        {
            temp_stack.push(text[i]);
        }
        else
        {
            if (isOperand(text[i]))
            {
                result = result + text[i];
            }
            else
            {
                if (isOperator(text[i]))
                {
                    while (!temp_stack.empty() && getPriority(temp_stack.top()) >= getPriority(text[i]))
                    {
                        cout << temp_stack.top() << endl;
                        result = result + temp_stack.top();
                        temp_stack.pop();
                    }
                    temp_stack.push(text[i]);
                }
                else
                {
                    if (text[i] == ')')
                    {
                        while (!temp_stack.empty() && temp_stack.top() != '(')
                        {
                            result = result + temp_stack.top();
                            temp_stack.pop();
                        }
                        temp_stack.pop();
                    }
                }
            }
        }
    }
    while (!temp_stack.empty())
    {
        result = result + temp_stack.top();
        temp_stack.pop();
    }
    return result;
}

void createExpressionTree(NODE *&root, string src)
{
    src = infixToPostfix(src);
    stack<NODE *> tree_nodes;
    for (int i = 0; i < src.length(); i++)
    {
        if (isOperand(src[i]))
        {
            NODE *temp = new NODE;
            temp->data = src[i];
            tree_nodes.push(temp);
        }
        else
        {
            if (isOperator(src[i]))
            {
                NODE *temp = new NODE;
                temp->data = src[i];
                temp->right = tree_nodes.top();
                tree_nodes.pop();
                temp->left = tree_nodes.top();
                tree_nodes.pop();
                tree_nodes.push(temp);
            }
        }
    }
    root = tree_nodes.top();
    tree_nodes.pop();
}

int main()
{
    ifstream fi("input.txt");
    if (!fi.is_open())
    {
        cout << "Ko the doc file";
        return 0;
    }

    int resultCalculatePostfix;
    string src;
    string resultIntoPostfix;
    string destination;

    ExpressionTree result_tree;

    getline(fi, src);

    // resultIntoPostfix = infixToPostfix(src);
    // chuanhoastr(resultIntoPostfix, destination);
    // cout << resultIntoPostfix << endl;
    // cout << destination;

    createExpressionTree(result_tree.root, src);

    // chuanhoastr(src,destination);
    // cout << destination << endl;
    // resultpostfix = evaluatepostfix(destination);
    // cout << resultpostfix << endl;
}