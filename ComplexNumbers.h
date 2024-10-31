#pragma once
class ComplexNumber
{
private:
	int imaginryNum;
	int realNum;

public:
	 static int counter;
	ComplexNumber();
	ComplexNumber(int r, int i);
	ComplexNumber(int r);
	int getImgNum();
	int getRealNum();
	void setImgNum(int i);
	void setRealNum(int r);
	void print();
	~ComplexNumber();
};
ComplexNumber add(ComplexNumber x, ComplexNumber y);
ComplexNumber subtract(ComplexNumber x, ComplexNumber y);