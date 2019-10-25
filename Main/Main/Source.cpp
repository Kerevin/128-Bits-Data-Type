#include <iostream>
#include <string>
#include <cstring>
#include <math.h>

using namespace std;
struct BigBit
{
	int data[4];
};

void printBigBit(BigBit a)
{

	for (int i = 3; i >= 0; i--)
	{
		cout << a.data[i] << endl;
	}
	cout << endl;
}

string divideByTwo(string a)
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
	return temp;
}

string multiplyByTwo(string a)
{
	string result = "";
	int sodu = 0;
	for (int i = a.length() - 1; i >= 0; i--)
	{ 
		int number = stoi(a.substr(i, 1)) * 2 + sodu;
		sodu = int(number / 10);
		result.insert(0,to_string(number % 10));
	}
	if (sodu != 0)
		result.insert(0, to_string(sodu));
	return result;
}

string DecToBin(string a)
{
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
			a = divideByTwo(a);
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
			a = divideByTwo(a);
			
		}
	}


	return  result;
}

BigBit storeData(string a)
{
	BigBit result;
	int soam = a[0] == '-';
	//a = DecToBin(a);
	// Khởi tạo với các phần tử đều bằng 0 
	// Ở cấp độ bin đều là 0000
	for (int i = 0; i < 4; i++)
		result.data[i] = 0;
	
	// Chạy từ vị trí 3 xuống 0 trong mảng data như một dãy nhị//
	for (int i = 3; i > -1; i--)
	{
		for (int j = 31; j > -1; j--)
		{
			// Nếu là 1 thì set bit tại vị trí j, là 0 thì bỏ qua.
			if (a[j + i * 32] == '1')
			{
				result.data[i] = (result.data[i] | ( 1 << (31 - j) ) );
			}
		}
	}
	if (soam == 1)
	{
		// bù 1
		// 
	}
	return result;
}

string BinToDec(BigBit a)
{
	string data = "";
	int b;
	return to_string(a.data[3] + a.data[2] * (pow(2, 32)) + a.data[1] * (pow(2, 64)) + a.data[0] * (pow(2, 128)));
}
int Ghidaybit(BigBit a)
{
	// chuyển bin sang dec 
	string x = "0";
	for (int j  = 3; j >= 0; j--)
	{
	
		for (int i = 0; i < 32 * (4 - j); i++)
		{ 
			x = to_string((stoi(x) | (a.data[j] << (32 * (4 - j) - i))));
			cout << x;
		}
		cout << endl;
	}
	return 1;
	//return x;
}
void DocDayBit(int x, int a[32])
{
	// chuyen dec sang bin
	for (int i = 0; i < 32; i++)
		a[i] = ((x >> (32 - i)) & 1);
}

string Bin128ToDec(BigBit a)
{
	// Source: https://stackoverflow.com/questions/8023414/how-to-convert-a-128-bit-integer-to-a-decimal-ascii-string-in-c
	// log10(x) = log2(x) / log2(10) ~= log2(x) / 3.322
	string s;
	for (int i = 0; i < 128 /3 + 1 + 1 ; i++)
		s+= '0';
	int i, j;

	for (i = 0; i < 128; i++)
	{
		int carry;
		carry = (a.data[0] >= 0x80000000);
		// Shift n[] left, doubling it
		a.data[0] = ((a.data[0] << 1) & 0xFFFFFFFF) + (a.data[1] >= 0x80000000);
		a.data[1] = ((a.data[1] << 1) & 0xFFFFFFFF) + (a.data[2] >= 0x80000000);
		a.data[2] = ((a.data[2] << 1) & 0xFFFFFFFF) + (a.data[3] >= 0x80000000);
		a.data[3] = ((a.data[3] << 1) & 0xFFFFFFFF);
		

		// Add s[] to itself in decimal, doubling it
		for (j = s.size() - 2; j >= 0; j--)
		{
			s[j] += s[j] - '0' + carry;

			carry = (s[j] > '9');

			if (carry)
			{
				s[j] -= 10;
			}
		}

	}
	s.pop_back();
	while (s[0] == '0')
	{
		s.erase(0, 1);
	}
	return s;
}


void plusBit(BigBit a, BigBit b)
{
	int nho = 0;
	int x = 0;
	BigBit c;
	string temp = "";
	for (int i = 3; i >= 0; i--)
	{
		// ( X >> (n - 1 - i) ) & 1 : đọc bit 
		for (int j = 31; j >= 0; j--)
		{
			int t = ((a.data[i] >> (31 - j)) & 1) + ((b.data[i] >> (31 - j)) & 1) + nho;
			if (t == 3)
			{
				//c.data[i] = 1;
				temp.insert(0, "1");
				nho = 1;
			}
				
			if (t == 2)
			{
				//c.data[i] = 0;
				temp.insert(0, "0");
				nho = 1;
			}
				
			if (t <= 1)
			{
				//c.data[i] = t;
				temp.insert(0, to_string(t));
				nho = 0;
			}				
		}
	}
	c = storeData(temp);
	printBigBit(c);
}
int main()
{
	// 4294967296 = 2 ^ 32
	// 18446744073709551616 = 2 ^ 64
	// 340282366920938463463374607431768211456 = 2 ^ 128
	string a = "2";
	string a1 = "3";
	string b = DecToBin(a);
	BigBit c = storeData(b);
	BigBit c1 = storeData(DecToBin(a1));
	printBigBit(c);
	printBigBit(c1);
	plusBit(c, c1);

	system("pause");
}  