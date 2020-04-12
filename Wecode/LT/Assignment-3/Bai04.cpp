//Bài toán: Merge 2 danh sách đơn theo thứ tự tăng dần, biết rằng 2 danh sách lk đơn đã sắp xếp tăng dần

/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
[]
template
###End banned keyword*/

#include <iostream>
using namespace std;
struct node {
    int info;
    node* pNext;
};
struct List {
    node* pHead;
    node* pTail;
};
void CreateList(List& l) {
    l.pHead = NULL;
    l.pTail = NULL;
}

void inputList(List &l) {
	while (1) {
		long long x;
		cin >> x;
		if (x == 0) {
			return;
		}
		else {
			node* newnode = new node;
			newnode->info = x;
			newnode->pNext = NULL;
			if (l.pHead == NULL) {
				l.pHead = newnode;
				l.pTail = newnode;
			}
			else {
				l.pTail->pNext = newnode;
				l.pTail = newnode;
			}
		}
	}
}

void SortIncrease(List &l){
    node *root_count = l.pHead;
    int count = 0;
    while(root_count){
        count++;
        root_count = root_count->pNext;
    }
    while(count--){
        node *B = NULL;
        node *sort_in = l.pHead;
        while(sort_in){
            B = sort_in->pNext;
            if(B == NULL)
                break;
            if(sort_in->info > B->info){
                long long temp = sort_in->info;
                sort_in->info = B->info;
                B->info = temp;
            }
            sort_in = sort_in->pNext;
        }
    }
}
node * mergeTwoLists(node *l1, node *l2) {
    node fake;
    fake.info = -1;
    fake.pNext = NULL;
    node *last = &fake;
    while(l1 != NULL && l2 != NULL) {
        if(l1->info < l2->info) {
            last->pNext = l1;
            last = l1;
            l1 = l1->pNext;    
        }
        else {
            last->pNext = l2;
            last = l2;
            l2 = l2->pNext;
        }
    }
    if(l1 != NULL) {
        last->pNext = l1;
    }
    if(l2 != NULL) {
        last->pNext = l2;
    }
    return fake.pNext;
}

void xuatnode(List l){
    while(l.pHead){
        cout << l.pHead->info << " ";
        l.pHead = l.pHead->pNext;
    }
    cout << endl;
}

void outputresult(List l1, List l2, List &result){
    if(l1.pHead == NULL || l2.pHead == NULL){
        if(l1.pHead == NULL){
            cout << "Danh sach l1 rong." << endl;
        }
        else{
            cout << "Danh sach l1 la: ";
            xuatnode(l1);
        }
        if(l2.pHead == NULL){
            cout << "Danh sach l2 rong." << endl;
        }
        else{
            cout << "Danh sach l2 la: ";
            xuatnode(l2);
        }
        cout << "Khong tron duoc.";
    }
    else{
        cout << "Danh sach l1 la: ";
        xuatnode(l1);
        cout << "Danh sach l2 la: ";
        xuatnode(l2);

        SortIncrease(l1);
        SortIncrease(l2);

        cout << "Danh sach l1 sau khi sap xep la: ";
        xuatnode(l1);
        cout << "Danh sach l2 sau khi sap xep la: ";
        xuatnode(l2);

        cout << "Ket qua tron l1 voi l2 la: ";
        result.pHead = mergeTwoLists(l1.pHead, l2.pHead);
        xuatnode(result);
    }

}
int main()
{
	
	List L1;
	CreateList(L1);
	List L2;
	CreateList(L2);
    List result;

	inputList(L1);
	inputList(L2);
    
    outputresult(L1, L2, result);


	return 0;
}