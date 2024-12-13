//
// Created by Kamil on 12/9/2024.
//

#include "wspolneFunkcje.h"
#include <iostream>
#include <vector>
using namespace std;

vector<int> utworzWektor(string dane, char rozdzielnik) {
    dane += rozdzielnik;
    vector<int> zwor;
    string test;
    for (int i = 0; i < dane.length(); i++) {
        if (dane.at(i) == rozdzielnik) {
            zwor.push_back(stoi(test));
            test = "";
        } else {
            test += dane.at(i);
        }
    }
    return zwor;
}

std::string odczytajWektor(std::vector<int> wektor, const char rozdzielnik) {
    string zwrot;
    for (int i = 0; i < wektor.size(); i++) {
        zwrot += to_string(wektor.at(i)) + rozdzielnik;
    }
    zwrot.pop_back();
    return zwrot;
}
