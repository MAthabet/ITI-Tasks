#pragma once
class ComplexNumber
{
public:
	int imaginryNum;
	int realNum;

	ComplexNumber();

	ComplexNumber(int r, int i);

	void print();
};
ComplexNumber add(ComplexNumber x, ComplexNumber y);
ComplexNumber subtract(ComplexNumber x, ComplexNumber y);