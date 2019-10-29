#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;


class QInt
{
private:
	int data[4];
	string number;

	string dividedByTwo(string);
	void storeToQInt();
	static QInt convertToQInt(string bin);
	QInt join(QInt &a,QInt &q, int n);
	void split(QInt& join, QInt &a, QInt& q, int n);
	void ShiftRight(QInt &a, QInt& q, int& lastBit, int n);
	string convertToStoreData();
	void executeTwosComplenment();
public:
	QInt();
	QInt(string);
	QInt(QInt const &);
	~QInt();
	
	void printData();
	void print();

	QInt ROR(int n);
	QInt ROL(int n);
	QInt operator>> (int n);
	QInt operator<< (int n);

	int countAmountBits();

	string convertDecToBin();
	string convertBinToHex();
	string convertQIntToDec();
	static string convertBinToDec(string bin);
	static string convertDecToHex(string dec);
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


	bool operator> (QInt& const b);
	bool operator< (QInt& const b);
	bool operator>= (QInt& const b);
	bool operator<= (QInt& const b);
	bool operator== (QInt& const b);

};