#ifndef CONVERTOR_H
#define CONVERTOR_H

#include "number.cpp"

class convertor
{
public:
    string convert(number n);
private:
    string itos(int number);
    int stoi(string line);
    int ctoi(char ch);
    string itol(int number);
    int ltoi(char number);
    void reverse(string& line, int length);
    string toDec(string val, int ss);
    string fromDec(string val, int ss);
};

#endif // CONVERTOR_H
