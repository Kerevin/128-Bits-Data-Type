#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
struct BigBit
{
	int data[4];
};
string divideByTwo(string a)
{
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
string DecToBin(string a)
{
	string b = "";
	string c = "";
	for (int i = 0; i < a.length(); i++)
		b += "0";
	for (int i = 0; i < 128; i++)
		c += "0";
	int k = 127;
	while (b != a)
	{

		if (stoi(a.substr(a.length() - 1, 1)) % 2 == 0)
			c[k--] = '0';
		else
			c[k--] = '1';
		a = divideByTwo(a);
	}
	//reverse(c.begin(), c.end());

	return  c;
}

BigBit storeData(string a)
{
	BigBit temp;
	for (int i = 0; i < 4; i++)
		temp.data[i] = 0;
	
	for (int i = 3; i > -1; i--)
	{
		for (int j = 31; j > -1; j--)
		{
			if (a[j + i * 32] == '1')
			{
				temp.data[i] =( temp.data[i] | (1 << (31 - j)) );
			}
		}
	}
	return temp;
}
int main()
{
	string a = "18446744073709551616";
	
	
	string b = DecToBin(a);
	BigBit c = storeData(b);
	for (int i = 3; i >= 0; i--)
	{
		cout << c.data[i] << endl;
	}

	system("pause");
}