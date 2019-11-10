#pragma once
#include "QInt.h"


class QFloat : public QNumber
{
private:

    void storeDecIntoQFloat();
    string multipliedByTwo(string num);



public:
    QFloat();
    QFloat(string number);
    QFloat(QFloat const& p);
    ~QFloat();

    string convertFractionalToBin();
    string convertIntegalToBin();
    string contertToFloatingPointFormat();
    string normalizeTheNumber(int&);
    string sum(string a, string b);
    virtual string dividedByTwo(string a);
    virtual void print();
    virtual void printData();

    virtual string reduceZeroInBin(string);

    static string convertDecToBin(string &dec);
    static string convertBinToDec(string& bin);

    virtual string convertFractionalBinToDec(string bin);
    virtual string convertQFloatToDec();
    virtual string convertNumberToBin();

};
