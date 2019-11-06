#pragma once
#include<QMainWindow>
#include<string>
#include<iostream>
#include<vector>
using namespace std;
bool isNum(char a);
bool checkSyntax(string);
bool isOperator(char a);
void findPos(vector<int>&posOperator, vector<int>&posNum, string a);
void getNum(vector<string>&num, string a, vector<int>posNum);
bool checkSyntax(string a);
bool checkSyntaxBinary(string a);
bool checkSyntaxDecimal(string a);
bool checkSyntaxHeximal(string a);

