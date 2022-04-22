#include<stdio.h>
#include<malloc.h>
#include<iostream>
#define maxsize 100
using namespace std;
typedef int ElementType;
typedef struct Lnode *List;
struct Lnode {
	ElementType Data[maxsize];
	int Last;
};
List L;

//初始化 创建空标
List MakeEmpty()
{
	List L;
	L = (List)malloc(sizeof(struct Lnode));
	L->Last = -1;         
	return L;
}


//按值查找
int Find(ElementType X, List L)
{
	int i = 0;
	while (i <= L->Last && L->Data[i] != X)
		i++;
	if (i > L->Last)	
		return -1;
	else
		return i;

}

//插入
void Insert(ElementType X, int i, List L)
{
	int j;
	if (L->Last == maxsize) {
		cout << "表满" << endl;
		return;

	}

	if (i<0 || i>L->Last + 1) {
		cout << "非法插入" << endl;
		return;
	}

	for (j = L->Last; j >= i; j--)
	{
		L->Data[j + 1] = L->Data[j];//从后向前挪
	}
	L->Data[i] = X;
	L->Last++;
	return;
}
//删除
void Delete(int i, List L)
{
	int j;
	if (i<0 || i>L->Last ) {
		cout << "非法删除" << endl;
		return;
	}
	for (j = i; j < L->Last+1; j++)
		L->Data[j - 1] = L->Data[j];//从前往后挪
	L->Last--;
	return;


}
//按序查找
ElementType Findth(int K, List L)
{
	if (K<0 || K>L->Last) {
		cout << "越界查询" << endl;
		return 0;
	}
	return L->Data[K];
}

//表长
int Length(List L)
{
	return L->Last + 1;
}


int main()
{
	int i = 0;
	L = MakeEmpty();
	Insert(1, 0, L);
	Insert(2, 1, L);
	Insert(3, 2, L);
	Insert(4, 3, L);
	Insert(5, 4, L);
	cout << "原始线性表为：";
	for (int j = 0; j < L->Last+1; j++)	cout << L->Data[j] << ' ';
	cout << endl;
	Delete(1, L);
	cout << "删除后线性表为：";
	for (int j = 0; j < L->Last + 1; j++)	cout << L->Data[j] << ' ';
	cout << endl;
	cout << "1th element：" << L->Data[1];

	return 0;
}
