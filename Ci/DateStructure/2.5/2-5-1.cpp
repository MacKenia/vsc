#include "iostream"
using namespace std;
typedef struct Node 
{
	int data;
	struct Node *next;
} Node, *LinkList;

void showList(LinkList L);

void CreateList(LinkList &L)
{
	int x, n;
	cout << "请输入集合的元素个数：";
	cin >> n;
	cout << "集合的元素依次是：";
	L = new Node;
	L->data = n; //头节点数据存放链表长度
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

void except(LinkList &LA, LinkList &LB, LinkList &LC) 
{
	LinkList pa = LA->next;
	LinkList pb, pc = new Node;
	LinkList head = pc; // 头指针
	head->data = 0;
	head->next = NULL;
	int x = 1;
	while (LA->data--)
	{
		
		pb = LB->next;
		int t = LB->data; // 保存头结点的值
		while (LB->data--) // 头节点的值依次减一来遍历
		{
			if (pa->data == pb->data)
			{
				x = 0;
				pa = pa->next;//pa遍历被放入另一种情况的if中，所以在这里要加一条
				break;
			}
			else
			{
				x = 1; //将标志重置为1 
				pb = pb->next;
			}
		}
		LB->data = t; // 将值还给头结点以便下一次遍历
		if (x == 1)
		{
			pc->next = pa;
			pa = pa->next; //为保证复制之后的两条链依旧分开
			pc = pc->next;
			pc->next = NULL; //保证链表有限
			head->data++; //链表长度加一
		}
	}
	LC = head;
}

void showList(LinkList L)
{
	LinkList p = L->next; 
	int t = L->data;
	while (L->data--)
	{
		cout << p->data << " ";
		p = p->next;
	}
	L->data = t;
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