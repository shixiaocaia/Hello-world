#include<Linkk.h>
using namespace std;

Queue createqueue()
{
	Queue Q;
	Q = (Queue)malloc(sizeof(struct QNode));
	Q->front = NULL;
	Q->rear = NULL;
	return Q;
}

int Isempty(Queue Q)
{
	if (Q->front==NULL)	return 1;
	else return 0;
}

void Addqueue(Queue Q, int x)
{
	struct Node* node;
	node = (struct Node*)malloc(sizeof(struct Node));//这里需要的是Node型，注意typedef的是Qnode类型
	node->data = x;
	node->Next = NULL;
	if (Q->rear == NULL)//队列为空时候
	{
		Q->rear = node;
		Q->front = node;
	}
	else {
		Q->rear->Next = node;
		Q->rear = node;//rear保持在最后一个元素位置
	}

}

int delequeue(Queue Q)
{
	struct Node* frontcell;
	int frontt;
	if (Isempty(Q)) {
		cout << "queue is empty" << endl;
		return 0;
	}
	else {
		frontcell = Q->front;
		if (Q->front == Q->rear)
		{
			Q->front = Q->rear = NULL;
		}
		else {
			Q->front = Q->front->Next;
		}
		frontt = frontcell->data;
		free(frontcell);
		return frontt;
	}
}
int main()
{
	Queue Q;
	Q = createqueue();
	cout << "enter 5" << endl;
	cout << "enter 6" << endl;
	cout << "enter 7" << endl;
	Addqueue(Q, 5);
	Addqueue(Q, 6);
	Addqueue(Q, 7);
	cout << delequeue(Q) << endl;
	cout << delequeue(Q) << endl;



	return 0;
}
