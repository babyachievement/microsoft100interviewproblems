/*
给出俩个单向链表的头指针，比如 h1，h2，判断这俩个链表是否相交。
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
	判断两个链表是否有交点
*/
int check_if_two_list_have_cross_node(LinkNode *list1, LinkNode *list2)
{
	int flag = 0;
	LinkNode *p1, *p2;

	// 1. 都不存在环, 检查最后一个节点是不是同一个节点
	if (!check_circle_exists_in_list(list1) && !check_circle_exists_in_list(list2))
	{
		p1 = get_last_node(list1);
		p2 = get_last_node(list2);

		if (p1 == p2)
			flag = 1;
	}
	// 1. 都存在环,检查一个链表的节点是否有在另个链表中出现
	else if (check_circle_exists_in_list(list1) && check_circle_exists_in_list(list2))
	{
		// 遍历list1中所有节点
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