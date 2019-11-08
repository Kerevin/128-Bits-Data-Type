#include"checkSyntax.h"

bool isNum(char a) {
    if (a >= 48 && a <= 57)
        return true;
    return false;
}
bool isHex(char &a) {
    if (a >= 65 && a <= 70)
        return true;
    else if (a >= 97 && a <= 102) {
        a -= 32;
        return true;
    }
    return false;
}
bool isOp(char a) {
    if (a == '+' || a == '-' || a == '*' || a == '/' || a == '<' || a == '>' || a == '=' || a == '&' || a == '|' || a == '^')
        return true;
    return false;
}
bool checkSyntaxBin(string truyenVao) {
    int countOp = 0;
    if (isOp(truyenVao[truyenVao.size() - 1]))
        return false;
    for (int i = 0; i < truyenVao.size(); i++)
        if (isOp(truyenVao[i]))
            countOp++;
    if (countOp > 5)
        return false;

    for (int i = 1; i < truyenVao.size(); i++) {
        if (isHex(truyenVao[i - 1]) || (isNum(truyenVao[i - 1]) && truyenVao[i - 1] > '1') || truyenVao[i - 1] == '.')
            return false;
        else if (isOp(truyenVao[i - 1]) && isOp(truyenVao[i])) {
            if ((truyenVao[i - 1] != '+' && truyenVao[i - 1] != '-' && truyenVao[i - 1] != '<' && truyenVao[i - 1] != '>' && truyenVao[i - 1] != '=')
                && (truyenVao[i] != '+' && truyenVao[i] != '-' && truyenVao[i] != '<' && truyenVao[i] != '>' && truyenVao[i] != '='))
                return false;
        }
    }
    return true;
}
bool checkSyntaxDecInt(string truyenVao) {
    int countOp = 0;
    if (isOp(truyenVao[truyenVao.size() - 1]))
        return false;
    for (int i = 0; i < truyenVao.size(); i++)
        if (isOp(truyenVao[i]))
            countOp++;
    if (countOp > 5)
        return false;

    for (int i = 1; i < truyenVao.size(); i++) {
        if (isHex(truyenVao[i - 1]) || truyenVao[i - 1] == '.')
            return false;
        else if (isOp(truyenVao[i - 1]) && isOp(truyenVao[i])) {
            if ((truyenVao[i - 1] != '+' && truyenVao[i - 1] != '-' && truyenVao[i - 1] != '<' && truyenVao[i - 1] != '>' && truyenVao[i - 1] != '=')
                && (truyenVao[i] != '+' && truyenVao[i] != '-' && truyenVao[i] != '<' && truyenVao[i] != '>' && truyenVao[i] != '='))
                return false;
        }
    }
    return true;
}
bool checkSyntaxDecFloat(string &truyenVao) {
    for (int i = 1; i < truyenVao.size(); i++) {
        if (isHex(truyenVao[i - 1]))
            return false;
        else if (isOp(truyenVao[i]))
            return false;
        else if (truyenVao[i] == '.' && truyenVao[i - 1] == '.')
            return false;
    }
    int count = 0;
    if (truyenVao[0] == '.')
        truyenVao = "0" + truyenVao;
    else {
        for (int i = 0; i < truyenVao.size(); i++) {
            if (truyenVao[i] == '.')
                count++;
        }
        if (count == 0)
            truyenVao = truyenVao + ".0";
    }
    return true;
}
bool checkSyntaxHex(string &truyenVao) {
    int countOp = 0;
    if (isOp(truyenVao[truyenVao.size() - 1]))
        return false;
    for (int i = 0; i < truyenVao.size(); i++)
        if (isOp(truyenVao[i]))
            countOp++;
    if (countOp > 5)
        return false;

    for (int i = 1; i < truyenVao.size(); i++) {
        if (truyenVao[i - 1] == '.')
            return false;
        else if (!isNum(truyenVao[i - 1]) && !isHex(truyenVao[i - 1]) && !isOp(truyenVao[i - 1]))
            return false;
        else if (isOp(truyenVao[i - 1]) && isOp(truyenVao[i])) {
            if ((truyenVao[i - 1] != '+' && truyenVao[i - 1] != '-' && truyenVao[i - 1] != '<' && truyenVao[i - 1] != '>' && truyenVao[i - 1] != '=')
                && (truyenVao[i] != '+' && truyenVao[i] != '-' && truyenVao[i] != '<' && truyenVao[i] != '>' && truyenVao[i] != '='))
                return false;
        }
    }
    return true;
}
