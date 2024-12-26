
#include "projects.h"
#include "commonFunctions.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "tasks.h"
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
        for (const structureProjects& i : structure) {
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

void addProject(vector<structureProjects>& structure) {
    structureProjects strukt;
    strukt.name = inputString("Podaj nazwe projektu:");
    strukt.description = inputString("Podaj opis:");
    strukt.startDate = createVector(inputString("Podaj date rozpoczecia [DD.MM.RRRR]:"), *".");
    strukt.endDate = createVector(inputString("Podaj planowana date zakonczenia [DD.MM.RRRR]:"), *".");
    strukt.status = inputString("Podaj status projektu (np. „planowany,” „w trakcie,” „zakończony”)");
    strukt.taskList = createVector(inputString("Podaj po przecinku ID zadan podlegajacych pod ten projekt:"), *",");
    structure.push_back(strukt);
}

void removeProject(vector<structureProjects>& structure, vector<taskStructure>& taskStructure) {
    string name = inputString("Podaj nazwe projektu:");
    for (int i = 0; i < structure.size(); i++) {
        if (structure[i].name == name) {
            for (const int& j : structure[i].taskList) {
                for (const::taskStructure& k : taskStructure) {

                }
            }
            structure.erase(structure.begin() + i);

        }
    }
}

void report() {

}

void editProject() {

}
