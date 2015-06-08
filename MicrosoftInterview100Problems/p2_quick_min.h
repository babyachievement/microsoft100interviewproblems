#include <stdio.h>
#include <stdlib.h>

#ifndef P2_QUICK_STACK_MIN_H
#define P2_QUICK_STACK_MIN_H

#define MAX 100
typedef struct stack
{
	int data[MAX];
	int min_values[MAX];

	int top;
}stack;

void createStack(stack **st);
void push(stack *st, int value);
int pop(stack *st);
void destroy(stack *st);

#endif