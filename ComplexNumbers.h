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

	ComplexNumber operator+ (ComplexNumber right);
	ComplexNumber operator- (ComplexNumber right);
	//prefix
	ComplexNumber operator++ ();
	ComplexNumber operator-- ();
	//postfix
	ComplexNumber operator++ (int);
	ComplexNumber operator-- (int);

	
	bool operator== (ComplexNumber right);
	bool operator!= (ComplexNumber right);
	void operator= (ComplexNumber right);

	explicit operator int();

	~ComplexNumber();

};