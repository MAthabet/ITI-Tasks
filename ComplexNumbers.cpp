#include "ComplexNumbers.h"

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

ComplexNumber ComplexNumber::operator+ (ComplexNumber right)
{
	ComplexNumber ans;
	ans.setRealNum(this->getRealNum() + right.getRealNum());
	ans.setImgNum(this->getImgNum() + right.getImgNum());
	return ans;
}
ComplexNumber ComplexNumber::operator- (ComplexNumber right)
{
	ComplexNumber ans;
	ans.setRealNum(this->getRealNum() - right.getRealNum());
	ans.setImgNum(this->getImgNum() - right.getImgNum());
	return ans;
}
bool ComplexNumber::operator== (ComplexNumber right)
{
	if (this->getRealNum() == right.getRealNum())
		if (this->getImgNum() == right.getImgNum())
			return true;
	return false;
}
bool ComplexNumber::operator!= (ComplexNumber right)
{
	if (this->getRealNum() != right.getRealNum()) return false;
	if (this->getImgNum() != right.getImgNum()) return false;
	return true;
}
void ComplexNumber::operator= (ComplexNumber right)
{
	this->setRealNum(right.getRealNum());
	this->setImgNum(right.getImgNum());
}



