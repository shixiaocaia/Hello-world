#include<iostream>
#include<malloc.h>
#include<stdio.h>
using namespace std;
typedef struct Lnode *List;
struct Lnode {
	int data;
	List Next;
};
List L;
List MakeEmpty()
{
	List  L = (List)malloc(sizeof(struct Lnode));
	L = NULL;
	return L;
}
int Length(List L)
{
	List p = L;
	int len = 0;
	while (p)
	{
		p = p->Next;
		len++;
	}
	return len;
}
//按序号找
List FindKth(int K, List L)
{
	List p = L;
	int i = 1;
	// (K<0 || K>Length(L))	return NULL;
	while (p && i < K) {
		p = p->Next;
		i++;
	}
	if (i == K && p->Next)
		return p;
	else if (i == K && !p->Next)
		return L;
	else
		return NULL;

}
//按值寻找
List Find(int X, List L)
{
	List p = L;
	while (p&&X!=p->data){
		p = p->Next;
	}
	return p;
}

List Insert(int x, int i, List L)
{
	List p, s;
	int j = 1;
	if (i == 1)//插入链头
	{
		s = (List)malloc(sizeof(struct Lnode));
		s->data = x;
		s->Next = L;
		return s;
	}
	p = FindKth(i - 1, L);//找到插入的前一个位置的链表
	if (!p)
	{
		cout << "insert error" << endl;
		return NULL;
	}
	else {
		s = (List)malloc(sizeof(struct Lnode));
		s->data = x;
		s->Next = p->Next;
		p->Next = s;
		return p;
	}
}
List Delete(int i, List L)
{
	List p, s;
	if (i == 1) {
		s = L;
		if (L)
			L = L->Next;
		else
			return NULL;
		free(s); //释放被删除的节点
		return L;
	}
	p = FindKth(i - 1, L);//这是第i-1个节点位置
	if (!p || !(p->Next)) {
		cout << "结点错误" << endl;
		return NULL;
	}
	else {
		s = p->Next;//这是第i个节点位置
		p->Next = s->Next;//第i个位置指向i+1
		free(s);//释放被删除的空间
		return L;
	}
}
void Print(List L)
{
	List t;
	int flag = 1;
	cout << "当前链表为：" ;
	for (t = L; t; t = t->Next) {
		cout << t->data << ' ';
		flag = 0;
	}
	if (flag)
		cout << "NULL" << endl;
	else
		cout << endl;
}


int main()
{
	L = MakeEmpty();
	Print(L);
	L = Insert(11, 1, L);
	L = Insert(12, 2, L);
	L = Insert(13, 3, L);
	L = Insert(14, 4, L);
	Print(L);
	cout << "链表的长度为：" << Length(L) << endl;
	cout << "链表中第2个元素的值为： " << FindKth(2, L)->data << endl;
	if (Find(FindKth(2, L)->data, L))	cout << "YES" << endl;
	else cout << "NO" << endl;
	L = Delete(3, L);
	Print(L);
	return 0;

}
