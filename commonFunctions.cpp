//
// Created by Kamil on 12/9/2024.
//

#include "commonFunctions.h"
#include <iostream>
#include <vector>
using namespace std;

vector<int> createVector(string data, char splitter) {
    data += splitter;
    vector<int> vectorToReturn;
    string test;
    for (int i = 0; i < data.length(); i++) {
        if (data.at(i) == splitter) {
            vectorToReturn.push_back(stoi(test));
            test = "";
        } else {
            test += data.at(i);
        }
    }
    return vectorToReturn;
}

std::string readVector(const std::vector<int> &vector, const char splitter) {
    string stringToReturn;
    for (const int i : vector) {
        stringToReturn += to_string(i) + splitter;
    }
    stringToReturn.pop_back();
    return stringToReturn;
}