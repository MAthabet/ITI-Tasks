#include "ComplexNumbers.h"
#include <iostream>

ComplexNumber::ComplexNumber()
{
}

ComplexNumber::ComplexNumber(int r, int i)
{
	imaginryNum = i;
	realNum = r;
}
void ComplexNumber::print()
{
	printf("(%d + %di)", this->realNum, this->imaginryNum);
}

ComplexNumber add(ComplexNumber x, ComplexNumber y)
{
	ComplexNumber ans;
	ans.realNum = x.realNum + y.realNum;
	ans.imaginryNum = x.imaginryNum + y.imaginryNum;
	return ans;
}
ComplexNumber subtract(ComplexNumber x, ComplexNumber y)
{
	return ComplexNumber(x.realNum - y.realNum, x.imaginryNum - y.imaginryNum);
}