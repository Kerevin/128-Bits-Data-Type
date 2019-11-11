#pragma once
#include "QFloat.h"
#include <fstream>
#include <vector>
class File
{
private:
	ifstream readData;
	ofstream writeData;
	int type;

public:
	File()
	{
		this->type = 0;
	}
	File(int type, string fileInput, string fileOutput)
	{
		
		this->type = type;
		readData.open(fileInput, ios::in);
		writeData.open(fileOutput, ios::out);
	
	}
	~File()
	{
		writeData.close();
		readData.close();
	}


	void convert(vector <string>& s)
	{
		// Chuyển đổi từ các hệ với nhau //
		string result;
		if (this->type == 1)		//type = 1 thì chuyển sang QInt
		{
		
			// Chuyển hệ 2 sang hệ X 
			if (s[0] == "2")
			{
				if (s[1] == "10")
					result = QInt::convertBinToDec(s[2]);
				else
					result = QInt::convertBinToHex(s[2]);
			}
			// Chuyển hệ 10 sang hệ X
			else if (s[0] == "10")
			{
				if (s[1] == "2")
					result = QInt::convertDecToBin(s[2]);
				else
					result = QInt::convertDecToHex(s[2]);
			}
			// Chuyển hệ 16 sang hệ X
			else
			{
				if (s[0] == "2")
					result = QInt::convertHexToBin(s[2]);
				else
					result = QInt::convertHexToDec(s[2]);
			}
		}
		else // type = 2 thì chuyển đổi QFloat
		{

			// Chuyển hệ 2 sang hệ X 
			if (s[0] == "2")
			{
				if (s[1] == "10")
					result = QFloat::convertBinToDec(s[2]);
			}
				// Chuyển hệ 10 sang hệ X
			else if (s[0] == "10")
			{
				if (s[1] == "2")
					result = QFloat::convertDecToBin(s[2]);

			}
			
		}
		writeFile(result);
	}

	void calculate(vector <string>& s)
	{
		// Phần tính toán của QInt //
		QInt result;
		QInt *a, *b;
		int comparision = -1;
		if (s[0] == "2")
		{
			// Số scan vào là nhị phân //
			a = new QInt(QInt::convertBinToQInt(s[1]));
			b = new QInt(QInt::convertBinToQInt(s[3]));
	
		}
		else if (s[0] == "16")
		{
			// Số scan vào là thập lục phân //
			a = new QInt (QInt::convertHexToDec(s[1]));
			b = new QInt (QInt::convertHexToDec(s[3]));
		}
		else
		{
			// Số scan vào là thập phân //
			a = new QInt((s[1]));
			b = new QInt((s[3]));
		}
		switch (s[2][0])
		{
		case '+':
			result = (*a) + (*b);
			break;
		case '-':
			result = (*a) - (*b);
			break;
		case '*':
			result = (*a) * (*b);
			break;
		case '/':
			result = (*a) / (*b);
			break;
		case '>':
		{
			if (s[2].size() > 1)
			{
				if (s[2][1] == '>')
					result = (*a) >> stoi(s[3]);
				else
					comparision = (*a) >= (*b);
			}
			
			else	
				comparision = (*a) > (*b);
			break;
		}
		case '<':
		{
			if (s[2].size() > 1)
			{
				if (s[2][1] == '<')
					result = (*a) << stoi(s[3]);
				else
					comparision = (*a) <= (*b);
			}

			else
				comparision = (*a) < (*b);
			break;
		}
		case '=':
		{
			if (s[2][1] == '=')
				comparision = (*a) == (*b);
			break;
		}
		case '&':
		{
			result = (*a) & (*b);
			break;
		}
		case '|':
		{
			result = (*a) | (*b);
			break;
		}
		case '^':
		{
			result = (*a) ^ (*b);
			break;
		}
		case '~':
		{
			result = ~(*a);
			break;
		}
		default:
			cout << "Error... No operator is suitable" << endl;
			break;
		}
	
	
		if (comparision != -1)
		{
			if (comparision == 0)
				writeFile("False");
			else
				writeFile("True");
		}
		else
		{
			if (s[0] == "2")
				writeFile(result.convertDecToBin());
			else if (s[0] == "10")
				writeFile(result.convertQIntToDec());
			else
				writeFile(result.convertBinToHex());
		}
		delete a, b;
	}

	void preProcess(vector <string> s)
	{
		// Tiền xử lý //
		// Xác định chức năng thực hiện //
		// Chuyển đổi hoặc tính toán //
		if (s.size() > 1)
			if (isdigit(s[2][0]) || (s[2][0] == '-' && isdigit(s[2][1])) )
			{
				this->convert(s);
			}
			else if (this->type == 1)
			{
				this->calculate(s);
			}
	}

	void printString(vector <string> s)
	{
		for (int i = 0; i < s.size(); i++)
			cout << s[i] << endl;
		cout << endl;
	}


	vector <string> split(string s)
	{
		// Tách một chuỗi từ các dòng trong file input để xử lý //

		vector <string> consequence;
		int pre = 0, pos = 0;
		while (pos != -1)
		{
			pos = s.find(" ", pos + 1);
			consequence.push_back(s.substr(pre, pos - pre));
			pre = pos + 1;
		}
	

		return consequence;
	}


	void readFile()
	{
		// Đọc file từ file input //
		if (readData)
		{
			do
			{
				string s;
				getline(readData, s);
				if (s.size() > 0)
					this->preProcess(split(s));

			} while (!readData.eof());
		}
			
		else
			cout << "Couldn't open file..." << endl;

		cout << "Finished! " << endl;
	}

	void writeFile(string s)
	{
		writeData << s << endl;
	}

};