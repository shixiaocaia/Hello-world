#include<Linkk.h>
using namespace std;
MaxHeap Create(int MaxSize)  // 建堆 
{
	MaxHeap H = (MaxHeap)malloc(sizeof( MaxHeap));
	H->Elements = (ElementType*)malloc(sizeof(ElementType) * Maxsize+1);
	H -> size = 0;
	H->capacity = Maxsize;
	H->Elements[0] = Maxsize;
	return H;

}
bool IsFull(MaxHeap H)    // 判断堆是否满
{
	//if (H->size == H->capacity)	 return true;
	//else return false;
	return (H->size == H->capacity);
}

bool IsEmpty(MaxHeap H)    //  判断堆是否为空
{
	return (H->size == 0);
}
bool Insert(MaxHeap H, ElementType item)   // 插入元素
{
	if (IsFull(H))
	{
		printf("heap is full\n");
		return false;
	}
	else {
		int i = ++H->size;//插入到最后的位置
		for (; H->Elements[i / 2] < item; i /= 2)
			H->Elements[i] = H->Elements[i / 2];//比较父亲节点的值，比他大，向下放
		H->Elements[i] = item;//找到了合适的位置
		return true;
	}
}

ElementType DeleteMax(MaxHeap H)  // 删除并返回堆中最大元素
{
	int parent, child;
	parent = 1;
	ElementType Max, tmp;
	if (IsEmpty(H))
	{
		printf("heap is empty\n");
		return 0;
	}
	else {
		tmp = H->Elements[H->size--];
		Max = H->Elements[1];//返回删除的值
		for (; parent * 2 <= H->size; parent = child)//从上向下遍历，不断向下遍历
		{
			child = 2 * parent;//左节点
			if (child != H->size && H->Elements[child] < H->Elements[child + 1])//存在右节点，取最大的节点
				child++;
			if (H->Elements[child] <= tmp)	break;//比这个堆左右节点值都大，可以放在这
			else
				H->Elements[parent] = H->Elements[child];//向上放
		}
		H->Elements[parent] = tmp;
		return Max;
	}
}
void LevelOrderTraversal(MaxHeap H)  // 层序遍历 
{
	for (int i= 1; i <= H->size; i++)
		printf("%d ", H->Elements[i]);
	printf("\n");
}


int main()
{
	MaxHeap H;
	H = Create(Maxsize);
	Insert(H,58);
	Insert(H,44);
	Insert(H,25);
	Insert(H,35);
	Insert(H,31);
	LevelOrderTraversal(H);
	/*
	    58
	   /  \
      44	  25
	 /  \
	35  31
	*/
	DeleteMax(H);
	
	LevelOrderTraversal(H);
	return 0;
}
