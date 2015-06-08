/*
给你10分钟时间，根据上排给出十个数，在其下排填出对应的十个数
要求下排每个数都是先前上排那十个数在下排出现的次数。
上排的十个数如下：
【0，1，2，3，4，5，6，7，8，9】
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
int NumberTB::getFrequecy(int num)   //此处的num即指上排的数 i
{
	int count = 0;

	for (int i = 0; i<len; i++)
	{
		if (bottom[i] == num)
			count++;
	}
	return count;    //cout即对应 frequecy
}




/*
NumberTB nTB;
int* result = nTB.getBottom();

for (int i = 0; i<len; i++)
{
cout << *result++ << endl;
}

*/