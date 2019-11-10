#include "QFloat.h"

QFloat::QFloat() : QNumber()
{
}
QFloat::QFloat(string number) : QNumber(number)
{

	this->storeDecIntoQFloat();
}
QFloat::QFloat(QFloat const& p)
{
	for (int i = 0; i < 4; i++)
		this->data[i] = p.data[i];
	this->number = p.number;
	
}
QFloat::~QFloat()
{
}

void QFloat::print()
{
	cout << this->number << endl;
}
void QFloat::printData()
{
	printDataMember();
}

string QFloat::sum(string a, string b)
{
	// a + b //
	int lenA = a.size() - 1;
	int lenB = b.size() - 1;
	string result;
	int temp = 0;
	while (lenA >= 0 && lenB >= 0)
	{

		int num = stoi(a.substr(lenA--, 1)) + stoi(b.substr(lenB--, 1)) + temp;
		temp = num / 10;
		result.insert(0, to_string(num % 10));

	}
	while (lenA >= 0)
	{
		int num = stoi(a.substr(lenA--, 1)) + temp;
		temp = num / 10;
		result.insert(0, to_string(num % 10));
	}
	while (lenB >= 0)
	{
		int num = stoi(b.substr(lenB--, 1)) + temp;
		temp = num / 10;
		result.insert(0, to_string(num % 10));
	}
	if (temp > 0)
	{
		result.insert(0, to_string(temp));
	}
	return result;
}
string QFloat::dividedByTwo(string a)
{
	// Chia có phần thập phân //
	string temp = "";
	int sodu = 0;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] != '.')
		{
			int num = stoi(a.substr(i, 1));
			temp += to_string((sodu * 10 + num) / 2);
			sodu = (num % 2 != 0);
		}
		else
			temp += ".";
	}
	if (sodu > 0)
	{
		if (temp.find('.') == -1)
			temp += ".5";
		else
			temp += "5";
	}

	while (temp[0] == '0')
		temp.erase(0, 1);
	return temp;
}
string QFloat::reduceZeroInBin(string bin)
{
	string result = bin;
	while (result[0] == '0')
	{
		result.erase(0, 1);
	}
	while (result.size() % 4 != 0)
	{
		result.insert(0, "0");
	}
	if (result.size() == 0)
		result += "0";
	return result;
}
string QFloat::multipliedByTwo(string a)
{
	string result = "";
	int sodu = 0;
	for (int i = a.length() - 1; i >= 0; i--)
	{
		int number = stoi(a.substr(i, 1)) * 2 + sodu;
		sodu = int(number / 10);
		result.insert(0, to_string(number % 10));
	}
	if (sodu != 0)
		result.insert(0, to_string(sodu));
	return result;
}


string QFloat::contertToFloatingPointFormat()
{
	// Binary của phần số nguyên //
	string binIntegalPart = convertIntegalToBin();
	
	// Binary của phần thập phân //
	string binFractionPart = convertFractionalToBin();

	string result = binIntegalPart;

	int j = 0;
	result += ".";
	while (j < binFractionPart.size() && result.size () < 112)
	{
		result += binFractionPart[j++];
	}
	while (result[0] == '0')
		result.erase(0,1);
	return result;
}
string QFloat::normalizeTheNumber(int& exponent)
{
	// Chuẩn hóa số dec sang dạng số chấm động //
	// Có dạng 1.X * 2 ^ E
	string binaryFormat = contertToFloatingPointFormat();

	string temp = binaryFormat;
	exponent = (binaryFormat.substr(0, binaryFormat.find("."))).size() - 1;
	if (exponent == -1)
	{
		int i = 1;
		while (temp[i++] == '0')
		{
			exponent--;
			
		}
	}

	string normalizedBinary = "";
	if (exponent >= 0)
	{
		// Số mũ dương //
		// Dời sang phải //
		for (int i = 1; i <= exponent; i++)
			normalizedBinary += binaryFormat[i];
		normalizedBinary += binaryFormat.substr(binaryFormat.find(".") + 1);
	}
	else 
	{
		// Số mũ âm //
		// Dời sang trái //
		binaryFormat.erase(0, 1);
		binaryFormat.erase(0, -exponent);
		normalizedBinary += binaryFormat;
	}
	
	while (normalizedBinary.size() < 112)
	{
		normalizedBinary += "0";
	}
	return normalizedBinary;
}
string QFloat::convertIntegalToBin()
{
	// Phần số nguyên 
	// Chuyển phần nguyên sang binary 
	string integerNum = this->number.substr(0, this->number.find("."));
	if (integerNum[0] == '-')
		integerNum.erase(0, 1);
	QInt integerPart(integerNum);

	return reduceZeroInBin(integerPart.convertDecToBin());
}
string QFloat::convertFractionalToBin()
{
	// Phần số thập phân
	// Chuyển phần số thập phân sang binary
	string num = this->number;
	int pointPosition = num.find(".");
	string floatingNum;
	if (pointPosition == -1)
		floatingNum = "0";
	else
		floatingNum = num.substr(num.find(".") + 1);
	string result;
	int count = 0;
	while (reduceZeroInBin(floatingNum) != "" && count < 112)
	{
		int	amountDigits = floatingNum.size();
		floatingNum = multipliedByTwo(floatingNum);
		floatingNum.insert(floatingNum.size() - amountDigits, ".");
		if (floatingNum[0] != '.')
		{
			result += "1";
		}
		else
		{
			result += "0";
		}

		floatingNum = floatingNum.substr(floatingNum.find(".") + 1);
		count++;

	}
	return result;
}
string QFloat::convertNumberToBin()
{
	// 1 bit cho Sign
	// 15 bits cho số mũ -> K = 2 ^ (14) - 1
	// 112 bits cho định trị

	bool sign = this->number[0] == '-';
	int exponent;


	string mantissa = normalizeTheNumber(exponent); // Định trị

	// Phần mũ //
	exponent += 16383; // E = E + K;
	string binaryOfExponent = QInt(to_string(exponent)).convertDecToBin();

	// Trường hợp dấu âm thì bị thiếu bit nên
	// thêm bit 0 ở đầu cho đủ 15 bits phần mũ 
	while (binaryOfExponent.size() < 15)
		binaryOfExponent.insert(0, "0");



	string result = to_string(sign); // Thêm dấu 

	result += binaryOfExponent + mantissa;
	return result;
}


