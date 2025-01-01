#ifndef COMMONFUNCTIONS_H
#define COMMONFUNCTIONS_H
#include "structures.h"
#include <string>
#include <vector>
using namespace std;



vector<int> createVector(string data, char splitter);
string readVector(const vector<int> &vector, char splitter);
string inputString(const string& text);
int inputInt(const string& text, const int& maxChoice);
date createDate(const string& text);
bool isEarlierDate(const date &date1, const date &date2);
bool isLaterDate(const date &date1, const date &date2);


#endif //COMMONFUNCTIONS_H
