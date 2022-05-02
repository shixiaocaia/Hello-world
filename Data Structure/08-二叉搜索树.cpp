#include<Linkk.h>
using namespace std;

//二叉搜索树、二叉排序树、二叉查找树、BST（Binary Search Tree）
/*
	非空BST具有以下的性质：
		1.非空左子树的所有键值小于其根结点的键值
		2.非空右子树的所有键值大于其根结点的键值
		3.左、右子树都是二叉搜索树
*/
Bintree FindMax(Bintree H)
{
	if (!H)
	{
		printf("tree is empty\n");
		return 0;
	}
	else {
		while (H->Right)
			H = H->Right;
		return H;
	}
}
Bintree FindMin(Bintree H)
{
	if (!H)
	{
		printf("tree is empty\n");
		return 0;
	}
	else {
		while (H->Left)
			H = H->Left;
		return H;
	}
}


Bintree Insert(Bintree H, int x)
{
	if (!H)
	{
		H = (Bintree)malloc(sizeof(struct TreeNode));
		H->Data = x;
		H->Left = NULL;
		H->Right = NULL;
	}
	else {
		if (x > H->Data)
		{
			H->Right=Insert(H->Right, x);
		}
		else if(x<H->Data)
		{
			H->Left=Insert(H->Left, x);
		}
	}
	return H;

}

Bintree Delete(Bintree H, int x)
{
	Bintree tmp;
	if (!H)
	{
		printf("tree is empty\n");
		return 0;
	}
	else if (x > H->Data)	H->Right = Delete(H->Right, x);
	else if (x < H->Data)	H->Left = Delete(H->Left, x);
	else {
		//被删除的节点有两个孩子
		if (H->Left && H->Right)
		{
			//用左子树的最大值：一定大于左子树所有值，小于右子树所有值
			//用右子树的最小值：一定大于左子树所有值，小于右子树所有值
			tmp=FindMin(H->Right);
			H->Data = tmp->Data;
			H->Right = Delete(H->Right, tmp->Data);
			
		}
		//只有一个孩子或者没有孩子
		else {
			tmp = H;
			if (!H->Left && !H->Right)	H = NULL;
			else if (!H->Left&&H->Right) 	H = H->Right;
			else if (H->Left && !H->Right) H = H->Left;
			free(tmp);
		}
		//return H;
	}
	return H;//递归返回的位置
}



void Inordertraversal(Bintree H)
{
	if (H)
	{
		Inordertraversal(H->Left);
		printf("%d ", H->Data);
		Inordertraversal(H->Right);
	}
}


int main()
{
	Bintree BST = NULL;
	BST = Insert(BST, 5);
	BST = Insert(BST, 7);
	BST = Insert(BST, 3);
	BST = Insert(BST, 1);
	BST = Insert(BST, 2);
	BST = Insert(BST, 4);
	BST = Insert(BST, 6);
	BST = Insert(BST, 8);
	BST = Insert(BST, 9);
	Inordertraversal(BST);
	printf("\n");
	/*
				5
			   /\
			  3  7
			 /\	 /\
			1 4 6  8
			\      \
			 2      9
	*/
	printf("Min %d\n", FindMin(BST)->Data);
	printf("Max %d\n", FindMax(BST)->Data);
	Deletee(5,BST);
	Inordertraversal(BST);
	return 0;
}
