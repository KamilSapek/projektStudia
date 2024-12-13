#include "contributors.h"
#include "commonFunctions.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void readContributors(const char* name, vector<strucureContributors>& structure) {
    cout << name << endl;
    ifstream file(name);
    if (!file.is_open()) {
        cout << "Nie mozna otworzyc pliku" << endl;
    } else {
        strucureContributors strukt;
        int iterator, lineNumer;
        string line, test;
        lineNumer = 0;
        while (getline(file, line)) {
            line += ';';
            iterator = 0;
            for (int i = 0; i < line.length(); i++) {
                if (line.at(i) == ';') {
                    switch (iterator) {
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
                    iterator++;
                } else {
                    test += line.at(i);
                }
            }
            lineNumer++;
        }
        structure.push_back(strukt);
    }
}

void saveContributor(const char* name, vector<strucureContributors>& structure) {
    ofstream file(name, ios::app);
    if (!file.is_open()) {
        cout << "Nie mozna otworzyc pliku" << endl;
    } else {
        string line;
        for (auto i : structure) {
            line += to_string(i.ID) + ";";
            line += i.name + ";";
            line += i.surname + ";";
            line += readVector(i.tasksToDo, *",") + ";";
            line += readVector(i.historyOfTasks, *",") + "\n";
            file << line;
            line = "";
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