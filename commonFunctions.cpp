//
// Created by Kamil on 12/9/2024.
//

#include "commonFunctions.h"
#include "tasks.h"
#include "contributors.h"
#include "projects.h"

#include <iostream>
#include <limits>
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

string inputString(const string& text, const string& onErrorText) {
    string toReturn;
    cout << text;
    cin >> toReturn;
    while (!cin) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << onErrorText;
        cin >> toReturn;
    }
    return toReturn;
}

int inputInt(const string& text, const string& onErrorText) {
    int toReturn;
    cout << text;
    cin >> toReturn;
    while (!cin) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << onErrorText;
        cin >> toReturn;
    }
    return toReturn;
}