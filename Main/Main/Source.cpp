#include "FIle.h"

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

BigBit plusBit(BigBit& a,BigBit& b)
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

string convertBinToDec(BigBit a)
{
	// Source: https://stackoverflow.com/questions/8023414/how-to-convert-a-128-bit-integer-to-a-decimal-ascii-string-in-c
	// log10(x) = log2(x) / log2(10) ~= log2(x) / 3.322
	string s;
	for (int i = 0; i < 128 / 3 + 1 + 1; i++)
		s += '0';
	int i, j;
	int sign = a.data[0];
	if (sign == -1)
	{
		// Âm sang dương: bù 1 rồi bù 2 như dương sang âm //
		onesComplement(a);
		twosComplement(a);
	}
	for (i = 0; i < 128; i++)
	{
		int carry;
		carry = (a.data[0] >= 0x80000000);
		// Shift n[] left, doubling it
		a.data[0] = ((a.data[0] << 1)) + (a.data[1] >= 0x80000000);
		a.data[1] = ((a.data[1] << 1)) + (a.data[2] >= 0x80000000);
		a.data[2] = ((a.data[2] << 1)) + (a.data[3] >= 0x80000000);
		a.data[3] = ((a.data[3] << 1));


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

BigBit andBit(BigBit& a, BigBit& b)
{
	// return a & b
	BigBit result;
	initializeDefault(result);
	for (int i = 3; i >= 0; i--)
		result.data[i] = (a.data[i] & b.data[i]);
	

	return result;
}

BigBit orBit(BigBit& a, BigBit& b)
{
	// return a | b
	BigBit result;
	initializeDefault(result);
	for (int i = 3; i >= 0; i--)
		result.data[i] = (a.data[i] | b.data[i]);


	return result;
}

BigBit xorBit(BigBit& a, BigBit& b)
{
	// return a ^ b
	BigBit result;
	initializeDefault(result);
	for (int i = 3; i >= 0; i--)
		result.data[i] = (a.data[i] ^ b.data[i]);


	return result;
}

void notBit(BigBit& a)
{

	for (int i = 3; i >= 0; i--)
		a.data[i] = ~a.data[i];

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

BigBit minusBit(BigBit& a,BigBit& b)
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

void SHL(BigBit& a)
{
	a.data[0] = ((a.data[0] << 1)) + (a.data[1] >= 0x80000000);
	a.data[1] = ((a.data[1] << 1)) + (a.data[2] >= 0x80000000);
	a.data[2] = ((a.data[2] << 1)) + (a.data[3] >= 0x80000000);
	a.data[3] = ((a.data[3] << 1));
}
void SHR(BigBit& a)
{
	a.data[3] = ((a.data[3] >> 1) & 0x7FFFFFFF) + ((a.data[2] % 2) << 31);
	a.data[2] = ((a.data[2] >> 1) & 0x7FFFFFFF) + ((a.data[1] % 2) << 31);
	a.data[1] = ((a.data[1] >> 1) & 0x7FFFFFFF) + ((a.data[0] % 2) << 31);
	a.data[0] = ((a.data[0] >> 1));

}
void ROL(BigBit& a)
{
	// Rotate left //
	// Moving all bits to the left, MSB assigns to LSB
	bool LSB = a.data[0] & 0x8000000;
	SHL(a);
	a.data[3] = a.data[3] + LSB;
}
void ROR(BigBit& a)
{
	// Rotate right //
	// Moving all bits to the righ, LSB assigns to MSB
	bool MSB = a.data[3] & 1;
	SHR(a);
	if (MSB == 1)
		a.data[0] = a.data[3] ^ 0x8000000;
}

bool GT(BigBit& a, BigBit& b)
{
	// Greater than //

	BigBit result = minusBit(a, b);
	return (result.data[0] >= 0 && result.data[1] >= 0 && result.data[2] >= 0 && result.data[3] > 0);
}
bool GET(BigBit& a, BigBit& b)
{
	// Greater and equal than //

	BigBit result = minusBit(a, b);
	return (result.data[0] >= 0 && result.data[1] >= 0 && result.data[2] >= 0 && result.data[3] >= 0);
}
bool ST(BigBit& a, BigBit& b)
{
	// Smaller than //

	BigBit result = minusBit(a, b);
	return (result.data[0] < 0 && result.data[1] < 0 && result.data[2] < 0 && result.data[3] < 0);
}
bool SET(BigBit& a, BigBit& b)
{
	// Smaller than or equal //

	BigBit result = minusBit(a, b);
	return (result.data[0] <= 0 && result.data[1] <= 0 && result.data[2] <= 0 && result.data[3] <= 0);
}
bool Equal(BigBit& a, BigBit& b)
{
	BigBit result = minusBit(a, b);
	return (result.data[0] == 0 && result.data[1] == 0 && result.data[2] == 0 && result.data[3] == 0);
}
BigBit merge1(BigBit& a, BigBit& q)
{
	BigBit temp;
	initializeDefault(temp);
	int n1 = countAmountBit(a) - 1;
	int n2 = countAmountBit(q) - 1;

	temp = a;
	for (int i = 0; i < (n2 / 32) + 1; i++)
		for (int j = 0; j < 32; j ++)
			SHL(temp);

	temp = plusBit(temp, q);
	return temp;
}

BigBit join(BigBit& a, BigBit& q, int n)
{
	BigBit result;
	initializeDefault(result);
	result = a;
	for (int i = 0; i < n; i++)
		SHL(result);
	
	for (int i = 0; i < n; i++)
	{
		if (((q.data[3 - (i / 32)] >> (i % 32)) & 1) == 1)
			result.data[3 - (i / 32)] = (result.data[3 - (i / 32)] | (1 << (i % 32)));
	}
	
	return result;
}
void split(BigBit temp, BigBit& a, BigBit& q, int n)
{
	
	int k = (n / 32) + 1;
	BigBit c = temp;
	initializeDefault(a);
	initializeDefault(q);
	for (int i = 0; i < n; i++)
	{
		if ( ((temp.data[3 - (i / 32)] >> (i % 32)) & 1 ) == 1)
			q.data[3 - (i / 32)] = (q.data[3 - (i / 32)] | (1 << (i % 32)));
	}
	for (int i = 0; i < n; i++)
	{
		SHR(temp);
	}
	a = temp;
}

void ShiftRight(BigBit& a, BigBit& q, int& lastBit, int n)
{
	lastBit = ((q.data[3]) & 1);
	BigBit temp = join(a, q, n);
	SHR(temp);
	split(temp, a, q, n);

}
BigBit multiplyBit(BigBit q,BigBit m)
{
	// Thuật toán nhân cải tiến //
	BigBit a;
	initializeDefault(a);
	int lastBit = 0;
	int k = countAmountBit(q);

	if (k < 4)
		k = 4;
	else
		k = int(k / 4) * 4 + (float(k / 4.0) > 0.0) * 4;

	int n = k;
	while (k > 0)
	{
		if ( ((q.data[3]) & 1) == 1 && lastBit == 0)	
		{
			a = minusBit(a, m);
		}
		else if (((q.data[3]) & 1) == 0 && lastBit == 1)
		{
			a = plusBit(a, m);
	
		}
		ShiftRight(a, q, lastBit, n);
		k--;
	}

	return join(a, q, n);
}

BigBit divideBit(BigBit q, BigBit m)
{
	BigBit a;
	initializeDefault(a);
	int lastBit = 0;
	int k = countAmountBit(q); // Số bit

	if (k < 4)
		k = 4;
	else
		k = int(k / 4) * 4 + (float(k / 4.0) > 0.0) * 4;
	int sign = 0; // Dấu 
	int n = k; 
	if (q.data[0] == -1)
	{
		sign ++;
		onesComplement(q);
		twosComplement(q);
	}
	if (m.data[0] == -1)
	{
		sign ++;
		onesComplement(m);
		twosComplement(m);
	}
	while (k > 0)
	{
		BigBit joining = join(a, q, n);
		SHL(joining);
		split(joining, a, q, n);
		BigBit temp = minusBit(a, m);
		if (temp.data[0] == -1)
		{
			// Set bit 0 của q thành 0
			SHR(q);
			SHL(q);
			// q.data[3] = (q.data & (-2)); 
		}
		else
		{
			// Set bit 0 của q thành 1
			a = temp;
			q.data[3] = (q.data[3] | 1);
		}
		k--;
	}
	if (sign % 2 != 0)
	{
		onesComplement(q);
		twosComplement(q);
	}
	return q;
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
string dividedByTwo(string a)
{
	// Phép chia thực hiện như người chia ngoài nháp :D //
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
		{
			temp += ".";
		}
	
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
string sum(string a, string b)
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
int main(int argc, char ** argv)
{
	// bit đầu lưu dấu
	// Bit 0 là bit bên phải nhất.
	// 4294967296 = 2 ^ 32
	// 18446744073709551616 = 2 ^ 64
	// 170141183460469231731687303715884105728 = 2 ^ 127
	// 340282366920938463463374607431768211456 = 2 ^ 128
	
	// argv[1] là kiểu QInt hoặc QFloat
	// argv[2] là file input
	// argv[3] là file output
	
	if (argc < 1)
		return 0;
	
	/*for (int i = 1; i <= argc; i++)
		cout << argv[i] << endl;*/
	
	File a(atoi(argv[1]), string(argv[2]), string(argv[3]));
	a.readFile();

	cout << endl;
	system("pause");
}		  