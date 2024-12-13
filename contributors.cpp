#include "contributors.h"
#include "commonFunctions.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void readContributors(const char* nazwa, vector<strucureContributors>& struktura) {
    cout << nazwa << endl;
    ifstream plik(nazwa);
    if (!plik.is_open()) {
        cout << "Nie mozna otworzyc pliku" << endl;
    } else {
        strucureContributors strukt;
        int licznik, numerLinii;
        string linia, test;
        numerLinii = 0;
        while (getline(plik, linia)) {
            linia += ';';
            licznik = 0;
            for (int i = 0; i < linia.length(); i++) {
                if (linia.at(i) == ';') {
                    switch (licznik) {
                        case 0: strukt.ID = stoi(test);
                        break;
                        case 1: strukt.name = test;
                        break;
                        case 2: strukt.surname = test;
                        break;
                        case 3: strukt.tasksToDo = createVector(test, ',');
                        break;
                        case 4: strukt.historyOfTasks = createVector(test, ',');
                        break;
                    }
                    test = "";
                    licznik++;
                } else {
                    test += linia.at(i);
                }
            }
            numerLinii++;
        }
        struktura.push_back(strukt);
    }
}

void saveContributor(const char* nazwa, vector<strucureContributors>& struktura) {
    ofstream plik(nazwa, ios::app);
    if (!plik.is_open()) {
        cout << "Nie mozna otworzyc pliku" << endl;
    } else {
        string linia;
        for (auto i : struktura) {
            linia += to_string(i.ID) + ";";
            linia += i.name + ";";
            linia += i.surname + ";";
            linia += readVector(i.tasksToDo, *",") + ";";
            linia += readVector(i.historyOfTasks, *",") + "\n";
            plik << linia;
            linia = "";
        }
    }
}

void addContributor() {
    int ID;
    cout << "Podaj ID czlonka:";
    cin >> ID;
}

void removeContributor() {

}

void reportContributor() {

}

void editContributor() {

}