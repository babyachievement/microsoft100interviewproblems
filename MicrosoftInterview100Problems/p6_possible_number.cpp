/*
����10����ʱ�䣬�������Ÿ���ʮ�������������������Ӧ��ʮ����
Ҫ������ÿ����������ǰ������ʮ���������ų��ֵĴ�����
���ŵ�ʮ�������£�
��0��1��2��3��4��5��6��7��8��9��
*/

#include "stdafx.h"

NumberTB::NumberTB()
{
	success = false;
	//format top   
	for (int i = 0; i<len; i++)
	{
		top[i] = i;
	}
}


int* NumberTB::getBottom()
{
	int i = 0;
	while (!success)
	{
		i++;
		setNextBottom();
	}
	return bottom;
}

//set next bottom   
void NumberTB::setNextBottom()
{
	bool reB = true;

	for (int i = 0; i<len; i++)
	{
		int frequecy = getFrequecy(i);

		if (bottom[i] != frequecy)
		{
			bottom[i] = frequecy;
			reB = false;
		}
	}
	success = reB;
}

//get frequency in bottom   
int NumberTB::getFrequecy(int num)   //�˴���num��ָ���ŵ��� i
{
	int count = 0;

	for (int i = 0; i<len; i++)
	{
		if (bottom[i] == num)
			count++;
	}
	return count;    //cout����Ӧ frequecy
}




/*
NumberTB nTB;
int* result = nTB.getBottom();

for (int i = 0; i<len; i++)
{
cout << *result++ << endl;
}

*/