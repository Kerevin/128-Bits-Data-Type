#pragma once
#include "QNumber.h"


class QInt : public QNumber
{
private:
	

	void storeToQInt();

	string convertToStoreData();

	QInt join(QInt &a,QInt &q, int n);
	void split(QInt& join, QInt &a, QInt& q, int n);
	void ShiftRight(QInt &a, QInt& q, int& lastBit, int n);
	

public:
	QInt();
	QInt(string);
	QInt(QInt const &);
	~QInt();

	static string dividedByTwo(string);
	static QInt convertBinToQInt(string bin);
	virtual void printData();
	virtual void print();

	virtual QInt ROR(int n);
	virtual QInt ROL(int n);
	virtual QInt operator>> (int n);
	virtual QInt operator<< (int n);

	virtual int countAmountBits();
	virtual void executeTwosComplenment();

	virtual string convertDecToBin();
	virtual string convertBinToHex();
	virtual string convertQIntToDec();

	static string convertBinToHex(string bin);
	static string convertBinToDec(string bin);
	static string convertDecToHex(string dec);
	static string convertDecToBin(string dec);
	static string convertHexToBin(string hex);
	static string convertHexToDec(string hex);
	


	QInt operator+ (QInt& const b);
	QInt operator- (QInt& const b);
	QInt operator* (QInt& const q);
	QInt operator/ (QInt& const m);

	QInt operator& (QInt& const b);
	QInt operator| (QInt& const b);
	QInt operator^ (QInt& const b);
	QInt operator~ ();
	QInt& operator= (const QInt&  b);

	bool operator> (QInt& const b);
	bool operator< (QInt& const b);
	bool operator>= (QInt& const b);
	bool operator<= (QInt& const b);
	bool operator== (QInt& const b);
	
};