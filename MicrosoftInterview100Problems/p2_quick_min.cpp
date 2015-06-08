/*2.
* 定义栈的数据结构，要求添加一个min函数，能够得到栈的最小元素。
* 要求函数min、push以及pop的时间复杂度都是O(1)。
*/

#include "stdafx.h"

void createStack(stack **st)
{
	if (NULL == *st)
	{
		*st = (stack *)malloc(sizeof(stack));
		(*st)->top = -1;
	}
}

void push(stack *st, int value)
{
	int lastMinValue;

	if (NULL == st)
	{
		return;
	}

	st->top++;
	st->data[st->top] = value;

	if (st->top == 0)
	{
		st->min_values[st->top] = value;
	}
	else
	{
		lastMinValue = st->min_values[st->top - 1];
		if (value >= lastMinValue)
		{
			st->min_values[st->top] = lastMinValue;
		}
		else
		{
			st->min_values[st->top] = value;
		}
	}
}

int pop(stack *st)
{
	if (NULL == st)
	{
		return INT_MIN;
	}

	if (st->top > -1)
	{
		return st->data[st->top--];
	}
	else
	{
		return INT_MIN;
	}
}

void destroy(stack *st)
{
	if (st != NULL)
		free(st);
}

/*
stack *st = NULL;
createStack(&st);

push(st, 3);
printf("min : %d\n", st->min_values[st->top]);
push(st, 3);
printf("min : %d\n", st->min_values[st->top]);
push(st, 4);
printf("min : %d\n", st->min_values[st->top]);
push(st, 5);
printf("min : %d\n", st->min_values[st->top]);
push(st, 1);
printf("min : %d\n", st->min_values[st->top]);
push(st, 2);
printf("min : %d\n", st->min_values[st->top]);

pop(st);
printf("min : %d\n", st->min_values[st->top]);
pop(st);
printf("min : %d\n", st->min_values[st->top]);
pop(st);
printf("min : %d\n", st->min_values[st->top]);
*/