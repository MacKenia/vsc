#include "iostream"
using namespace std;
typedef struct Node 
{
	int data;
	struct Node *next;
} Node, *LinkList;

void CreateList(LinkList &L)
{
	int x, n;
	cout << "请输入集合的元素个数：";
	cin >> n;
	cout << "集合的元素依次是：";
	L = new Node;
	L->next = NULL;
	LinkList q = L;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		LinkList p = new Node;
		p->data = x;
		q->next = p;
		q = q->next;
	}
	q->next = NULL;
}

void except(LinkList &LA, LinkList &LB, LinkList &LC) //我感觉主要在这有问题
{
	LinkList pa = LA->next;
	LinkList pb, pc = NULL;
	int x = 1;
	while (pa->next != NULL)
	{
		pb = LB->next;
		while (pb->next != NULL)
		{
			if (pa->data == pb->data)
			{
				x = 0;
				break;
			}
			else
				pb = pb->next;
		}
		if (x == 1)
		{
			pc = pa;
			pc = pc->next;
		}
		pa = pa->next;
	}
	LC = pc;
}

void showList(LinkList L)
{
	LinkList p = L; 
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl
		 << endl;
}

int main()
{
	LinkList p1 = NULL, p2 = NULL, p3 = NULL;
	cout << "创建集合1" << endl;
	CreateList(p1);
	cout << "创建集合2" << endl;
	CreateList(p2);
	except(p1, p2, p3);
	cout << "两个集合差运算后的结果为：" << endl;
	showList(p3);
}