#include "tasks.h"
#include "commonFunctions.h"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

void readTasks(const char* name, vector<taskStructure>& structure) {
    cout << name << endl;
    ifstream file(name);
    if (!file.is_open()) {
        cout << "Nie mozna otworzyc pliku" << endl;
    } else {
        taskStructure strukt;
        int iterator;
        string line, test;
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
                        case 2: strukt.description = test;
                        break;
                        case 3: strukt.priority = test;
                        break;
                        case 4: strukt.contributors = createVector(test, *",");
                        break;
                        case 5: strukt.startDate = createVector(test, *".");
                        break;
                        case 6: strukt.estimatedEndDate = createVector(test, *".");
                        break;
                        case 7: strukt.status = test;
                        break;
                        case 8: strukt.dependencies = createVector(test, *",");
                        break;
                        case 9: strukt.completionPercentage = stoi(test);
                        break;
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
    for (auto i : structure)
        cout << i.description << endl;
}

/* Funkcja ktora sprawdza czy nie ma w strukturze zduplikowanego ID lub czy nie ma konfliktu w zależnościach */
void _checkData(vector<taskStructure>& struktura) {
    // duplikaty ID

}

void saveTasks(const char* name, vector<taskStructure>& structure) {
    ofstream file(name, std::ios::in | std::ios::out | ios::app);
    if (!file.is_open()) {
        cout << "Nie mozna otworzyc pliku" << endl;
    } else {
        string line;
        for (auto i : structure) {
            i.description = "a jednak jest to polska";
            line += to_string(i.ID) + ";";
            line += i.name + ";";
            line += i.description + ";";
            line += i.priority + ";";
            line += readVector(i.contributors, *",") + ";";
            line += readVector(i.startDate, *".") + ";";
            line += readVector(i.estimatedEndDate, *".") + ";";
            line += i.status + ";";
            line += readVector(i.dependencies, *",") + ";";
            line += to_string(i.completionPercentage);
            file << line << endl;
            line = "";
        }
    }
}

void addTask() {
}

void removeTask() {
}

void raportTasks() {
}

void editTask() {
}
