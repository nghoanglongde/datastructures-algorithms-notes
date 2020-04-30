// /*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
// define
// include
// class
// [
// ]
// template
// ###End banned keyword*/

// #include <iostream>
// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

// using namespace std;

// //###INSERT CODE HERE -
// struct NODE
// {
//     char data;
//     NODE *next;
// };

// NODE *Push(NODE *&head, char data)
// {
//     NODE *temp = new NODE;
//     if (head == NULL)
//     {
//         head = temp;
//         head->data = data;
//         head->next = NULL;
//         return head;
//     }
//     temp->data = data;
//     temp->next = head;
//     head = temp;
//     return head;
// }

// void Pop(NODE *&head)
// {
//     if (head == NULL)
//     {
//         cout << "Stack is empty";
//         return;
//     }
//     head = head->next;
//     return;
// }

// char Top(NODE *head){
//     return head->data;
// }

// bool calculate(NODE *head ,string s){
//     for(int i = 0;i < s.length();i++){
//         if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
//             head = Push(head, s[i]);
//         }
//         else{
//             if(head != NULL){
//                 char top = Top(head);
//                 Pop(head);
//                 if(s[i] == ']'){
//                     if(top != '[')
//                         return false;
//                 }
//                 else if(s[i] == '}'){
//                     if(top != '{')
//                         return false;
//                 }
//                 else{
//                     if(top != '(')
//                         return false;
//                 }
//             }
//             else
//                 return false;
//         }
//     }
//     if(head == NULL){
//         return true;
//     }
//     return false;
// }

// int main()
// {
//     NODE *head = NULL;
//     string s;
//     cin >> s;
//     if(calculate(head ,s)){
//         cout << "true";
//     }
//     else
//         cout << "false";
//     return 0;
// }
// int main(){ 

//     long long sl_open = 0, sl_close = 0;
//     bool has_open = false;
//     bool check_0 = false;
//     string text;
//     getline(cin, text);
//     bool check[] = {false, false, false};
//     string err1[] = {"Ngoac dat sai vi tri", "Thieu ngoac mo.", "Thieu ngoac dong."};
//     string err2[] = {"Ngoac dat sai vi tri", "thieu ngoac mo", "thieu ngoac dong"};
//     for(int i = 0;i < text.length();i++){
//         if(text[i] == '('){
//             ++sl_open;
//             has_open = true;
//         }
//         else if(text[i] == ')'){
//             ++sl_close;
//         }
//         if(text[i] == ')' && !has_open){
//             check_0 = true;
//         }
//     }
//     if(sl_open == sl_close && !check_0){
//         cout << "So cap dau ngoac tron hop le la: " << sl_open;
//         return 0;
//     }
//     if(check_0 && sl_open > 0){
//         check[0] = true;
//     }
//     if(sl_open < sl_close){
//         check[1] = true;
//     }
//     if(sl_open > sl_close){
//         check[2] = true;
//     }
//     int j = 0;
//     for(int i = 0;i < 3;i++){
//         if(check[i]){
//             j++;
//         }
//     }
//     int k = 1;
//     for(int i = 0;i < 3;i++){
//         if(check[i] && j >= 2){
//             if(k == 2){
//                 cout << err2[i];
//             }
//             else{
//                 cout << err2[i] << " va ";
//             }
//             ++k;
//         }
//         else if(check[i] && j == 1){
//             cout << err1[i];
//         }
//     }

// }