void QFloat::storeDecIntoQFloat()
{
	string binary = convertNumberToBin();
	bool sign = binary[0] == '1';
	for (int i = 3; i > -1; i--)
	{
		for (int j = 31; j > -1; j--)
		{
			// Nếu là 1 thì set bit tại vị trí j, là 0 thì bỏ qua.
			if (binary[j + i * 32] == '1')
			{
				this->data[i] = (this->data[i] | (1 << (31 - j)));
			}
		}
	}
}

string QFloat::convertFractionalBinToDec(string bin)
{
	string result = "0";
	if (bin.find('1') == -1)
		return ".0";
	// Chuyển nhị phân của phần thập phân sang lại dec //
	while (bin[bin.size() - 1] == '0')
		bin.pop_back();
	
	
	for (int i = 0; i < bin.size(); i++)
	{
		string a = bin.substr(i, 1);
		if (a == "1")
			for (int j = 0; j < bin.size() - i - 1; j++)
			{
				a = this->multipliedByTwo(a);
			}
			result = sum(a, result);
	}
	
	for (int i = 0; i < bin.size(); i++)
	{
		result = this->dividedByTwo(result);
	}
	
	return result;
}

string QFloat::convertQFloatToDec()
{
	bool sign = (this->data[0] >> 31) & 1;
	
	int exponent = ((this->data[0] & 0x7fffffff) >> 16); // Phần mũ
	exponent -= 16383;
	cout << exponent << endl;
	string mantissa = ""; // Phần định trị

	for (int j = 15; j >=0; j--)
	{
		if (((this->data[0] >> j) & 1) == 1)
			mantissa += "1";
		else
			mantissa += "0";
	}

	for (int i = 1; i <= 3; i++)
	{
		for (int j = 31; j >= 0; j--)
			if (((this->data[i] >> j) & 1) == 1)
				mantissa += "1";
			else
				mantissa += "0";
	}
	


	if (exponent >= 0)
		mantissa.insert(0, "1");
	else
	{
		mantissa.insert(0, "1");
		for (int i = exponent + 1; i < 0; i++)
			mantissa.insert(0, "0");
	}
		

	string integalPart; // Phần số nguyên

	// Kiểm tra nếu phần mũ dương thì dịch trái, phần nguyên > 0//
	// Mũ âm thì phần nguyên == 0; //
	if (exponent >= 0)
	{
		integalPart = QInt::convertBinToDec(mantissa.substr(0, exponent + 1));
		mantissa = mantissa.substr(exponent + 1);
	}	
	else
		integalPart = "0";



	string fracionalPart = this->convertFractionalBinToDec(mantissa); // Phần số thập phân

	string result = integalPart + fracionalPart;
	
	if (sign)
		result.insert(0, "-");
	


	return result;
	

}
string QFloat::convertBinToDec(string& bin)
{

		
	bool sign = bin[0] == '1';

	int exponent = stoi(QInt::convertBinToDec(bin.substr(1, 15)));// Phần mũ
	exponent -= 16383;
	
	string mantissa = bin.substr(16); // Phần định trị


	if (exponent > 0)
		mantissa.insert(0, "1");
	else
	{
		mantissa.insert(0, "1");
		for (int i = exponent + 1; i < 0; i++)
			mantissa.insert(0, "0");
	}


	string integalPart; // Phần số nguyên

	// Kiểm tra nếu phần mũ dương thì dịch trái, phần nguyên > 0//
	// Mũ âm thì phần nguyên == 0; //
	if (exponent > 0)
	{
		integalPart = QInt::convertBinToDec(mantissa.substr(0, exponent + 1));
		mantissa = mantissa.substr(exponent + 1);
	}
	else
		integalPart = "0";



	string fracionalPart = QFloat().convertFractionalBinToDec(mantissa); // Phần số thập phân

	string result = integalPart + fracionalPart;

	if (sign)
		result.insert(0, "-");
	return result;
}
string QFloat::convertDecToBin(string &dec)
{
	QFloat num(dec);
	return num.convertNumberToBin();
}
