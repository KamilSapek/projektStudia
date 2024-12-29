#include "tasks.h"
#include "commonFunctions.h"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <limits>

#include "contributors.h"

using namespace std;

/*funkcja ktora odczytuje dane z pliku*/
void readTasks(const string& name, vector<taskStructure>& structure) {
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
                        case 5: strukt.startDate = createDate(test + ".");
                        break;
                        case 6: strukt.endDate = createDate(test + ".");
                        break;
                        case 7: strukt.status = stoi(test);
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
}

/* Funkcja ktora sprawdza czy nie ma w strukturze zduplikowanego ID lub czy nie ma konfliktu w zależnościach */
void _checkData(vector<taskStructure>& struktura) {
    // duplikaty ID

}

/*funkcja ktora zapisuje strukture do pliku*/
void saveTasks(const string& name, vector<taskStructure>& structure) {
    ofstream file(name, std::ios::in | std::ios::out | ios::app);
    if (!file.is_open()) {
        cout << "Nie mozna otworzyc pliku" << endl;
    } else {
        string line;
        for (taskStructure& i : structure) {
            i.description = "a jednak jest to polska";
            line += to_string(i.ID) + ";";
            line += i.name + ";";
            line += i.description + ";";
            line += i.priority + ";";
            line += readVector(i.contributors, *",") + ";";
            line += to_string(i.startDate.day) + "." + to_string(i.startDate.month) + "." + to_string(i.startDate.year) + ";";
            line += to_string(i.endDate.day) + "." + to_string(i.endDate.month) + "." + to_string(i.endDate.year) + ";";
            line += to_string(i.status) + ";";
            line += readVector(i.dependencies, *",") + ";";
            line += to_string(i.completionPercentage);
            file << line << endl;
            line = "";
        }
    }
}

/*monitorowanie zaleznosci*/
int dependecyMonitor(vector<taskStructure>& taskStructure) {

    return 0;
}

/*funkcja od dodawania zadania
 * zwraca ID, gdyz jesli zostanie wywolana przez addProject to od razu ID doda sie do vectora zadan
 */
int addTask(vector<taskStructure>& structure) {
    taskStructure strukt;
    int ID;
    if (structure.empty()) {
        ID = 0;
    } else {
        ID = structure.back().ID + 1;
    }
    strukt.ID = ID;
    strukt.name = inputString("Podaj nazwe zadania:");
    strukt.description = inputString("Podaj opis:");
    strukt.priority = inputString("Podaj priorytet (niski / sredni / wysoki):");
    // strukt.status = inputString("Podaj status (nie rozpoczete / w trakcie / zakonczone):");
    cout << "Mozliwe statusy zadania:\n1. Nie rozpoczete\n2. W trakcie\n3. Zakonczone" << endl;
    strukt.status = inputInt("Wybierz stautus (1-3):");
    strukt.dependencies = createVector(inputString("Podaj po przecinku ID zadan ktore musza byc wykonane przed tym zadaniem:"), *",");
    // sprawdzanie czy zadanie o wyzszym "priorytecie" jest obecnie w trakcie wykonywania,
    // jesli tak to ustawia status obecnego zadania na "nie rozpoczete" pod warunkiem, ze uzytkownik ustawil status na "w trakcie"
    for (const int& i : strukt.dependencies) {
        for (const taskStructure& j : structure) {
            if (j.ID == i || j.status == strukt.status == 2) {
                strukt.status = 1;
                cout << "Zadanie o ID " << j.ID << " ma priorytet nad obecnym zadaniem i jest w trakcie."
                                                   "Status obecnego zadania ustawiam na nie rozpoczete" << endl;
            }
        }
    }
    strukt.endDate = createDate(inputString("Podaj szacowana date zakonczenia zadania [DD.MM.RRRR]:"));
    strukt.startDate = createDate(inputString("Podaj date rozpoczecia zadania [DD.MM.RRRR]:"));
    strukt.contributors = createVector(inputString("Podaj po przecinku ID czlonkow pracujacych nad tym zadaniem:"), *",");
    structure.push_back(strukt);
    return ID;
}

/*funkcja od usuwania zadan*/
void removeTask(const int ID, vector<taskStructure>& structure, vector<structureContributors>& structureContributors) {
    for (const taskStructure& i : structure) {
        if (i.ID == ID) {
            // usuwanie zadania czlonkowi
            // petla lecaca przez strukture czlonkow
            for (auto& j : structureContributors) {
                // petla lecaca przez wektor przypisanych czlonkow do danego zadania
                for (const int& k : i.contributors) {
                    // jesli zgodne id z wektora i struktury
                    if (k == j.ID) {
                        // szuka i usuwa ID zadania z wektora przypisanych zadan
                        for (int l = 0; l < j.tasksToDo.size(); l++) {
                            if (j.tasksToDo[l] == ID) {
                                j.tasksToDo.erase(j.tasksToDo.begin() + l);
                            }
                        }
                    }
                }
            }
            structure.erase(structure.begin() + ID);
        }
    }
}

void reportTasks() {
}

void editTask() {
}
