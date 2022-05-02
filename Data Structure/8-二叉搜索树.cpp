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

Bintree Deletee(int X, Bintree BST) {
	Bintree tmp;
	if (!BST)
		cout << "要删除的元素未找到";
	else if (X < BST->Data)   // X 比当前结点值小，在左子树继续查找删除 
		BST->Left = Deletee(X, BST->Left);
	else if (BST->Data < X)   // X 比当前结点值大，在右子树继续查找删除 
		BST->Right = Deletee(X, BST->Right);
	else {  //  找到被删除结点 
		if (BST->Left && BST->Right) {  // 被删除结点有俩孩子结点 
			tmp = FindMin(BST->Right);   // 找到右子树中值最小的
			BST->Data = tmp->Data;     // 用找到的值覆盖当前结点 
			BST->Right = Deletee(tmp->Data, BST->Right);    // 把前面找到的右子树最小值结点删除 
		}
		else {  // 被删除结点只有一个孩子结点或没有孩子结点 
			tmp = BST;
			if (!BST->Left && !BST->Right)  // 没有孩子结点 
				BST = NULL;
			else if (BST->Left && !BST->Right)  // 只有左孩子结点 
				BST = BST->Left;
			else if (!BST->Left && BST->Right)  // 只有右孩子结点 
				BST = BST->Right;
			free(tmp);
		}
	}
	return BST;
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
