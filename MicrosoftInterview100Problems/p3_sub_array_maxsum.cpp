/*3
* ����һ���������飬������������Ҳ�и�����
* ������������һ�������������һ�������飬ÿ�������鶼��һ���͡�
* ������������ĺ͵����ֵ��Ҫ��ʱ�临�Ӷ�ΪO(n)��
*/

#include "stdafx.h"

#define MAX 100
int max[MAX];

int maxSum(int *a, int n)
{
	int i,sumMax = 0;

	/*
	��ֹȫ��Ϊ����
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