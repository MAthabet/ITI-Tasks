#include "ComplexNumbers.h"
#include <iostream>

int ComplexNumber::counter = 0;

ComplexNumber::ComplexNumber()
{
	setImgNum(0);
	setRealNum(0);
	counter++;
}

ComplexNumber::~ComplexNumber()
{
	counter--;
}

ComplexNumber::ComplexNumber(int r, int i)
{
	setImgNum(i);
	setRealNum(r);
	counter++;
}
ComplexNumber::ComplexNumber(int r)
{
	setRealNum(r);
	setImgNum(0);
	counter++;
}
int ComplexNumber::getImgNum()
{
	return ComplexNumber::imaginryNum;
}
int ComplexNumber::getRealNum()
{
	return ComplexNumber::realNum;
}
void ComplexNumber::setImgNum(int i)
{
	ComplexNumber::imaginryNum = i;
}
void ComplexNumber::setRealNum(int r)
{
	ComplexNumber::realNum = r;
}

void ComplexNumber::print()
{
	printf("(%d + %di)", this->realNum, this->imaginryNum);
}

ComplexNumber* add(ComplexNumber* x, ComplexNumber* y)
{
	ComplexNumber ans;
	ans.setRealNum(x->getRealNum() + y->getRealNum());
	ans.setImgNum(x->getImgNum() + y->getImgNum());
	return &ans;
}
ComplexNumber* subtract(ComplexNumber* x, ComplexNumber* y)
{
	ComplexNumber ans;
	ans.setRealNum(x->getRealNum() - y->getRealNum());
	ans.setImgNum(x->getImgNum() - y->getImgNum());
	return &ans;
}

