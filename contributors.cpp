#include "contributors.h"
#include "commonFunctions.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void readContributors(const string &name, vector<structureContributors> &structure) {
    cout << "Contributors" << endl;
    ifstream file(name);
    if (!file.is_open()) {
        cout << "Nie mozna otworzyc pliku" << endl;
    } else {
        structureContributors strukt;
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
            structure.push_back(strukt);
        }
    }
}

void saveContributor(const string &name, vector<structureContributors> &structure) {
    ofstream file(name, ios::trunc);
    if (!file.is_open()) {
        cout << "Nie mozna otworzyc pliku" << endl;
    } else {
        string line;
        for (const structureContributors &i: structure) {
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

void addContributor(vector<structureContributors> &structure, vector<taskStructure> &taskStruc) {
    structureContributors strukt;
    strukt.name = inputString("Podaj imie czlonka: ", true);
    strukt.surname = inputString("Podaj nazwisko czlonka: ", true);
    strukt.tasksToDo = createVector(inputString("Podaj po przecinku ID zadan do wykonania: ", false), *",");
    for (taskStructure &i: taskStruc) {
        for (const int &g: strukt.tasksToDo) {
            if (i.ID == g) {
                i.contributors.push_back(g);
            }
        }
    }
    strukt.historyOfTasks = createVector(inputString("Podaj po przecinku ID zadan ktore czlonek juz wykonal: ", false),
                                         *",");
    structure.push_back(strukt);
}

void removeContributor(vector<structureContributors> &structure, vector<taskStructure> &taskStruc) {
    cout << "ID   imie nazwisko" << endl;
    for (const structureContributors &i: structure) {
        cout << i.ID << "   " << i.name << " " << i.surname << endl;
    }
    const int ID = inputInt("Podaj ID czlonka: ", 0, structure.back().ID);
    for (auto i = structure.begin() + ID; i != structure.end(); ++i) {
        if (i->ID == ID) {
            for (taskStructure &j: taskStruc) {
                for (const int &k: i->tasksToDo) {
                    if (j.ID == k) {
                        for (int g = 0; g < j.contributors.size(); g++) {
                            if (j.contributors[g] == ID) {
                                j.contributors.erase(j.contributors.begin() + g);
                                break;
                            }
                        }
                    }
                }
            }
            structure.erase(i);
        }
        i->ID -= 1;
    }
}

void reportContributor(const vector<structureContributors> &structure, const vector<taskStructure> &taskStruc) {
    cout << "ID  imie nazwisko" << endl;
    for (const auto &i: structure) {
        cout << i.ID << "   " << i.name << " " << i.surname << endl;
    }
    const structureContributors i = structure[inputInt("Podaj ID czlonka: ", 0, structure.back().ID)];
    cout << "Imie: " << i.name << endl;
    cout << "Nazwisko: " << i.surname << endl;
    cout << "Zadania do zrobienia: ";
    for (int j = 0; j < i.tasksToDo.size(); j++) {
        if (j == i.tasksToDo.size() - 1) {
            cout << taskStruc[i.tasksToDo[j]].name << endl;
        } else {
            cout << taskStruc[i.tasksToDo[j]].name << ", ";
        }
    }
    cout << endl;
}


void editContributor(vector<structureContributors> &structure, vector<taskStructure> &taskStruc) {
    cout << "ID  imie nazwisko" << endl;
    for (const auto &i: structure) {
        cout << i.ID << "   " << i.name << " " << i.surname << endl;
    }
    const int ID = inputInt("Podaj ID czlonka: ", 0, 4);
    cout << "Co chcesz zmienic?\nDostepne opcje:" << endl;
    cout << "1. Imie\n2. Nazwisko\n3. Zadania do zrobienia\n4. Historia zrobionych zadan\n5. Wyjdz";
    switch (inputInt("Wybierz opcje: ", 0, 5)) {
        case 1:
            structure[ID].name = inputString("Podaj imie czlonka: ", true);
            break;
        case 2:
            structure[ID].surname = inputString("Podaj nazwisko czlonka: ", true);
            break;
        case 3:
            structure[ID].tasksToDo = createVector(inputString("Podaj po przecinku ID zadan do wykonania: ", false),
                                                   *",");
            for (taskStructure &i: taskStruc) {
                for (const int &g: structure[ID].tasksToDo) {
                    if (i.ID == g) {
                        i.contributors.push_back(g);
                    }
                }
            }
            break;
        case 4:
            structure[ID].historyOfTasks = createVector(
                inputString("Podaj po przecinku ID zadan ktore czlonek juz wykonal: ", false), *",");
            break;
        case 5:
            break;
    }
}

void contributorLoad(const vector<structureContributors> &structureContributors,
                     const vector<taskStructure> &taskStruc) {
    cout << "ID  imie nazwisko" << endl;
    for (const auto &i: structureContributors) {
        cout << i.ID << "   " << i.name << " " << i.surname << endl;
    }
    const int ID = inputInt("Podaj ID czlonka: ", 0, structureContributors.back().ID);
    const struct structureContributors i = structureContributors[ID];
    const int amountOfTasks = i.tasksToDo.size();
    date earliestDate = taskStruc[0].startDate, latestDate = taskStruc[0].endDate;
    for (const int &j: i.tasksToDo) {
        for (const taskStructure &k: taskStruc) {
            if (k.ID == j) {
                if (isEarlierDate(k.startDate, earliestDate)) {
                    earliestDate = k.startDate;
                }
                if (isLaterDate(k.endDate, latestDate)) {
                    latestDate = k.endDate;
                }
            }
        }
    }
    cout << "Liczba przypisanych zadan: " << amountOfTasks << endl;
    cout << "Szacowany czas wykonania wszystkich zadan: " << latestDate.day - earliestDate.day + (
        latestDate.month - earliestDate.month) * 30 + (latestDate.year - earliestDate.year) * 365 << endl;
}
