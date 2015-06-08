/*
�����������������ͷָ�룬���� h1��h2���ж������������Ƿ��ཻ��
*/

#include "stdafx.h"


void create_linklist(LinkNode **listPP)
{
	if (NULL == *listPP)
	{
		*listPP = (LinkNode *)malloc(sizeof(LinkNode));
		(*listPP)->next = NULL;
	}
}

void add_node(LinkNode *listP, int value)
{
	LinkNode *p = NULL;
	if (NULL != listP)
	{
		p = listP;
		while (NULL != p->next)
		{
			p = p->next;
		}

		LinkNode *new_node = (LinkNode *)malloc(sizeof(LinkNode));
		new_node->iValue = value;
		new_node->next = NULL;
		p->next = new_node;
	}
}

void visit_list(LinkNode *listP)
{
	while (NULL != listP)
	{
		printf("%d ", listP->iValue);
		listP = listP->next;
	}
}

void destroy_list(LinkNode *listP)
{
	LinkNode *p = NULL;
	while (NULL != listP)
	{
		p = listP->next;
		free(listP);
		listP = p;
	}
}


int check_circle_exists_in_list(LinkNode *listP)
{
	int flag = 0;
	LinkNode *p1, *p2;
	if (NULL != listP)
	{
		p1 = listP->next;
		if (NULL != p1)
		{
			p2 = p1->next;
		}

		while (p1!=NULL&&p2!=NULL)
		{
			if (p1 == p2)
			{
				flag = 1;
				break;
			}
			else
			{
				p1 = p1->next;
				if (NULL != p1)
					p2 = p1->next;
				else
					break;
			}
		}
	}

	return flag;
}


LinkNode *get_last_node(LinkNode *listP)
{
	if (listP != NULL)
	{
		while (listP->next != NULL)
			listP = listP->next;
		return listP;
	}
	else
		return NULL;
}

int chec_node_in_list(LinkNode *listP, LinkNode *node)
{
	while (listP != NULL && node != listP)
		listP = listP->next;
	if (NULL == listP)
		return 0;
	else
		return 1;
}

/*
	�ж����������Ƿ��н���
*/
int check_if_two_list_have_cross_node(LinkNode *list1, LinkNode *list2)
{
	int flag = 0;
	LinkNode *p1, *p2;

	// 1. �������ڻ�, ������һ���ڵ��ǲ���ͬһ���ڵ�
	if (!check_circle_exists_in_list(list1) && !check_circle_exists_in_list(list2))
	{
		p1 = get_last_node(list1);
		p2 = get_last_node(list2);

		if (p1 == p2)
			flag = 1;
	}
	// 1. �����ڻ�,���һ������Ľڵ��Ƿ�������������г���
	else if (check_circle_exists_in_list(list1) && check_circle_exists_in_list(list2))
	{
		// ����list1�����нڵ�
		while (list1 != NULL)
		{
			if (!chec_node_in_list(list2, list1))
			{
				list1 == list1->next;
			}
			else
			{
				flag = 1;
				break;
			}
		}
	}

	return flag;
}