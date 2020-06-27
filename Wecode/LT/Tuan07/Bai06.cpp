struct node
{
	int info;
	node* pNext;
};
struct list
{
	node* pHead;
	node* pTail;

};
void CreateList(list& l)
{
	l.pHead = l.pTail = NULL;
}
node* CreateNode(int x)
{
	node* p;
	p = new node;
	p->info = x;
	p->pNext = NULL;
	return p;
}
void AddTail(list& l, node* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = l.pHead;

	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void NhapList(list& l)
{
	while (1)
	{
		int x;
		cin >> x;
		if (x == 0) return;
		node* p = CreateNode(x);
		AddTail(l, p);
	}
}
struct TNode
{
	int Key;
	TNode* pLeft;
	TNode* pRight;

};
typedef TNode* TREE;

void CreateTree(TREE& T)
{
	T = NULL;
}
TNode* CreateTNode(int x)
{
	TNode* p;
	p = new TNode;
	p->Key = x;
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}
void InsertTNode(TREE& T, int x)
{
	if (T)
	{
		if (T->Key == x) return;
		if (T->Key > x)
			return InsertTNode(T->pLeft, x);
		else
			return InsertTNode(T->pRight, x);
	}
	T = new TNode;
	T->Key = x;
	T->pLeft = T->pRight = NULL;
}
void NhapCay(TREE& T)
{
	while (1)
	{
		int x;
		cin >> x;
		if (x == 0) break;
		InsertTNode(T, x);
	}
}
void InOrder(TREE Root)
{
	if (Root != NULL)
	{
		InOrder(Root->pLeft);
		cout << Root->Key << " ";
		InOrder(Root->pRight);
	}
}
TNode* SearchTNode(TREE T, int x)
{
	if (T != NULL)
	{
		if (T->Key == x) return T;
		else
		{
			if (x > T->Key)
				return SearchTNode(T->pRight, x);
			else
				return SearchTNode(T->pLeft, x);
		}
	}
	return NULL;
}
int Bac(TREE T)
{
	if (T)
	{
		if (T->pLeft == NULL && T->pRight == NULL)
			return 0;
		if (T->pLeft != NULL && T->pRight != NULL)
			return 2;
		if (T->pLeft == NULL && T->pRight != NULL || T->pLeft != NULL && T->pRight == NULL)
			return 1;
	}
}
void Output(TREE T, list l)
{
	node* p = l.pHead;
	while (p != NULL)
	{
		TNode* tmp = SearchTNode(T, p->info);
		if (tmp)
			cout << "Node " << p->info << " co bac la " << Bac(tmp) << "." << endl;
		else
			cout << "Node " << p->info << " co bac la " << 0 << "." << endl;
		p = p->pNext;
	}
}
int main()
{
	TREE T;
	CreateTree(T);
	list l;
	CreateList(l);
	NhapCay(T);
	NhapList(l);
	InOrder(T);
	cout << endl;
	Output(T, l);
	return 0;
}