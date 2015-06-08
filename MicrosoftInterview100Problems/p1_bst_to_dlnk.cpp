/*
* 1. ����һ�ö�Ԫ�����������ö�Ԫ������ת����һ�������˫������
* Ҫ���ܴ����κ��µĽ�㣬ֻ����ָ���ָ��
*/

#include "stdafx.h"


BSTreeNode *head = NULL, *tail = NULL;
void addBSTreeNode(BSTreeNode **root, int value)
{
	if (NULL == (*root))
	{
		*root = (BSTreeNode *)malloc(sizeof(BSTreeNode));
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

void createBSTree(BSTreeNode **root, int datas[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		addBSTreeNode(root, datas[i]);
	}
}
void createList(BSTreeNode *cur){
	cur->m_pLeft = tail;//�ѵ�ǰ��root�ӵ������β�� 
	if (tail != NULL){//˫������ 
		tail->m_pRight = cur;
	}
	else{
		head = cur;
	}
	tail = cur;//����β���Ϊ��ǰ��㣬����˵��β������ 
}


void visit(BSTreeNode *root)
{
	if (NULL == root)
	{
		return;
	}
	visit(root->m_pLeft);
	createList(root);
	//printf("%d ", root->m_nValue);
	visit(root->m_pRight);
}


void destroy(BSTreeNode *root)
{
	if (NULL != root)
	{
		destroy(root->m_pLeft);
		destroy(root->m_pRight);
		free(root);
	}
}



/*
int datas[] = {10, 6, 4, 8, 14, 12, 16};
BSTreeNode *rootPtr = NULL;
extern BSTreeNode *head;

createBSTree(&rootPtr, datas, sizeof(datas) / sizeof(int));
visit(rootPtr);
while (NULL != head)
{
printf("%d ", head->m_nValue);
head = head->m_pRight;
}
printf("\n");
*/