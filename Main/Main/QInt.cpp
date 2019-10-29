#include "QInt.h"


QInt::QInt()
{
	for (int i = 3; i >= 0; i--)
		data[i] = 0;
	number = "0";
}
QInt::QInt(string a) 
{
	for (int i = 3; i >= 0; i--)
		this->data[i] = 0;
	this->number = a;
	this->storeToQInt();
	
}
QInt::QInt(QInt const& p)
{
	for (int i = 3; i >= 0; i--)
		this->data[i] = p.data[i];
	this->number = p.number;
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
	return temp;
}


void QInt::printData() 
{
	for (int i = 3; i >= 0; i--)
		cout << this->data[i] << endl;
	cout << endl;
}
void QInt::print()
{
	cout << this->convertQIntToDec() << endl;
}


void QInt::storeToQInt() 
{
	int sign = this->number[0] == '-';
	string a = this->convertToStoreData();
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
		this->executeTwosComplenment();
	}

}
void QInt::executeTwosComplenment()
{
	// Bù 1 và Bù 2 //
	// Chuyển âm sang dương và ngược lại //
	*this = ~(*this);
	*this = QInt("1") + (*this);
}
QInt QInt::join(QInt& a, QInt& q, int n) {
	QInt result(a);
	for (int i = 0; i < n; i++)
		result = result << 1;

	for (int i = 0; i < n; i++)
	{
		if (((q.data[3 - (i / 32)] >> (i % 32)) & 1) == 1)
			result.data[3 - (i / 32)] = (result.data[3 - (i / 32)] | (1 << (i % 32)));
	}

	return result;
}
void QInt::split(QInt& join,QInt&a, QInt& q, int n)
{
	QInt c(join);
	q = QInt();
	a = QInt();
	for (int i = 0; i < n; i++)
	{
		if (((join.data[3 - (i / 32)] >> (i % 32)) & 1) == 1)
			q.data[3 - (i / 32)] = (q.data[3 - (i / 32)] | (1 << (i % 32)));
	}
	for (int i = 0; i < n; i++)
	{
		join = join >> 1;
	}
	a = join;
}
void QInt::ShiftRight(QInt &a, QInt& q, int& lastBit, int n)
{
	lastBit = ((q.data[3]) & 1);
	QInt temp = join(a, q, n);
	temp = temp >> 1;
	split(temp, a, q, n);
}
int QInt::countAmountBits()
{
	int result = 0;
	int index = 0;
	QInt a(*this);
	if (a.data[0] == -1)
	{
		a.executeTwosComplenment();
	}
	for (int i = 0; i < 4 && result == 0; i++)
	{
		for (int j = 0; j < 32; j++)
		{
			if (((a.data[i] >> (31 - j)) & 1) == 0)
				index++;
			else
			{
				result = 1;
				break;
			}
		}
	}
	return (128 - index);
}


