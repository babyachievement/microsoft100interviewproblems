

#ifndef P6_POSSIBLE_NUMBER_H
#define P6_POSSIBLE_NUMBER_H
#define len 10

class NumberTB
{
private:
	int top[len];
	int bottom[len];
	bool success;
public:
	NumberTB();
	int* getBottom();
	void setNextBottom();
	int getFrequecy(int num);
};

#endif