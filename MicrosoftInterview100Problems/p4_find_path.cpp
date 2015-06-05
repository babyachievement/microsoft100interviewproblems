/*4
题目：输入一个整数和一棵二元树。
从树的根结点开始往下访问一直到叶结点所经过的所有结点形成一条路径。
打印出和与输入整数相等的所有路径。
例如 输入整数 22 和如下二元树
 10
 / \
 5  12
/ \
4 7
则打印出两条路径：10, 12 和 10, 5, 7。
二元树节点的数据结构定义为：
struct BinaryTreeNode // a node in the binary tree
{
int m_nValue; // value of node
BinaryTreeNode *m_pLeft; // left child of node
BinaryTreeNode *m_pRight; // right child of node
};
*/
#include "stdafx.h"


void createBSTree(BinaryTreeNode **root, int datas[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		addBSTreeNode(root, datas[i]);
	}
}

void addBSTreeNode(BinaryTreeNode **root, int value)
{
	if (NULL == (*root))
	{
		*root = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
		(*root)->m_pLeft = NULL;
		(*root)->m_pRight = NULL;
		(*root)->m_nValue = value;
	}
	else if ((*root)->m_nValue > value)
	{
		addBSTreeNode(&((*root)->m_pLeft), value);
	}
	else
	{
		addBSTreeNode(&((*root)->m_pRight), value);
	}
}


void visitBinaryTree(BinaryTreeNode *root)
{
	if (NULL != root)
	{
		visitBinaryTree(root->m_pLeft);
		printf("%d ", root->m_nValue);
		visitBinaryTree(root->m_pRight);
	}
}


void printStack(P4Stack *st)
{
	int temp = 0;
	if (NULL != st){
		while (temp <= st->top)
		{
			printf("%d ", st->datas[temp++]);
		}
		printf("\n");
	}
}

int sum = 0;
int flag = 0;

void findPath(BinaryTreeNode *root, int target, P4Stack *st)
{
	if (NULL == root)
	{
		flag = 0;
	}else 
	{
		sum += root->m_nValue;
		push(st, root->m_nValue);
		findPath(root->m_pLeft, target, st);

		findPath(root->m_pRight, target, st);
		
		if (sum == target)
		{
			sum -= root->m_nValue;
			printStack(st);
			if (root->m_pLeft==NULL && root->m_pRight == NULL)
				pop(st);
			flag = 1;
		}
		else
		{
			sum -= root->m_nValue;
			flag = 0;
			pop(st);
		}		
	}
}

void destroy(BinaryTreeNode *root)
{
	if (NULL != root)
	{
		destroy(root->m_pLeft);
		destroy(root->m_pRight);
		free(root);
	}
}



/**************************stack operation****************************************/

void createStack(P4Stack **root)
{
	if (NULL == *root)
	{
		*root = (P4Stack *)malloc(sizeof(P4Stack));
		(*root)->top = -1;
	}
}
void push(P4Stack *st, int value)
{
	if (NULL == st)
	{
		return;
	}
	//printf("push %d\n", value);

	st->top++;
	st->datas[st->top] = value;

}
int pop(P4Stack *st)
{
	if (NULL == st)
	{
		return INT_MIN;
	}

	if (st->top > -1)
	{
		return st->datas[st->top--];
	}
	else
	{
		return INT_MIN;
	}
}



/*
int datas[] = { 10,5, 4, 3, 7, 12,13};
BinaryTreeNode *rootPtr = NULL;
P4Stack *st = NULL;

createBSTree(&rootPtr, datas, sizeof(datas) / sizeof(int));
visitBinaryTree(rootPtr);
printf("\n");
createStack(&st);

findPath(rootPtr, 22, st);

printf("\n");
*/