
#include "projects.h"
#include "commonFunctions.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void readProjects(const char* name, vector<structureProjects>& structure) {
    cout << name << endl;
    ifstream file(name);
    if (!file.is_open()) {
        cout << "Nie mozna otworzyc pliku" << endl;
    } else {
        structureProjects strukt;
        int iterator;
        string line, test;
        while (getline(file, line)) {
            line += ';';
            iterator = 0;
            for (int i = 0; i < line.length(); i++) {
                if (line.at(i) == ';') {
                    switch (iterator) {
                        case 0: strukt.name = test;
                        break;
                        case 1: strukt.description = test;
                        break;
                        case 2: strukt.startDate.push_back(stoi(test));
                        break;
                        case 3: strukt.endDate.push_back(stoi(test));
                        break;
                        case 4: strukt.status = test;
                        break;
                        case 5: strukt.taskList.push_back(stoi(test));
                    }
                    test = "";
                    iterator++;
                } else {
                    test += line.at(i);
                }
            }
            structure.push_back(strukt);
        }
    }
}

void saveProjects(const char* name, vector<structureProjects>& structure) {
    ofstream file(name, ios::app);
    if (!file.is_open()) {
        cout << "Nie mozna otworzyc pliku" << endl;
    } else {
        string line;
        for (auto i : structure) {
            line += i.name + ";";
            line += i.description + ";";
            line += readVector(i.startDate, *".") + ";";
            line += readVector(i.endDate, *".") + ";";
            line += readVector(i.taskList, *",") + ";";
            file << line << endl;;
            line = "";
        }
    }
}

void addProject() {

}

void removeProject() {

}

void report() {

}
