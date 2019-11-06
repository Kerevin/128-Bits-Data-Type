#include"xuLyChuoi.h"

string convertStringToChar(string a)
{
    int temp = stoi(a);
    char temp_c = temp;
    string temp_s = "";
    temp_s += temp_c;
    return temp_s;
}

int findFirstOpPos(string truyenVao)
{
    for (int i = 1; i < truyenVao.size(); i++)
        if (isdigit(truyenVao[i - 1]) != 0 || (truyenVao[i-1] >= 65 && truyenVao[i-1] <=70) && (truyenVao[i] == '+' || truyenVao[i] == '-' || truyenVao[i] == '*' || truyenVao[i] == '/'
            || truyenVao[i] == '<' || truyenVao[i] == '>' || truyenVao[i] == '=' ))
        {
            return i;
        }
    return -1;
}

char getFirstOp(string truyenVao)
{
    for (int i = 1; i < truyenVao.size(); i++)
        if (isdigit(truyenVao[i - 1]) != 0 && (truyenVao[i] == '+' || truyenVao[i] == '-' || truyenVao[i] == '*' || truyenVao[i] == '/'
            || truyenVao[i] == '<' || truyenVao[i] == '>' || truyenVao[i] == '='))
        {
            return truyenVao[i];
        }
    return ' ';
}
string getOp(string truyenVao, string &num1, string &num2) {
    // a= so thu nhat
    // b la so thu 2
    // hàm return dấu
    if (getFirstOp(truyenVao) == '+' || getFirstOp(truyenVao) == '-' || getFirstOp(truyenVao) == '*'	//Toan tu + - * /
        || getFirstOp(truyenVao) == '/')
    {
        num1 = truyenVao.substr(0, findFirstOpPos(truyenVao) );
        num2 = truyenVao.substr(findFirstOpPos(truyenVao) + 1);
    }
    else //Toán tử so sánh
    {
        num1 = truyenVao.substr(0, findFirstOpPos(truyenVao) );
        if (truyenVao[findFirstOpPos(truyenVao) + 1] == '=')
        {
            num2 = truyenVao.substr(findFirstOpPos(truyenVao) + 2);
            return convertStringToChar(to_string(truyenVao[findFirstOpPos(truyenVao)])) + convertStringToChar(to_string(truyenVao[findFirstOpPos(truyenVao) + 1]));
        }
        else
            num2 = truyenVao.substr(findFirstOpPos(truyenVao) + 1);
    }
    return convertStringToChar(to_string(truyenVao[findFirstOpPos(truyenVao)]));
}
