#define _CRT_SECURE_NO_WARNINGS

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
//prefix
ComplexNumber ComplexNumber::operator++ ()
{
	this->realNum++;
	this->imaginryNum++;
	return *this;
}
ComplexNumber ComplexNumber::operator-- ()
{
	this->realNum--;
	this->imaginryNum--;
	return *this;
}
//postfix
ComplexNumber ComplexNumber::operator++ (int)
{
	ComplexNumber temp = *this;
	this->realNum++;
	this->imaginryNum++;
	return temp;
}
ComplexNumber ComplexNumber::operator-- (int)
{
	ComplexNumber temp = *this;
	this->realNum--;
	this->imaginryNum--;
	return temp;
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
 ComplexNumber::operator int() 
{
	return this->realNum;
}

 void compNUmMenu()
 {
	 int a, b;

	 printf("\nEnter first complex number (R +Ii):");
	 printf("\n Enter Real part : ");
	 scanf("%d", &a);
	 printf("\n Enter Imaginry part : ");
	 scanf("%d", &b);
	 ComplexNumber x = ComplexNumber(a, b);

	 printf("\nEnter Second complex number (R +Ii):");
	 printf("\n Enter Real part : ");
	 scanf("%d", &a);
	 printf("\n Enter Imaginry part : ");
	 scanf("%d", &b);

	 ComplexNumber y = ComplexNumber(a, b);
	 ComplexNumber ans = x + y;


	 printf("\n");
	 x.print();printf(" + ");y.print();printf(" = ");
	 ans.print();
	 printf("\n");

	 ans = x - y;
	 x.print();printf(" - ");y.print();printf(" = ");
	 ans.print();
	 printf("\n");
	 printf("complex numbers counter : %d", ComplexNumber::counter);
	 printf("\ncomplex number as int : %d", (int)ans);
	 x++;
	 printf("\n first number after postfix increment: ");
	 x.print();
	 y--;
	 printf("\n second number after postfix decrement:");
	 y.print();
	 --x;
	 printf("\n first number after prefix decrement: ");
	 x.print();
	 ++y;
	 printf("\n second number after prefix decrement:");
	 y.print();
 }
