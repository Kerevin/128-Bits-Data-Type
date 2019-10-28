#include "QInt.h"


QInt::QInt()
{
	for (int i = 0; i < 4; i++)
		data[i] = 0;
	number = "";
}
QInt::QInt(string number) 
{
	for (int i = 0; i < 4; i++)
		data[i] = 0;
	this->number = number;
	this->convertDecToBin();
}
QInt::~QInt() 
{

}


string QInt::dividedByTwo(string a)
{
	// Phép chia thực hiện như người chia ngoài nháp :D //
	string temp = "";
	int sodu = 0;
	for (int i = 0; i < a.length(); i++)
	{
		int num = stoi(a.substr(i, 1));
		temp += to_string((sodu * 10 + num) / 2);
		sodu = (num % 2 != 0);
	}
	return a;
}
void QInt::printData() 
{

}
void QInt::storeData() 
{
	int sign = this->number[0] == '-';
	string a = this->convertDecToBin();
	// Khởi tạo với các phần tử đều bằng 0 
	// Ở cấp độ bin đều là 0000

	// Chạy từ vị trí 3 xuống 0 trong mảng data như một dãy nhị//
	for (int i = 3; i > -1; i--)
	{
		for (int j = 31; j > -1; j--)
		{
			// Nếu là 1 thì set bit tại vị trí j, là 0 thì bỏ qua.
			if (a[j + i * 32] == '1')
			{
				this->data[i] = (this->data[i] | (1 << (31 - j)));
			}
		}
	}
	if (sign == 1)
	{
		// bù 1
		onesComplement(result);
		// bù 2
		twosComplement(result);
	}

}


string QInt::convertDecToBin() 
{
	string a = this->number;
	string basekey = "";
	string result = "";

	// Kiểm tra xem có phải số âm hay không //
	int soam = (a[0] == '-');

	// Khi a chia hết thì sẽ còn một dãy 0 nên lấy mảng basekey để làm base key  //
	for (int i = 0; i < a.length() - soam; i++)
		basekey += "0";

	// Khởi tạo với 128 số 0 để phù hợp với 128 bits
	for (int i = 0; i < 128; i++)
		result += "0";

	int index = 127; // Chỉ số của string result chạy từ vị trí 127 xuống 0

	// Chuyển dec thành bin, lưu vào result
	if (soam == 0)
	{
		while (basekey != a)
		{

			if (stoi(a.substr(a.length() - 1, 1)) % 2 == 0)
				result[index--] = '0';
			else
				result[index--] = '1';
			a = dividedByTwo(a);
		}
	}
	else
	{
		a = a.substr(1);
		while (basekey != a)
		{
			if (stoi(a.substr(a.length() - 1, 1)) % 2 == 0)
				result[index--] = '0';
			else
				result[index--] = '1';
			a = dividedByTwo(a);

		}
	}

	return  result;
}
void QInt::convertBinToDec() 
{

}

QInt QInt::operator+(const QInt& b)
{
	return QInt();
}
