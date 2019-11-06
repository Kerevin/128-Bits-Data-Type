#include"checkSyntax.h"

vector<int>posOperator, posNum;
vector<string>num;
bool isNum(char a) {
    if ((a >= 48 && a <= 57) || (a >= 65 && a <= 70))
        return true;
    return false;
}
bool isOperator(char a) {
    if (a == 42 || a == 43 || a == 45 || a == 46 || a == 47 || a == 38 || a == 60 || a == 61 || a == 62 || a == 94 || a == 124 || a == 126)
        return true;
    return false;
}
void findPos(vector<int>&posOperator, vector<int>&posNum, string a) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 42 || a[i] == 43 || a[i] == 45 || a[i] == 46 || a[i] == 47 || a[i] == 38 || a[i] == 60 || a[i] == 61 || a[i] == 62 || a[i] == 94 || a[i] == 124 || a[i] == 126)
            posOperator.push_back(i);
        if ((a[i] >= 48 && a[i] <= 57) || (a[i] >= 65 && a[i] <= 70) || (a[i] >= 97 && a[i] <= 102))
            posNum.push_back(i);
    }
}
void getNum(vector<string>&num, string a, vector<int>posNum) {
    for (int i = 0; i < posNum.size() - 1; i++) {
        if (posNum[i] != posNum[i + 1] - 1) {
            num.push_back(a.substr(posNum[0], posNum[i] - posNum[0] + 1));
            num.push_back(a.substr(posNum[i + 1], posNum[posNum.size() - 1] - posNum[i + 1] + 1));
            return;
        }
    }
    num.push_back(a.substr(posNum[0], posNum[posNum.size() - 1] + 1));
}
bool checkSyntax(string a) { // false -> syntax error
    if (num.size() == 1) { // neu chuoi co 1 so
        if (posNum[posNum.size() - 1] < posOperator[0]) {
            for (int i = 0; i < a.size(); i++) { // neu dau o sau so
                if (isOperator(a[posNum[posNum.size() - 1] + 1]))
                    return false;
            }
        }
        if (posOperator[posOperator.size() - 1] < posNum[0]) { // neu dau o dau so
            for (int j = 0; j < posOperator.size(); j++) {
                if (a[j] != 43 && a[j] != 126 && a[j] != 45)
                    return false;
            }
        }
    }
    if (num.size() == 2) { //neu chuoi co 2 so
        if (posOperator[posOperator.size() - 1] > posNum[posNum.size() - 1]) { // neu dau o sau so
            return false;
        }
        if (posOperator[0] < posNum[0]) { // neu dau o dau so
            for (int j = 0; posOperator[j] < posNum[0]; j++) {
                if (a[j] != 43 && a[j] != 45)
                    return false;
            }
        }
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == 47 && (a[i + 1] == 47 || a[i + 1] == 42 || a[i + 1] == 46 || a[i + 1] == 38 || a[i + 1] == 124 || a[i + 1] == 94))
                return false;
            if (a[i] == 42 && (a[i + 1] == 47 || a[i + 1] == 42 || a[i + 1] == 46 || a[i + 1] == 38 || a[i + 1] == 124 || a[i + 1] == 94))
                return false;
            if (a[i] == 46 && (a[i + 1] == 47 || a[i + 1] == 42 || a[i + 1] == 46 || a[i + 1] == 38 || a[i + 1] == 124 || a[i + 1] == 94))
                return false;
            if (a[i] == 38 && (a[i + 1] == 47 || a[i + 1] == 42 || a[i + 1] == 46 || a[i + 1] == 38 || a[i + 1] == 124 || a[i + 1] == 94))
                return false;
            if (a[i] == 124 && (a[i + 1] == 47 || a[i + 1] == 42 || a[i + 1] == 46 || a[i + 1] == 38 || a[i + 1] == 124 || a[i + 1] == 94))
                return false;
            if (a[i] == 94 && (a[i + 1] == 47 || a[i + 1] == 42 || a[i + 1] == 46 || a[i + 1] == 38 || a[i + 1] == 124 || a[i + 1] == 94))
                return false;
            if (a[i] == 32 || (a[i] == a[i + 1] && (a[i] == 60 || a[i] == 62)))
                return false;
        }
    }

    return true;
}
bool checkSyntaxBinary(string a){
    findPos(posOperator, posNum, a);
    getNum(num, a, posNum);
    if(posOperator.size()==0){
        for(int i = 0;i<a.size();i++)
            if(isNum(a[i]) && (a[i] != '1' && a[i] != '0')){
                posNum.clear();
                num.clear();
                posOperator.clear();
                return false;
            }
    }
    else
        if(!checkSyntax(a)){
            posNum.clear();
            num.clear();
            posOperator.clear();
            return false;
        }
    posNum.clear();
    num.clear();
    posOperator.clear();
    return true;

}
bool checkSyntaxDecimal(string a){
    findPos(posOperator, posNum, a);
    getNum(num, a, posNum);
    if(posOperator.size()==0){
        posNum.clear();
        num.clear();
        posOperator.clear();
        return true;
    }
    else if(!checkSyntax(a)){
        posNum.clear();
        num.clear();
        posOperator.clear();
        return false;
    }
    posNum.clear();
    num.clear();
    posOperator.clear();
    return true;

}
bool checkSyntaxHeximal(string a){
    findPos(posOperator, posNum, a);
    getNum(num, a, posNum);
    if(posOperator.size()==0){
        for(int i = 0;i<a.size();i++)
            if(!isNum(a[i])){
                posNum.clear();
                num.clear();
                return false;
            }
    }
    else if(!checkSyntax(a)){
        posNum.clear();
        num.clear();
        posOperator.clear();
        return false;
    }
    posNum.clear();
    num.clear();
    posOperator.clear();
    return true;
}

