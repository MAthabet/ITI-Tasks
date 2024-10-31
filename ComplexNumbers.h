#pragma once
class ComplexNumber
{
private:
	int imaginryNum;
	int realNum;

public:
	ComplexNumber();
	ComplexNumber(int r, int i);
	void print();
};
ComplexNumber add(ComplexNumber x, ComplexNumber y);
ComplexNumber subtract(ComplexNumber x, ComplexNumber y);