#include "convertor.h"

string convertor::convert(number n)
{
    return fromDec(toDec(n.val, n.iss), n.oss);
}

string convertor::itos(int number) {
    string res;
    stringstream stream;
    stream << number;
    stream >> res;
    return res;
}

int convertor::stoi(string line) {
    int res;
    stringstream stream(line);
    stream >> res;
    if(line != "0" && res == 0) throw invalid_argument("stoi: argument have to be a number");
    return res;
}

int convertor::ctoi(char ch) {
    int res;
    stringstream stream(&ch);
    stream >> res;
    if(ch != '0' && res == 0) throw invalid_argument("ctoi: argument have to be a number");
    return res;
}

string convertor::itol(int number) {
    if(number < 10) return itos(number);
    if(number < 10 || number > 35) throw invalid_argument("itol: argument have to be in [0; 35]");
    string s(1, (char)(number + 55));
    return s;
}

int convertor::ltoi(char number) {
    int n = (int) number - 55;
    if(n < 10) return ctoi(number);
    if(n > 90) throw invalid_argument("ltoi: argument have to be in [0; Z]");
    return n;
}

void convertor::reverse(string& line, int length) {
    string res = "";
    for(int i = length - 1; i >= 0; i--) res += line[i];
    line = res;
}

string convertor::toDec(string val, int ss) {
    if(ss < 2 || ss > 36) throw invalid_argument("toDec: notation have to be in [2; 36]");
    int dec = 0;
    for(int i = 0; i < val.length(); i++) {
        int index = val.length() - 1 - i;
        int rank = ltoi(val[index]);
        if(rank >= ss) throw invalid_argument("toDec: argument in wrong notation");
        dec += rank * pow(ss, i);
    }
    return itos(dec);
}

string convertor::fromDec(string val, int ss) {
    if(ss < 2 || ss > 36) throw invalid_argument("fromDec: notation have to be in [2; 36]");
    int num = stoi(val);
    string res = "";
    while(num) {
        res += itol(num % ss);
        num /= ss;
    }
    reverse(res, res.length());
    return res;
}
