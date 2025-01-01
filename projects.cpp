#include "projects.h"
#include "commonFunctions.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "tasks.h"
using namespace std;

void readProjects(const string &name, vector<structureProjects> &structure) {
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
                        case 0: strukt.ID = stoi(test);
                            break;
                        case 1: strukt.name = test;
                            break;
                        case 2: strukt.description = test;
                            break;
                        case 3: strukt.startDate = createDate(test + ".");
                            break;
                        case 4: strukt.endDate = createDate(test + ".");
                            break;
                        case 5: strukt.status = stoi(test);
                            break;
                        case 6: strukt.taskList.push_back(stoi(test));
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

void saveProjects(const string &name, vector<structureProjects> &structure) {
    ofstream file(name, ios::app);
    if (!file.is_open()) {
        cout << "Nie mozna otworzyc pliku" << endl;
    } else {
        string line;
        for (const structureProjects &i: structure) {
            line += to_string(i.ID) + ";";
            line += i.name + ";";
            line += i.description + ";";
            line += to_string(i.startDate.day) + "." + to_string(i.startDate.month) + "." + to_string(i.startDate.year)
                    + ";";
            line += to_string(i.endDate.day) + "." + to_string(i.endDate.month) + "." + to_string(i.endDate.year) + ";";
            line += readVector(i.taskList, *",") + ";";
            file << line << endl;;
            line = "";
        }
    }
}

void addProject(vector<structureProjects> &structure, vector<taskStructure> &taskStructure) {
    structureProjects strukt;
    int ID;
    if (structure.empty()) {
        ID = 0;
    } else {
        ID = structure.back().ID + 1;
    }
    strukt.ID = ID;
    strukt.name = inputString("Podaj nazwe projektu:");
    strukt.description = inputString("Podaj opis:");
    strukt.startDate = createDate(inputString("Podaj date rozpoczecia [DD.MM.RRRR]:") + ".");
    strukt.endDate = createDate(inputString("Podaj planowana date zakonczenia [DD.MM.RRRR]:") + ".");
    while (true) {
        if (strukt.startDate.day == strukt.endDate.day && strukt.startDate.month == strukt.endDate.month && strukt.
            startDate.year == strukt.endDate.year) {
            cout << "Planowana data zakonczenia nie moze byc taka sama co data rozpoczecia projektu!" << endl;
        } else if (strukt.endDate.year < strukt.startDate.year) {
            cout << "Projekt nie moze sie zakonczyc przed jego rozpoczeciem!" << endl;
        } else if (strukt.startDate.month < strukt.endDate.month) {
            cout << "Projekt nie moze sie zakonczyc przed jego rozpoczeciem!" << endl;
        } else if (strukt.endDate.day < strukt.startDate.day) {
            cout << "Projekt nie moze sie zakonczyc przed jego rozpoczeciem!" << endl;
        } else {
            break;
        }
        strukt.endDate = createDate(inputString("Podaj planowana date zakonczenia [DD.MM.RRRR]:"));
    }
    // strukt.status = inputString("Podaj status projektu (np. „planowany,” „w trakcie,” „zakończony”)");
    cout << "Jaki jest obecny status projektu?\n1. Planowany\n2. W trakcie\n3. Zakonczony" << endl;
    strukt.status = inputInt("Wybierz opcje:", 3);
    // strukt.taskList = createVector(inputString("Podaj po przecinku ID zadan podlegajacych pod ten projekt:"), *",");
    int amount = inputInt("Ile zadan podlega zadaniu?:", 2147483647);
    vector<int> tasks;
    tasks.reserve(amount);
    for (int i = 0; i < amount; i++) {
        addTask(taskStructure, structure, ID, true);
    }
    strukt.taskList = tasks;
    structure.push_back(strukt);
}

void removeProject(vector<structureProjects> &structure, vector<taskStructure> &taskStructure,
                   vector<structureContributors> &structureContributors) {
    string name = inputString("Podaj nazwe projektu:");
    for (int i = 0; i < structure.size(); i++) {
        if (structure[i].name == name) {
            for (int &j: structure[i].taskList) {
                for (const ::taskStructure &k: taskStructure) {
                    if (j == k.ID) {
                        removeTask(j, taskStructure, structureContributors);
                    }
                }
            }
            structure.erase(structure.begin() + i);
        }
    }
}

void reportProejct(const vector<structureProjects> &structure, const vector<taskStructure> &taskStruc) {
    cout << "Podaj ID projektu: " << endl;
    for (const structureProjects &i: structure) {
        cout << "Nazwa: " << i.name << endl;
        cout << "Opis: " << i.description << endl;
        cout << "Status: " << i.status << endl;
        cout << "Data rozpoczecia: " << i.startDate.day << "." << i.startDate.month << "." << i.startDate.year << endl;
        cout << "Szacowana data zakonczenia: " << i.endDate.day << "." << i.endDate.month << "." << i.endDate.year <<
                endl;
        cout << "ID przypisanych zadan: ";
        for (int j = 0; j < i.taskList.size(); j++) {
            if (j == i.taskList.size() - 1) {
                cout << i.taskList[j] << endl;
            } else {
                cout << i.taskList[j] << ", ";
            }
        }
        cout << "Szacowany najkrotszy mozliwy czas zrealizowania: " << i.endDate.day - i.startDate.day + (
            i.endDate.month - i.startDate.month) * 30 + (i.endDate.year - i.startDate.year) * 365 << " dni" << endl;
        int sumPercentage = 0;
        for (const int &j: i.taskList) {
            for (const taskStructure &k: taskStruc) {
                if (j == k.ID) {
                    sumPercentage += k.completionPercentage;
                }
            }
        }
        cout << "Status realizacji zadania: " << sumPercentage / i.taskList.size() << endl;
    }
}

void editProject(vector<structureProjects> &structure, vector<taskStructure> &taskStruc) {
    const int ID = inputInt("Podaj ID projektu: ", structure.back().ID);
    int amount;
    vector<int> tasks;
    cout <<
            "Co chcesz zmienic? Dostepne opcje:\n1. Nazwa\n2. Opis\n3. Data rozpoczecia\n4. Planowana data zakonczenia\n5. Status\n6. Lista zadan"
            << endl;
    switch (inputInt("Wybierz opcje: ", 6)) {
        case 1:
            structure[ID].name = inputString("Podaj nazwe projektu: ");
            break;
        case 2:
            structure[ID].description = inputString("Podaj opis projektu: ");
            break;
        case 3:
            structure[ID].startDate = createDate(inputString("Podaj date rozpoczecia [DD.MM.RRRR]:") + ".");
            while (true) {
                if (structure[ID].startDate.day == structure[ID].endDate.day && structure[ID].startDate.month ==
                    structure[ID].endDate.month && structure[ID].
                    startDate.year == structure[ID].endDate.year) {
                    cout << "Planowana data rozpoczecia  nie moze byc taka sama co data zakonczenia projektu!" << endl;
                } else if (isLaterDate(structure[ID].startDate, structure[ID].endDate)) {
                    cout << "Projekt nie moze sie rozpoczac po jego zakonczeniu!" << endl;
                } else {
                    break;
                }
                structure[ID].endDate = createDate(inputString("Podaj planowana date zakonczenia [DD.MM.RRRR]:"));
            }
            break;
        case 4:
            structure[ID].endDate = createDate(inputString("Podaj planowana date zakonczenia [DD.MM.RRRR]:") + ".");
            while (true) {
                if (structure[ID].startDate.day == structure[ID].endDate.day && structure[ID].startDate.month ==
                    structure[ID].endDate.month && structure[ID].
                    startDate.year == structure[ID].endDate.year) {
                    cout << "Planowana data zakonczenia nie moze byc taka sama co data rozpoczecia projektu!" << endl;
                } else if (isEarlierDate(structure[ID].endDate, structure[ID].startDate)) {
                    cout << "Projekt nie moze sie zakonczyc przed jego rozpoczeciem!" << endl;
                } else {
                    break;
                }
                structure[ID].endDate = createDate(inputString("Podaj planowana date zakonczenia [DD.MM.RRRR]:"));
            }
            break;
        case 5:
            cout << "Jaki jest obecny status projektu?\n1. Planowany\n2. W trakcie\n3. Zakonczony" << endl;
            structure[ID].status = inputInt("Wybierz opcje:", 3);
            break;
        case 6:
            amount = inputInt("Ile zadan podlega zadaniu?:", 2147483647);
            tasks.reserve(amount);
            for (int i = 0; i < amount; i++) {
                addTask(taskStruc, structure, ID, true);
            }
            structure[ID].taskList = tasks;
    }
}
