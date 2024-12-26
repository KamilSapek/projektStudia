#include "contributors.h"
#include "commonFunctions.h"
#include "tasks.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <limits>
using namespace std;

void readContributors(vector<structureContributors>& structure) {
    files files;
    // cout << name << endl;
    ifstream file(files.contributorsFile);
    if (!file.is_open()) {
        cout << "Nie mozna otworzyc pliku" << endl;
    } else {
        structureContributors strukt;
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

void saveContributor(vector<structureContributors>& structure) {
    files files;
    ofstream file(files.contributorsFile, ios::app);
    if (!file.is_open()) {
        cout << "Nie mozna otworzyc pliku" << endl;
    } else {
        string line;
        for (const structureContributors& i : structure) {
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

void addContributor(vector<structureContributors>& structure, vector<taskStructure>& taskStruc) {
    structureContributors strukt;
    strukt.name = inputString("Podaj imie czlonka:");
    strukt.surname = inputString("Podaj nazwisko czlonka:");
    strukt.tasksToDo = createVector(inputString("Podaj po przecinku ID zadan do wykonania:"), *",");
    for (taskStructure& i : taskStruc) {
        for (const int& g : strukt.tasksToDo) {
            if (i.ID == g) {
                i.contributors.push_back(g);
            }
        }
    }
    strukt.historyOfTasks = createVector(inputString("Podaj po przecinku ID zadan ktore czlonek juz wykonal:"), *",");
    structure.push_back(strukt);
}

void removeContributor(vector<structureContributors>& structure, vector<taskStructure>& taskStruc) {
    int ID;
    ID = inputInt("Podaj ID czlonka:");
    for (int i = 0; i < structure.size(); i++) {
        if (structure[i].ID == ID) {
            structure.erase(structure.begin() + i);
        }
    }
    for (taskStructure& i : taskStruc) {
        for (const int& g : i.contributors) {
            if (ID == g) {
                i.contributors.erase(i.contributors.begin() + g);
            }
        }
    }
}

void reportContributor(vector<structureContributors>& structure) {
    int ID;
    cout << "Podaj ID czlonka:";
    cin >> ID;
    for (const structureContributors& i : structure) {
        if (i.ID == ID) {
            cout << "ID: " << i.ID << endl;
            cout << "Name: " << i.name << endl;
            cout << "Surname: " << i.surname << endl;
            cout << "Tasks to do: ";
            for (const int& g : i.tasksToDo) {
                cout << g << ", ";
            }
            cout << "\nHistory of tasks: ";
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

void editContributor() {
    int choice = inputInt("Podaj ID czlonka:");
    while (choice < 0) {
        cout << "ID nie moze byc mniejsze od 0!" << endl;
        choice = inputInt("Podaj ID czlonka:");
    }
    cout << "Co chcesz zmienic?\nDostepne opcje:" << endl;
    cout << "1. Imie\n2. Nazwisko\n3. Zadania do zrobienia\n4. Historia zrobionych zadan";
    cout << "Wybierz opcje:" << endl;
    cin >> choice;
    while (!cin) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wybierz opcje jeszcze raz:";
        cin >> choice;
    }
}