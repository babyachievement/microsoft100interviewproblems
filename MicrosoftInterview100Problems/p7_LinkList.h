#include <stdio.h>
#include <stdlib.h>

#ifndef P7_LINK_LIST_H
#define P7_LINK_LIST_H

typedef struct LinkNode{
	int iValue;
	struct LinkNode *next;
}LinkNode;

void create_linklist(LinkNode **listPP);

void add_node(LinkNode *listP, int value);

void visit_list(LinkNode *listP);

void destroy_list(LinkNode *listP);

int check_circle_exists_in_list(LinkNode *listP);
LinkNode *get_last_node(LinkNode *listP);
int chec_node_in_list(LinkNode *listP, LinkNode *node);
int check_if_two_list_have_cross_node(LinkNode *list1, LinkNode *list2);
#endif