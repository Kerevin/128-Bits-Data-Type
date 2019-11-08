#pragma once
#include<QMainWindow>
#include<string>
#include<iostream>
#include<vector>

using namespace std;

bool isNum(char a);
bool isHex(char &a);
bool isOp(char a);
bool checkSyntaxBin(string truyenVao);
bool checkSyntaxDecInt(string truyenVao);
bool checkSyntaxDecFloat(string &truyenVao);
bool checkSyntaxHex(string &truyenVao);
