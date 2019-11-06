#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

class QNumber
{
protected:
	int data[4];
	string number;
public:
	QNumber()
	{
		for (int i = 0; i <= 3; i++)
			this->data[i] = 0;
		this ->number = "0";
	}
	QNumber(string number)
	{
		for (int i = 0; i <= 3; i++)
			this->data[i] = 0;
		this->number = number;
	}
	~QNumber()
	{

	}
	virtual void printDataMember()
	{
		for (int i = 3; i >= 0; i--)
			cout << this->data[i] << endl;
		cout << endl;
	}
	virtual void print() = 0;
	virtual string reduceZeroInBin(string bin)
	{

		while (bin[0] == '0')
		{
			bin.erase(0, 1);
		}
		if (bin.size() == 0)
			bin = "0000";
		return bin;
	}
};
