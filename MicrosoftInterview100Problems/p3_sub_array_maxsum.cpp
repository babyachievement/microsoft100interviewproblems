/*3
* 输入一个整形数组，数组里有正数也有负数。
* 数组中连续的一个或多个整数组成一个子数组，每个子数组都有一个和。
* 求所有子数组的和的最大值。要求时间复杂度为O(n)。
*/

#include "stdafx.h"

#define MAX 100
int max[MAX];

int maxSum(int *a, int n)
{
	int i,sumMax = 0;

	/*
	防止全部为负数
	*/
	if (n > 0)
		sumMax = a[0];
	for (i = 0; i < n; i++)
	{
		if (i == 0)
		{
			max[i] = a[i];
		}
		else
		{
			if (max[i - 1] < 0)
			{
				max[i] = a[i];
			}
			else
			{
				max[i] = a[i] + max[i - 1];
			}
		}

		if (sumMax < max[i])
		{
			sumMax = max[i];
		}
	}

	return sumMax;
}

/*
int a[10] = { 1, -8, 6, 3, -1, 5, 7, -2, 0, 1 };
int b[10] = { -1, -8, -6, -3, -1, -5, -7, -2, -10, -11 };
printf("max sum: %d\n", maxSum(a, 10));
printf("max sum: %d\n", maxSum(b, 10));
*/