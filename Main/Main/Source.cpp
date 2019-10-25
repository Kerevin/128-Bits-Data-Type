#include "QInt.h"

struct BigBit
{
	int data[4];
};

void initializeDefault(BigBit& a)
{
	for (int i = 0; i < 4; i++)
		a.data[i] = 0;
}

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

BigBit plusBit(const BigBit& a, const BigBit& b)
{
	int nho = 0;
	BigBit c;
	for (int i = 0; i < 4; i++)
		c.data[i] = 0;
	for (int i = 3; i >= 0; i--)
	{
		// ( X >> (n - 1 - i) ) & 1 : đọc bit 
		// X = X | (1 << (n - 1 - i )): set bit
		for (int j = 31; j >= 0; j--)
		{
			int t = ((a.data[i] >> (31 - j)) & 1) + ((b.data[i] >> (31 - j)) & 1) + nho;
			if (t == 3)
			{
				c.data[i] = (c.data[i] | (1 << (31 - j)));
				nho = 1;
			}
			else if (t == 2)
			{
				nho = 1;
			}

			else
			{
				if (t == 1)
					c.data[i] = (c.data[i] | (1 << (31 - j)));
				nho = 0;
			}
		}
	}
	return c;
}


void onesComplement(BigBit& a)
{
	// Bù 1 //
	for (int i = 3; i >= 0; i--)
	{
		for (int j = 31; j >= 0; j--)
		{
			a.data[i] = (a.data[i] ^ (1 << (31 - j)));
		}
	}
}

void twosComplement(BigBit& a)
{
	// Bù 2 // 
	BigBit b;
	initializeDefault(b);
	b.data[3] = 1;
	a = plusBit(a, b);
}

string convertDecToBin(string a)
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

BigBit minusBit(const BigBit& a, const BigBit& b)
{
	BigBit temp;
	temp = b;
	onesComplement(temp);
	twosComplement(temp);
	return plusBit(a, temp);
}
int countAmountBit(BigBit a)
{
	int result = 0;
	int index = 0;
	if (a.data[0] == -1)
	{
		onesComplement(a);
		twosComplement(a);
	}
	for (int i = 0; i < 4 && result == 0; i++)
	{
		for (int j = 0; j < 32; j++)
		{ 		
			if ( ((a.data[i] >> (31 - j)) & 1) == 0)
				index ++;
			else
			{
				result = 1;
				break;	
			}
		}
	}
	return (128 - index);
}
BigBit merge(BigBit& a, BigBit& q)
{
	BigBit temp;
	initializeDefault(temp);
	int n1 = countAmountBit(a);
	int n2 = countAmountBit(q);
	int k = 31;
	int i = 3;
	for (int j = n1; j > 0; j--)
	{
		if ( ((a.data[3 - (j / 32)] >> (n1 - j)) & 1) == 1)
		{
			temp.data[i] = (temp.data[i] | (1 << (31 - k)));
		}
			
		k--;
		if (k == -1)
		{
			k = 31;
			i--;
		}
	}
	for (int j = n2; j > 0; j--)
	{
		if ( ((q.data[3 - (j / 32)] >> (n2 - j)) & 1) == 1)
			temp.data[i] = (temp.data[i] | (1 << (31 - k)));
		k--;
		if (k == -1)
		{
			k = 31;
			i--;
		}
	}

	
	return temp;
}

void ShiftRight(BigBit& a, BigBit& q, int& lastBit)
{
	BigBit temp;
	lastBit = ((a.data[3] >> (31)) & 1);
	initializeDefault(temp);
}
BigBit multiplyBit(BigBit m,BigBit q)
{
	// Thuật toán nhân cải tiến //
	BigBit a;
	initializeDefault(a);
	int lastBit = 0;
	int k = 127; 
	while (k >= 0)
	{
		if ( ((q.data[3] >> (0)) & 1) == 1 && lastBit == 0)
			a = minusBit(a, q);
		else if ( ((q.data[3] >> (0)) & 1) == 0 && lastBit == 1)
			a = plusBit(a, q);
		ShiftRight(a, q, lastBit);
		k--;
	}
	return a;
}


BigBit storeData(string a)
{
	BigBit result;
	int soam = a[0] == '-';
	a = convertDecToBin(a);
	// Khởi tạo với các phần tử đều bằng 0 
	// Ở cấp độ bin đều là 0000
	initializeDefault(result);
	
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
		onesComplement(result);
		// bù 2
		twosComplement(result);
	}
	return result;
}


string convertBinToDec(BigBit a)
{
	// Source: https://stackoverflow.com/questions/8023414/how-to-convert-a-128-bit-integer-to-a-decimal-ascii-string-in-c
	// log10(x) = log2(x) / log2(10) ~= log2(x) / 3.322
	string s;
	for (int i = 0; i < 128 /3 + 1 + 1 ; i++)
		s+= '0';
	int i, j;
	int sign = a.data[0];
	if (sign == -1)
	{
		// Âm sang dương: bù 1 rồi bù 2 như dương sang âm //
		BigBit temp;
		onesComplement(a);
		twosComplement(a);
	}
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
	if (sign == -1)
		s.insert(0, "-");
	if (s.size() == 0)
		s.push_back('0');
	return s;
}



int main()
{
	// bit đầu lưu dấu
	// 4294967296 = 2 ^ 32
	// 18446744073709551616 = 2 ^ 64
	// 170141183460469231731687303715884105728 = 2 ^ 127

	// 340282366920938463463374607431768211456 = 2 ^ 128
	
	string a = "3";
	string a1 = "2"; 
	BigBit c = storeData(a);
	BigBit c1 = storeData(a1);
	printBigBit(merge(c, c1));
	cout << endl;
	//
	//cout << convertBinToDec(c) << endl;
	//printBigBit(c1);
	//printBigBit(plusBit(c, c1));
	cout << a << " - (" << a1 << ") = ";
	cout << convertBinToDec(minusBit(c, c1)) << endl;
	
	system("pause");
}   