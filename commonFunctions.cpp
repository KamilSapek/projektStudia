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

/*tworzy wektor intow na podstawie podanego tekstu i znaku interpunkcyjnego*/
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

/*przetwarza wektor na string*/
string readVector(const std::vector<int> &vector, const char splitter) {
    string stringToReturn;
    for (const int i : vector) {
        stringToReturn += to_string(i) + splitter;
    }
    stringToReturn.pop_back();
    return stringToReturn;
}

/*prosi uzytkownika o podanie stringa i sprawdza czy nie wystapil blad podczas tego lub czy cokolwiek wpisal*/
string inputString(const string& text) {
    string toReturn;
    cout << text << " ";
    getline(cin, toReturn);
    // dopoki istnieje blad podczas wpisywania stringa
    while (toReturn.empty() || !cin) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ups! Cos poszlo nie tak. Sprobuj ponownie." << endl;
        cout << text;
        getline(cin, toReturn);
    }
    cout << toReturn << endl;
    return toReturn;
}

/*prosi uzytkownika o podanie inta i sprawdza czy nie wystapil blad podczas tego lub czy cokolwiek wpisal*/
auto inputInt(const string &text, const int &maxChoice) -> int {
    int toReturn;
    cout << text;
    cin >> toReturn;
    // dopoki wystepuje blad podczas podawania liczby
    while (!cin) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ups! Cos poszlo nie tak. Sprobuj ponownie." << endl;
        cout << text;
        cin >> toReturn;
    }
    cin.ignore();
    if (toReturn > maxChoice) {
        cout << "Nie mozesz podac liczby wiekszej niz " << maxChoice << "!" << endl;
        return inputInt(text, maxChoice);
    }
    return toReturn;
}

date createDate(const string& text) {
    date dateToReturn = {};
    int iterator = 0;
    string test;
    for (int i = 0; i < text.length(); i++) {
        if (text.at(i) == '.') {
            switch (iterator) {
                case 0: dateToReturn.day = stoi(test); break;
                case 1: dateToReturn.month = stoi(test); break;
                case 2: dateToReturn.year = stoi(test); break;
            }
            iterator++;
            test = "";
        } else {
            test += text.at(i);
        }
    }
    return dateToReturn;
}