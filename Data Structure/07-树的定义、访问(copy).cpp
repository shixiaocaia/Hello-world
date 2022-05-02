#include<Linkk.h>
using namespace std;

//先序遍历
void  PreOrderTraversal(BinTree BT) {
	if (BT) {
		printf("%d", BT->Data);  // 打印根 
		PreOrderTraversal(BT->Left);  // 进入左子树 
		PreOrderTraversal(BT->Right);  // 进入右子树 
	}
}
void PreOrderTraversal(BinTree BT) {
	BinTree T = BT;
	Stack S = CreateStack();  // 创建并初始化堆栈 S
	while (T || !IsEmpty(S)) {  // 当树不为空或堆栈不空 
		while (T) {
			Push(S, T);    // 压栈，第一次遇到该结点 
			printf("%d", T->Data);  // 访问结点
			T = T->Left;   // 遍历左子树 
		}
		if (!IsEmpty(S)) {  // 当堆栈不空 
			T = Pop(S);    // 出栈，第二次遇到该结点 
			T = T->Right;  // 访问右结点 
		}
	}
}


//中序遍历
void InOrderTraversal(BinTree BT) {
	if (BT) {
		InOrderTraversal(BT->Left);  // 进入左子树 
		printf("%d", BT->Data);  // 打印根 
		InOrderTraversal(BT->Right);  // 进入右子树 
	}
}

void InOrderTraversal(BinTree BT) {
	BinTree T = BT;
	Stack S = CreateStack();  // 创建并初始化堆栈 S
	while (T || !IsEmpty(S)) {  // 当树不为空或堆栈不空 
		while (T) {
			Push(S, T);    // 压栈
			T = T->Left;   // 遍历左子树 
		}
		if (!IsEmpty(S)) {  // 当堆栈不空 
			T = Pop(S);    // 出栈
			printf("%d", T->Data);  // 访问结点
			T = T->Right;  // 访问右结点 
		}
	}
}


//后序遍历
void PostOrderTraversal(BinTree BT) {
	if (BT) {
		PostOrderTraversal(BT->Left);  // 进入左子树 
		PostOrderTraversal(BT->Right);  // 进入右子树 
		printf("%d", BT->Data);  // 打印根 
	}
}
void PostOrderTraversal(BinTree BT) {
	BinTree T = BT;
	Stack S = CreateStack();  // 创建并初始化堆栈 S
	vector<BinTree> v;   // 创建存储树结点的动态数组
	Push(S, T);
	while (!IsEmpty(S)) {  // 当树不为空或堆栈不空 
		T = Pop(S);
		v.push_back(T);  // 出栈元素进数组
		if (T->Left)
			Push(S, T->Left);
		if (T->Right)
			Push(S, T->Right);
	}
	reverse(v.begin(), v.end());  // 逆转 
	for (int i = 0; i < v.size(); i++)  // 输出数组元素
		printf("%d", v[i]->Data);
}
]//层次遍历
//遍历完同一层，放入下一层的节点值
void LevelOrderTraversal(BinTree BT) {
	queue<BinTree> q;   // 创建队列
	BinTree T;
	if (!BT)
		return;
	q.push(BT);  // BT 入队 
	while (!q.empty()) {
		T = q.front();  // 访问队首元素 
		q.pop();  // 出队
		printf("%d", T->Data);
		if (T->Left)  // 如果存在左儿子结点
			q.push(T->Left);  // 入队
		if (T->Right)
			q.push(T->Right);
	}
}


/* 树的定义的前置知识
  1. 树的定义
	树（Tree）：n（n≥0）个结点构成的有限集合
  2.基本术语
	结点的度（Degree）：结点的子树个数
	树的度：树的所有结点中最大的度数
	路径长度：路径所包含边的个数
	结点的层次（Level）：规定根结点在 1 层，其他任一结点的层数是其父结点的层数加一
	树的深度（Depth）：树中所有结点中的最大层次是这棵树的深度

	二叉树：度为2的树
			一个有穷的节点集合（可以为空）
	斜二叉树：只有左儿子或只有右儿子
	完美二叉树（满二叉树）：除最后一层叶结点外，每个结点都有两个子结点
	完全二叉树：有 n 个结点的二叉树，对树中结点按从上至下、从左到右顺序进行编号，编号为 i（1 ≤ i ≤ n）结点与满二叉树中编号为 i 结点在二叉树中位置相同
	
		重要性质：
		一个二叉树第 i 层的最大结点数为：2^i-1
		深度为 k 的二叉树有最大结点总数为：2^k-1;
		对任何非空二叉树T，n0表示叶节点的个数，n2表示度为2的非叶节点，n0=n2+1
  3.树的存储
	顺序存储：
		按从上至下、从左到右顺序存储 n 个结点的完全二叉树的结点父子关系：
			非根结点（序号 i > 1）的父结点的序号是 ⌊i/2⌋（向下取整）
			结点（序号为 i）的左孩子结点的序号是 2i（若 2 i ≤ n，否则没有左孩子
			结点（序号为 i）的右孩子结点的序号是 2i+1（若 2 i +1 ≤ n，否则没有右孩子
	链式存储：
		typedef struct TreeNode *BinTree;
		struct TreeNode{
		Element Data;  // 存值 
		BinTree Left;    // 左儿子结点 
		BinTree Right;   // 右儿子结点 
};	
*/
