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
public:
	QInt();
	QInt(string);
	~QInt();

	void printData();
	void storeData();
	void inputNumber(string);
	void inputNumber();

	void divideByTwo();
	void multiplyByTwo();


	void convertDecToBin();
	void convertBinToDec();

	QInt operator+ (const QInt& b); 
};