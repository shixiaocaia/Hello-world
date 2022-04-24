#include<Linkk.h>
using namespace std;

Stack makestack()
{
	Stack S;
	S = (Stack)malloc(sizeof(struct SNode));
	S->top = -1;
	return S;
}

int checkfull(Stack S)
{
	if (S->top == Maxsize - 1)	return 1;
	else return 0;
}

int checkempty(Stack S)
{
	if (S->top ==- 1)	return 1;
	else return 0;
}


void push(Stack S, int x)
{
	if (checkfull(S)) {
		cout << "stack full" << endl;
		return;
	}
	else{
		S->top++;
		S->data[S->top] = x;
		return;
	}
}

int pop(Stack S)
{
	if (checkempty(S)) {
		cout << "stack empty" << endl;
		return 0;
	}
	else {
		int t = S->data[S->top];
		S->top--;
		return t;
	}
}


int main()
{
	Stack S;
	S = makestack();
	cout << "5入栈" << endl;
	push(S, 5);
	cout << "6入栈" << endl;
	push(S, 6);
	cout << "7入栈" << endl;
	push(S, 7);
	cout << pop(S) << endl;
	cout << pop(S) << endl;



	return 0;
}
