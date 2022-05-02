#pragma once
#include<iostream>
#include<malloc.h>
#include<stdio.h>
using namespace std;
typedef struct Lnode* List;
typedef struct SNode* Stack;
typedef struct QNode* Queue;
typedef int ElementType;
typedef struct HeapStruct *MaxHeap;
typedef struct TreeNode* Bintree;
#define Maxsize 1000

struct Lnode {
	int data;
	List Next;
};
List L;

struct SNode {
	int data[Maxsize];
	int top;
};
Stack S;

struct Node {
	int data;
	struct Node* Next;
};
struct QNode {
	struct Node* rear;
	struct Node* front;
};

struct HeapStruct {
	ElementType* Elements;
	int size;
	int capacity;
};

struct TreeNode {
	int Data;
	Bintree Left;
	Bintree Right;
};
