#include "interface.h"
#include "tasks.h"
#include "projects.h"
#include "contributors.h"
#include "commonFunctions.h"

#include <iostream>
using namespace std;

// interfejs projekty
void projectsInterface(vector<structureProjects> &structureProjects, vector<taskStructure> &taskStructure,
                       vector<structureContributors> structureContributors) {
    // obsluga wyboru uzytkownika
    while (true) {
        // const int choice = interfaceAndChoice("PROJEKTY",
        // {"Dodaj projekt", "Usun projekt", "Edytuj projekt", "Menu glowne"});
        cout <<
                "PROJEKTY\n1. Dodaj projekt\n2. Usun projekt\n3. Edytuj projekt\n4. Harmonogram\n5. Raport\n6. Menu glowne"
                << endl;
        const int choice = inputInt("Wybierz opcje: ", 1, 6);
        if (choice == 1) {
            addProject(structureProjects, taskStructure);
        } else if (choice == 2) {
            if (!structureContributors.empty()) {
                removeProject(structureProjects, taskStructure, structureContributors);
            } else {
                cout << "Obecnie nie istnieje zaden projekt" << endl;
            }
        } else if (choice == 3) {
            if (!structureContributors.empty()) {
                editProject(structureProjects, taskStructure);
            } else {
                cout << "Obecnie nie istnieje zaden projekt" << endl;
            }
        } else if (choice == 4) {
            if (!structureContributors.empty()) {
                scheme(structureProjects);
            } else {
                cout << "Obecnie nie istnieje zaden projekt" << endl;
            }
        } else if (choice == 5) {
            if (!structureProjects.empty()) {
                reportProejct(structureProjects, taskStructure);
            } else {
                cout << "Obecnie nie istnieje zaden projekt" << endl;
            }
        } else if (choice == 6) {
            break;
        } else {
            cout << "Nie ma takiego wyboru!" << endl;
        }
    }
}

// interfejs zadania
void tasksInterface(vector<taskStructure> &taskStructure, vector<structureContributors> &structureContributors,
                    vector<structureProjects> &structureProjects) {
    while (true) {
        cout << "ZADANIA\n1. Dodaj zadanie\n2. Usun zadanie\n3. Edytuj zadanie\n4. Raport\n5. Menu glowne" << endl;
        const int choice = inputInt("Wybierz opcje: ", 1, 5);
        // obsluga wyboru uzytkownika
        if (choice == 1) {
            addTask(taskStructure, structureProjects, -1);
        } else if (choice == 2) {
            if (!taskStructure.empty()) {
                removeTask(-1, taskStructure, structureContributors, structureProjects, false);
            } else {
                cout << "Obecnie nie istnieje zadne zadanie" << endl;
            }
        } else if (choice == 3) {
            if (!taskStructure.empty()) {
                editTask(taskStructure);
            } else {
                cout << "Obecnie nie istnieje zadne zadanie" << endl;
            }
        } else if (choice == 4) {
            if (!taskStructure.empty()) {
                reportTask(taskStructure, structureProjects, structureContributors);
            } else {
                cout << "Obecnie nie istnieje zadne zadanie" << endl;
            }
        } else if (choice == 5) {
            break;
        } else {
            cout << "Nie ma takiego wyboru!" << endl;
        }
    }
}

// interfejs czlonkowie
void contributorsInterface(vector<structureContributors> &structureContributors,
                           vector<taskStructure> &taskStructure) {
    // obsluga wyboru uzytkownika
    while (true) {
        cout <<
                "CZLONKOWIE\n1. Dodaj czlonka\n2. Usun czlonka\n3. Edytuj czlonka\n4. Raport\n5. Obciazenie czlonka\n6. Menu glowne"
                << endl;
        const int choice = inputInt("Wybierz opcje: ", 1, 6);
        if (choice == 1) {
            addContributor(structureContributors, taskStructure);
        } else if (choice == 2) {
            if (!structureContributors.empty()) {
                removeContributor(structureContributors, taskStructure);
            } else {
                cout << "Obecnie nie istnieje zaden czlonek" << endl;
            }
        } else if (choice == 3) {
            if (!structureContributors.empty()) {
                editContributor(structureContributors, taskStructure);
            } else {
                cout << "Obecnie nie istnieje zaden czlonek" << endl;
            }
        } else if (choice == 4) {
            if (!structureContributors.empty()) {
                reportContributor(structureContributors, taskStructure);
            } else {
                cout << "Obecnie nie istnieje zaden czlonek" << endl;
            }
        } else if (choice == 5) {
            if (!structureContributors.empty()) {
                contributorLoad(structureContributors, taskStructure);
            } else {
                cout << "Obecnie nie istnieje zaden czlonek" << endl;
            }
        } else if (choice == 6) {
            break;
        } else {
            cout << "Nie ma takiego wyboru!" << endl;
        }
    }
}

// menu glowne
void mainMenu(vector<structureProjects> &structureProjects,
              vector<taskStructure> &taskStructure,
              vector<structureContributors> &structureContributors,
              const files &files) {
    while (true) {
        system("cls");
        cout << "MENU GLOWNE\n1. Projekty\n2. Zadania\n3. Czlonkowie\n4. Koniec" << endl;
        const int choice = inputInt("Wybierz opcje: ", 1, 4);
        // obsluga wyboru uzytkownika
        if (choice == 1) {
            projectsInterface(structureProjects, taskStructure, structureContributors);
        } else if (choice == 2) {
            tasksInterface(taskStructure, structureContributors, structureProjects);
        } else if (choice == 3) {
            contributorsInterface(structureContributors, taskStructure);
        } else if (choice == 4) {
            saveProjects(files.projectsFile, structureProjects);
            saveTasks(files.tasksFile, taskStructure);
            saveContributor(files.contributorsFile, structureContributors);
            break;
        } else {
            cout << "Nie ma takiego wyboru!" << endl;
        }
    }
}
