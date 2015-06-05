#include <stdio.h>

#ifndef P3_FIND_PATH_H
#define P3_FIND_PATH_H

#define MAX 100

typedef struct BinaryTreeNode // a node in the binary tree
{
	int m_nValue; // value of node
	BinaryTreeNode *m_pLeft; // left child of node
	BinaryTreeNode *m_pRight; // right child of node
}BinaryTreeNode;

typedef struct P4Stack
{
	int top;
	int datas[MAX];

}P4Stack;


void createStack(P4Stack **root);
void push(P4Stack *root, int value);
int pop(P4Stack *root);
void printStack(P4Stack *st);

void addBSTreeNode(BinaryTreeNode **root, int value);
void createBSTree(BinaryTreeNode **root, int datas[], int n);
void visitBinaryTree(BinaryTreeNode *root);
void destroy(BinaryTreeNode *root);
void findPath(BinaryTreeNode *root, int target, P4Stack *st);


#endif