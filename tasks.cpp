#include "tasks.h"
#include "commonFunctions.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

/*funkcja ktora odczytuje dane z pliku*/
void readTasks(const string &name, vector<taskStructure> &structure) {
    cout << "Tasks" << endl;
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
                        case 1:
                            strukt.projectID = stoi(test);
                        case 2: strukt.name = test;
                            break;
                        case 3: strukt.description = test;
                            break;
                        case 4: strukt.priority = stoi(test);
                            break;
                        case 5: strukt.contributors = createVector(test, *",");
                            break;
                        case 6: strukt.startDate = createDate(test + ".", true);
                            break;
                        case 7: strukt.endDate = createDate(test + ".", true);
                            break;
                        case 8: strukt.status = stoi(test);
                            break;
                        case 9: strukt.dependencies = createVector(test, *",");
                            break;
                        case 10: strukt.completionPercentage = stoi(test);
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
void _checkData(vector<taskStructure> &struktura) {
    // duplikaty ID
}

/*funkcja ktora zapisuje strukture do pliku*/
void saveTasks(const string &name, vector<taskStructure> &structure) {
    // ofstream file(name, std::ios::in | std::ios::out | ios::app);
    ofstream file(name, ios::trunc);
    if (!file.is_open()) {
        cout << "Nie mozna otworzyc pliku" << endl;
    } else {
        string line;
        for (taskStructure &i: structure) {
            line += to_string(i.ID) + ";";
            line += to_string(i.projectID) + ";";
            line += i.name + ";";
            line += i.description + ";";
            line += to_string(i.priority) + ";";
            line += readVector(i.contributors, *",") + ";";
            line += to_string(i.startDate.day) + "." + to_string(i.startDate.month) + "." + to_string(i.startDate.year)
                    + ";";
            line += to_string(i.endDate.day) + "." + to_string(i.endDate.month) + "." + to_string(i.endDate.year) + ";";
            line += to_string(i.status) + ";";
            line += readVector(i.dependencies, *",") + ";";
            line += to_string(i.completionPercentage);
            file << line << endl;
            line = "";
        }
    }
}

/*funkcja od dodawania zadania
 * zwraca ID, gdyz jesli zostanie wywolana przez addProject to od razu ID doda sie do vectora zadan
 */
void addTask(vector<taskStructure> &structure, vector<structureProjects> &structProjects, int projectID) {
    taskStructure strukt;
    // ustawienie ID zadania
    int ID;
    if (structure.empty()) {
        ID = 0;
    } else {
        ID = structure.back().ID + 1;
    }
    strukt.ID = ID;
    // ustawienie ID projektu do ktorego ma nalezec te zadanie
    if (projectID == -1) {
        projectID = inputInt("Podaj ID projektu do ktorego mam dodac to zadanie: ", 0, structProjects.back().ID);
    }
    strukt.projectID = projectID;
    // dodanie zadania do projektu
    for (structureProjects &i: structProjects) {
        if (i.ID == projectID) {
            i.taskList.push_back(ID);
        }
    }
    strukt.name = inputString("Podaj nazwe zadania: ", true);
    strukt.description = inputString("Podaj opis: ", true);
    // strukt.priority = inputString("Podaj priorytet (niski / sredni / wysoki):");
    cout << "Mozliwe priorytety:\n1. Niski\n2. Sredni\n3. Wysoki" << endl;
    strukt.priority = inputInt("Wybierz priorytet: ", 1, 3);
    strukt.contributors = createVector(
        inputString("Podaj po przecinku ID czlonkow pracujacych nad tym zadaniem: ", false),
        *",");
    strukt.startDate = createDate(inputString("Podaj date rozpoczecia zadania [DD.MM.RRRR]: ", true) + ".", false);
    strukt.endDate = createDate(inputString("Podaj szacowana date zakonczenia zadania [DD.MM.RRRR]: ", true) + ".",
                                false);
    // sprawdzenie czy data zakonczenia tego zadania nie jest dalsza od daty zakonczenia projektu
    for (structureProjects &i: structProjects) {
        if (i.ID == projectID) {
            while (true) {
                if (strukt.endDate.year > i.endDate.year) {
                    cout << "Zadanie nie moze konczyc sie pozniej niz sam projekt!" << endl;
                } else if (strukt.endDate.month > i.endDate.month && strukt.endDate.year == i.endDate.year) {
                    cout << "Zadanie nie moze konczyc sie pozniej niz sam projekt!" << endl;
                } else if (strukt.endDate.day > i.endDate.day && strukt.endDate.month == i.endDate.month && strukt.
                           endDate.year == i.endDate.year) {
                    cout << "Zadanie nie moze konczyc sie pozniej niz sam projekt!" << endl;
                } else {
                    break;
                }
                cout << "Co chcesz z tym zrobic?\n1. Ustaw date zakonczenia projektu na " << strukt.endDate.day << "."
                        << strukt.endDate.month << "." << strukt.endDate.year << endl;
                cout << "2. Zmienic date zakonczenia zadania" << endl;
                const int choice = inputInt("Wybierz opcje: ", 1, 2);
                if (choice == 1) {
                    i.endDate = strukt.endDate;
                } else {
                    strukt.endDate = createDate(
                        inputString("Podaj szacowana date zakonczenia zadania [DD.MM.RRRR]: ", true) + ".", false);
                }
            }
        }
    }
    // strukt.status = inputString("Podaj status (nie rozpoczete / w trakcie / zakonczone):");
    cout << "Mozliwe statusy zadania:\n1. Nie rozpoczete\n2. W trakcie\n3. Zakonczone" << endl;
    strukt.status = inputInt("Wybierz stautus (1-3): ", 1, 3);
    strukt.dependencies = createVector(
        inputString("Podaj po przecinku ID zadan ktore musza byc wykonane przed tym zadaniem: ", false), *",");
    // sprawdzenie czy zostalo wprowadzone ID ktore nie istnieje
    const int largestIDinTasks = structure.back().ID;
    vector<int> IDtoRemove;
    for (int i = 0; i < strukt.dependencies.size(); i++) {
        if (strukt.dependencies[i] > largestIDinTasks) {
            IDtoRemove.push_back(strukt.dependencies[i]);
            strukt.dependencies.erase(strukt.dependencies.begin() + i);
            i--;
        }
    }
    cout << "ID o numerach: ";
    for (int i = 0; i < IDtoRemove.size(); i++) {
        if (i == IDtoRemove.size() - 1) {
            cout << IDtoRemove[i];
        } else {
            cout << IDtoRemove[i] << ", ";
        }
    }
    cout << " musialem usunac z zaleznosci, gdyz nie istnieja" << endl;
    // sprawdzanie czy zadanie o wyzszym "priorytecie" jest obecnie w trakcie wykonywania,
    // jesli tak to ustawia status obecnego zadania na "nie rozpoczete" pod warunkiem, ze uzytkownik ustawil status na "w trakcie"
    if (strukt.status == 2) {
        for (const int &i: strukt.dependencies) {
            for (const taskStructure &j: structure) {
                if (j.ID == i && j.status == 2) {
                    strukt.status = 1;
                    cout << "Zadanie o ID " << j.ID <<
                            " ma priorytet nad obecnym zadaniem i jest w trakcie wykonywania."
                            "Status obecnego zadania ustawiam na nie rozpoczete" << endl;
                }
            }
        }
    }
    strukt.completionPercentage = 0;
    structure.push_back(strukt);
}

/*funkcja od usuwania zadan*/
void removeTask(int ID, vector<taskStructure> &structure, vector<structureContributors> &structureContributors,
                vector<structureProjects> &structureProjects, const bool &fromProject) {
    if (ID == -1) {
        ID = inputInt("Podaj ID zadania do usuniecia: ", 0, structure.back().ID);
    }
    for (taskStructure &i: structure) {
        if (i.ID == ID) {
            // usuwanie zadania czlonkowi
            // petla lecaca przez strukture czlonkow
            for (auto &j: structureContributors) {
                // petla lecaca przez wektor przypisanych czlonkow do danego zadania
                for (const int &k: i.contributors) {
                    // jesli zgodne id z wektora i struktury
                    if (k == j.ID) {
                        // szuka i usuwa ID zadania z wektora przypisanych zadan
                        for (int l = 0; l < j.tasksToDo.size(); l++) {
                            if (j.tasksToDo[l] == ID) {
                                j.tasksToDo.erase(j.tasksToDo.begin() + l);
                                break;
                            }
                        }
                    }
                }
            }
            structure.erase(structure.begin() + ID);
        }
        i.ID -= 1;
    }
    if (!fromProject) {
        for (int i = 0; i < structureProjects[ID].taskList.size(); i++) {
            if (structureProjects[ID].taskList[i] == ID) {
                structureProjects[ID].taskList.erase(structureProjects[ID].taskList.begin() + i);
            }
        }
    }
}

void reportTask(const vector<taskStructure> &structure, const vector<structureProjects> &structureProjects,
                 const vector<structureContributors> &structureContributors) {
    cout << "ID  nazwa" << endl;
    for (const auto &i: structure) {
        cout << i.ID << "   " << i.name << endl;
    }
    const taskStructure i = structure[inputInt("Podaj ID zadania: ", 0, structure.back().ID)];
    cout << "Nazwa: " << i.name << endl;
    cout << "Opis: " << i.description << endl;
    cout << "Nalezy do projektu: " << structureProjects[i.projectID].name << endl;
    cout << "Status: ";
    switch (i.status) {
        case 1:
            cout << "Nie rozpoczete" << endl;
            break;
        case 2:
            cout << "W trakcie" << endl;
            break;
        case 3:
            cout << "Zakonczone" << endl;
            break;
    }
    cout << "Priorytet: ";
    switch (i.priority) {
        case 1:
            cout << "Niski" << endl;
            break;
        case 2:
            cout << "Sredni" << endl;
            break;
        case 3:
            cout << "Wysoki" << endl;
            break;
    }
    cout << "Data rozpoczecia: " << i.startDate.day << "." << i.startDate.month << "." << i.startDate.year << endl;
    cout << "Szacowana data zakonczenia: " << i.endDate.day << "." << i.endDate.month << "." << i.endDate.year << endl;
    cout << "Procent wykonania: " << i.completionPercentage << "%" << endl;
    cout << "Przypisane osoby do zadania: ";
    for (int j = 0; j < i.contributors.size(); j++) {
        if (j == i.contributors.size() - 1) {
            cout << structureContributors[i.contributors[j]].name << " " << structureContributors[i.contributors[j]].surname << endl;
        } else {
            cout << structureContributors[i.contributors[j]].name << " " << structureContributors[i.contributors[j]].surname << ", ";
        }
    }
    cout << "Zaleznosci: ";
    for (int j = 0; j < i.dependencies.size(); j++) {
        if (j == i.dependencies.size() - 1) {
            cout << structureContributors[i.dependencies[j]].name << endl;
        } else {
            cout << structureContributors[i.dependencies[j]].name << ", ";
        }
    }
}

void editTask(vector<taskStructure> &taskStructure) {
    cout << "ID  nazwa" << endl;
    for (const auto &i: taskStructure) {
        cout << i.ID << "   " << i.name << endl;
    }
    const int ID = inputInt("Podaj ID zadania: ", 0, taskStructure.back().ID),
            largestIDinTasks = taskStructure.back().ID;
    vector<int> IDtoRemove;
    cout <<
            "Co chcesz zmienic? Dostepne opcje:\n"
            "1. Nazwa\n"
            "2. Opis\n"
            "3. Priorytet\n"
            "4. Przypisane osoby\n"
            "5. Data rozpoczecia\n"
            "6. Przewidywana data zakonczenia\n"
            "7. Status\n"
            "8. Zaleznosci\n"
            "9. Procent realizacji zadania\n"
            "10. Wyjdz"
            << endl;
    switch (inputInt("Wybierz opcje: ", 1, 10)) {
        case 1:
            taskStructure[ID].name = inputString("Podaj nowa nazwe: ", true);
            break;
        case 2:
            taskStructure[ID].description = inputString("Podaj nowy opis: ", true);
            break;
        case 3:
            cout << "Mozliwe priorytety:\n1. Niski\n2. Sredni\n3. Wysoki" << endl;
            taskStructure[ID].priority = inputInt("Wybierz priorytet: ", 1, 3);
            break;
        case 4:
            taskStructure[ID].contributors = createVector(
                inputString("Podaj po przecinku ID czlonkow pracujacych nad tym zadaniem: ", false), *",");
            break;
        case 5:
            taskStructure[ID].startDate =
                    createDate(inputString("Podaj date rozpoczecia zadania [DD.MM.RRRR]: ", true) + ".", false);
            break;
        case 6:
            taskStructure[ID].endDate = createDate(
                inputString("Podaj szacowana date zakonczenia zadania [DD.MM.RRRR]: ", true) + ".", false);
            break;
        case 7:
            taskStructure[ID].status = inputInt("Wybierz stautus (1-3): ", 1, 3);
            if (taskStructure[ID].status == 2) {
                for (const int &i: taskStructure[ID].dependencies) {
                    if (taskStructure[i].ID == i && taskStructure[i].status == 2) {
                        taskStructure[i].status = 1;
                        cout << "Zadanie o ID " << taskStructure[i].ID <<
                                " ma priorytet nad obecnym zadaniem i jest w trakcie wykonywania."
                                "Status obecnego zadania ustawiam na nie rozpoczete" << endl;
                    }
                }
            }
            break;
        case 8:
            taskStructure[ID].dependencies = createVector(
                inputString("Podaj po przecinku ID zadan ktore musza byc wykonane przed tym zadaniem: ", false), *",");
        // sprawdzenie czy zostalo wprowadzone ID ktore nie istnieje
            for (int i = 0; i < taskStructure[ID].dependencies.size(); i++) {
                if (taskStructure[ID].dependencies[i] > largestIDinTasks) {
                    IDtoRemove.push_back(taskStructure[ID].dependencies[i]);
                    taskStructure[ID].dependencies.erase(taskStructure[ID].dependencies.begin() + i);
                    i--;
                }
            }
            break;
        case 9:
            taskStructure[ID].completionPercentage = inputInt("Podaj procent realizacji zadania: ", 1, 100);
            break;
        case 10:
            break;
    }
}