//		Converting		//
QInt QInt::convertToQInt(string a)
{
	while (a.size() < 128)
	{
		a.insert(0, "0");
	}
	QInt result;
	int sign = (a[0] == '-');
	// Chạy từ vị trí 3 xuống 0 trong mảng data như một dãy nhị//
	for (int i = 3; i > -1; i--)
	{
		for (int j = 31; j > -1; j--)
		{
			// Nếu là 1 thì set bit tại vị trí j, là 0 thì bỏ qua.
			if (a[j + i * 32] == '1')
			{
				result.data[i] = (result.data[i] | (1 << (31 - j)));
			}
		}
	}
	if (sign == 1)
	{
		result.executeTwosComplenment();
	}
	return result;
}
string QInt::convertQIntToDec()
{
	string s;
	for (int i = 0; i < 128 / 3 + 1 + 1; i++)
		s += '0';
	int i, j;
	QInt a = *this;
	int sign = a.data[0];
	if (sign == -1)
	{
		// Âm sang dương: bù 1 rồi bù 2 như dương sang âm //
		a.executeTwosComplenment();
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
	this->number = s;
	return s;
}
string QInt::convertToStoreData()
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
string QInt::convertDecToBin()
{
	// Convert QInt into Binary //
	string result;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 32; j++)
			result += to_string((this->data[i] >> (31 - j)) & 1);
	}
	return result;
}
string QInt::convertDecToHex(string dec)
{
	QInt result(dec);
	return result.convertBinToHex();
}
string QInt::convertBinToHex()
{
	string converting[16] = { "0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F" };

	string result;
	QInt a(*this);
	int k = this->countAmountBits();
	if (k < 4)
		k = 4;
	else
		k = int(k / 4) * 4 + (float(k / 4.0) > 0.0) * 4;
	int i = 128;
	while (i > 0)
	{
		QInt d = QInt("15") & a;
		result += converting[d.data[3]] ;
		a = a >> 4;
		i -= 4;
	}
	reverse(result.begin(), result.end());
	return result;
}
string QInt::convertBinToDec(string bin)
{
	string s;
	for (int i = 0; i < 128 / 3 + 1 + 1; i++)
		s += '0';
	int i, j;
	QInt a;
	a = convertToQInt(bin);
	int sign = a.data[0];
	if (sign == -1)
	{
		// Âm sang dương: bù 1 rồi bù 2 như dương sang âm //
		a.executeTwosComplenment();
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
string QInt::convertHexToBin(string hex)
{
	while (hex.size() < 32)
		hex.insert(0, "0");
	string binaryResult = "";

	for (int i = 0; i < 32; i++)
	{
		string a;
		if (hex[i] > '9')
		{
			a = QInt(to_string(int(hex[i]) % 65 + 10)).convertDecToBin();

		}
		else
		{
			a = QInt(hex.substr(i, 1)).convertDecToBin();
		}
		
		binaryResult += a.substr(a.size() - 4);
	}
	return binaryResult;
}
string QInt::convertHexToDec(string hex)
{
	string binaryResult = convertHexToBin(hex);
	return convertBinToDec(binaryResult);
}


//		Operator		//
QInt QInt::operator+(QInt& const b)
{
	int nho = 0;
	QInt c;
	for (int i = 3; i >= 0; i--)
	{
		// ( X >> (n - 1 - i) ) & 1 : đọc bit 
		// X = X | (1 << (n - 1 - i )): set bit
		for (int j = 31; j >= 0; j--)
		{
			int t = ((this->data[i] >> (31 - j)) & 1) + ((b.data[i] >> (31 - j)) & 1) + nho;
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
	c.number = c.convertQIntToDec();
	return c;
}
QInt QInt::operator- (QInt& const b)
{
	QInt result;
	result = b;
	result.executeTwosComplenment();

	return (result+(*this));
}
QInt QInt::operator* (QInt& const q) {
	// Thuật toán nhân cải tiến //
	// result = (*this) * q;
	QInt a;
	int lastBit = 0;
	int k = q.countAmountBits();

	if (k < 4)
		k = 4;
	else
		k = int(k / 4) * 4 + (float(k / 4.0) > 0.0) * 4;

	int n = k;
	while (k > 0)
	{
		if (((q.data[3]) & 1) == 1 && lastBit == 0)
		{
			a = a - *this;
		}
		else if (((q.data[3]) & 1) == 0 && lastBit == 1)
		{
			a = a + *this;

		}
		ShiftRight(a, q, lastBit, n);
		k--;
	}

	return join(a, q, n);
}
QInt QInt::operator/ (QInt& const m) {
	// (*this) / m
	QInt a;
	QInt q(*this);
	int lastBit = 0;
	int k = q.countAmountBits(); // Số bit

	if (k <= 4)
		k = 4;
	else
		k = int(k / 4) * 4 + (float(k / 4.0) > 0.0) * 4;
	int sign = 0; // Dấu 
	int n = k;
	if (q.data[0] == -1)
	{
		sign++;
		q.executeTwosComplenment();
	}
	if (m.data[0] == -1)
	{
		sign++;
		m.executeTwosComplenment();
	}
	while (k > 0)
	{
		QInt joining = join(a, q, n);
		joining = joining << 1;
		split(joining, a, q, n);
		QInt temp = a - m;
		if (temp.data[0] == -1)
		{
			// Set bit 0 của q thành 0
			q.data[3] = (q.data[3] & (-2)); 
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
		q.executeTwosComplenment();
	}

	return q;
}

QInt QInt::operator& (QInt& const b)
{
	QInt result(*this);
	for (int i = 3; i >= 0; i--)
		result.data[i] = (this->data[i] & b.data[i]);
	result.number = result.convertQIntToDec();
	return result;
}
QInt QInt::operator| (QInt& const b) {
	QInt result(*this);

	for (int i = 3; i >= 0; i--)
		result.data[i] = (this->data[i] | b.data[i]);

	result.number = result.convertQIntToDec();
	return result;
}
QInt QInt::operator^ (QInt& const b) {
	// return a ^ b
	QInt result(*this);
	for (int i = 3; i >= 0; i--)
		result.data[i] = (this->data[i] ^ b.data[i]);
	result.number = result.convertQIntToDec();
	return result;
}
QInt QInt::operator~ () {
	// Not operator //
	QInt result(*this);
	for (int i = 3; i >= 0; i--)
		result.data[i] = ~this->data[i];
	result.number = result.convertQIntToDec();
	return result;
}

QInt QInt::operator>> (int n)
{
	// Shift right //
	QInt a = (*this);
	for (int i = 0; i < n; i++)
	{
		a.data[3] = ((a.data[3] >> 1) & 0x7FFFFFFF) + ((a.data[2] % 2) << 31);
		a.data[2] = ((a.data[2] >> 1) & 0x7FFFFFFF) + ((a.data[1] % 2) << 31);
		a.data[1] = ((a.data[1] >> 1) & 0x7FFFFFFF) + ((a.data[0] % 2) << 31);
		a.data[0] = ((a.data[0] >> 1));
	}
	return a;
}
QInt QInt::operator<< (int n)
{
	// Shift left //
	QInt a = (*this);
	for (int i = 0; i < n; i++)
	{
		a.data[0] = ((a.data[0] << 1)) + (a.data[1] >= 0x80000000);
		a.data[1] = ((a.data[1] << 1)) + (a.data[2] >= 0x80000000);
		a.data[2] = ((a.data[2] << 1)) + (a.data[3] >= 0x80000000);
		a.data[3] = ((a.data[3] << 1));
	}
	return a;
}
QInt QInt::ROR(int n)
{
	// Rotate right //
	// Moving all bits to the righ, LSB assigns to MSB

	QInt a(*this);
	for (int i = 0; i < n; i++)
	{
		bool MSB = a.data[3] & 1;
		a = a >> 1;
		if (MSB == 1)
			a.data[0] = a.data[3] ^ 0x8000000;

	}

	return a;
}
QInt QInt::ROL(int n)
{
	// Rotate left //
	// Moving all bits to the left, MSB assigns to LSB

	QInt a(*this);
	for (int i = 0; i < n; i++)
	{
		bool LSB = a.data[0] & 0x8000000;
		a = a >> 1;
		a.data[3] = a.data[3] + LSB;
	}
	
	return a;
}

bool QInt::operator> (QInt& const b)
{
	// Greater than //

	QInt result = (*this) - b;
	return (result.data[0] >= 0 && result.data[1] >= 0 && result.data[2] >= 0 && result.data[3] > 0);

}
bool QInt::operator< (QInt& const b) {
	// Smaller than //

	QInt result = (*this) - b;
	return (result.data[0] < 0 && result.data[1] < 0 && result.data[2] < 0 && result.data[3] < 0);

}
bool QInt::operator>= (QInt& const b) {
	QInt result = (*this) - b;
	return (result.data[0] >= 0 && result.data[1] >= 0 && result.data[2] >= 0 && result.data[3] >= 0);


}
bool QInt::operator<= (QInt& const b) {
	// Smaller than or equal //

	QInt result = (*this) - b;
	return (result.data[0] <= 0 && result.data[1] <= 0 && result.data[2] <= 0 && result.data[3] <= 0);

}
bool QInt::operator== (QInt& const b) {
	QInt result = (*this) - b;
	return (result.data[0] == 0 && result.data[1] == 0 && result.data[2] == 0 && result.data[3] == 0);

}
