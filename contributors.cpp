#include "contributors.h"
#include "commonFunctions.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <limits>
using namespace std;

void readContributors(const string &name, vector<structureContributors> &structure) {
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
    ofstream file(name, ios::app);
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
    strukt.name = inputString("Podaj imie czlonka:");
    strukt.surname = inputString("Podaj nazwisko czlonka:");
    strukt.tasksToDo = createVector(inputString("Podaj po przecinku ID zadan do wykonania:"), *",");
    for (taskStructure &i: taskStruc) {
        for (const int &g: strukt.tasksToDo) {
            if (i.ID == g) {
                i.contributors.push_back(g);
            }
        }
    }
    strukt.historyOfTasks = createVector(inputString("Podaj po przecinku ID zadan ktore czlonek juz wykonal:"), *",");
    structure.push_back(strukt);
}

void removeContributor(vector<structureContributors> &structure, vector<taskStructure> &taskStruc) {
    const int ID = inputInt("Podaj ID czlonka:", structure.back().ID);
    for (int i = 0; i < structure.size(); i++) {
        if (structure[i].ID == ID) {
            structure.erase(structure.begin() + i);
        }
    }
    for (taskStructure &i: taskStruc) {
        for (const int &g: i.contributors) {
            if (ID == g) {
                i.contributors.erase(i.contributors.begin() + g);
            }
        }
    }
}

void reportContributor(const vector<structureContributors> &structure) {
    int ID;
    cout << "Podaj ID czlonka:";
    cin >> ID;
    for (const structureContributors &i: structure) {
        if (i.ID == ID) {
            cout << "Imie: " << i.name << endl;
            cout << "Nazwisko: " << i.surname << endl;
            cout << "Zadania do zrobienia: ";
            for (const int &g: i.tasksToDo) {
                cout << g << ", ";
            }
            cout << "\nZadania ktore zrobil: ";
            for (int g = 0; g < i.historyOfTasks.size(); g++) {
                if (g == i.historyOfTasks.size()) {
                    cout << i.historyOfTasks[g] << endl;
                } else {
                    cout << i.historyOfTasks[g] << ", ";
                }
            }
            cout << endl;
        }
    }
}

void editContributor(vector<structureContributors> &structure, vector<taskStructure> &taskStruc) {
    int ID = inputInt("Podaj ID czlonka:", 4);
    while (ID < 0) {
        cout << "ID nie moze byc mniejsze od 0!" << endl;
        ID = inputInt("Podaj ID czlonka:", 4);
    }
    cout << "Co chcesz zmienic?\nDostepne opcje:" << endl;
    cout << "1. Imie\n2. Nazwisko\n3. Zadania do zrobienia\n4. Historia zrobionych zadan";
    switch (inputInt("Wybierz opcje: ", 4)) {
        case 1:
            structure[ID].name = inputString("Podaj imie czlonka: ");
            break;
        case 2:
            structure[ID].surname = inputString("Podaj nazwisko czlonka: ");
            break;
        case 3:
            structure[ID].tasksToDo = createVector(inputString("Podaj po przecinku ID zadan do wykonania:"), *",");
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
                inputString("Podaj po przecinku ID zadan ktore czlonek juz wykonal:"), *",");
            break;
    }
}

bool isEarlierDate(const date &date1, const date &date2) {
    if (date1.year < date2.year) {
        return true;
    }
    if (date1.month < date2.month && date1.year == date2.year) {
        return true;
    }
    if (date1.day < date2.day && date1.year == date2.year && date1.month == date2.month) {
        return true;
    }
    return false;
}

bool isLaterDate(const date &date1, const date &date2) {
    if (date1.year > date2.year) {
        return true;
    }
    if (date1.month > date2.month && date1.year == date2.year) {
        return true;
    }
    if (date1.day > date2.day && date1.year == date2.year && date1.month == date2.month) {
        return true;
    }
    return false;
}

void contributorLoad(const vector<structureContributors> &structureContributors,
                     const vector<taskStructure> &taskStruc) {
    const int ID = inputInt("Podaj ID czlonka:", structureContributors.back().ID);
    int amountOfTasks = 0;
    date earliestDate = taskStruc[0].startDate, latestDate = taskStruc[0].endDate;
    for (const struct structureContributors &i: structureContributors) {
        if (i.ID == ID) {
            amountOfTasks = i.tasksToDo.size();
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
        }
    }
    cout << "Liczba przypisanych zadan: " << amountOfTasks << endl;
    cout << "Szacowany czas wykonania wszystkich zadan: " << latestDate.day - earliestDate.day + (
        latestDate.month - earliestDate.month) * 30 + (latestDate.year - earliestDate.year) * 365 << endl;
}
