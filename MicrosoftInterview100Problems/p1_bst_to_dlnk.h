#include <stdio.h>
#include <stdlib.h>


#ifndef P1_BST_TODLNK_H
#define P1_BST_TODLNK_H

typedef struct BSTreeNode
{
	int m_nValue; // value of node
	BSTreeNode *m_pLeft; // left child of node
	BSTreeNode *m_pRight; // right child of node
}BSTreeNode;
void addBSTreeNode(BSTreeNode **root, int value);
void createBSTree(BSTreeNode **root, int datas[], int n);
void visit(BSTreeNode *root);
void destroy(BSTreeNode *root);
#endif