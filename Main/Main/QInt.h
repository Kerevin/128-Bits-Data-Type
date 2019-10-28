#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;


class QInt
{
private:
	int data[4];
	string number;
	string dividedByTwo(string);
	void storeData();
public:
	QInt();
	QInt(string);
	~QInt();

	void printData();
	
	void 

	void SHR(int n);
	void SHL(int n);
	void ROR(int n);
	void ROL(int n);

	int countAmountBits();

	string convertDecToBin();
	void convertBinToDec();

	QInt operator+ (const QInt& b); 
	QInt operator- (const QInt& b);
	QInt operator* (const QInt& b);
	QInt operator/ (const QInt& b);

	void operator& (const QInt& b);
	void operator| (const QInt& b);
	void operator^ (const QInt& b);
	void operator~ ();

};