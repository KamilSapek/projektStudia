#include "interface.h"
#include "tasks.h"
#include "projects.h"
#include "contributors.h"
#include "commonFunctions.h"

#include <iostream>
using namespace std;

/*interfejs projekty*/
void projectsInterface(vector<structureProjects> &structureProjects, vector<taskStructure> &taskStructure,
                       vector<structureContributors> structureContributors) {
    // obsluga wyboru uzytkownika
    while (true) {
        system("clear");
        // const int choice = interfaceAndChoice("PROJEKTY",
        // {"Dodaj projekt", "Usun projekt", "Edytuj projekt", "Menu glowne"});
        cout << "PROJEKTY\n1. Dodaj projekt\n2. Usun projekt\n3. Edytuj projekt\n4. Menu glowne" << endl;
        const int choice = inputInt("Wybierz opcje:", 4);
        if (choice == 1) {
            addProject(structureProjects, taskStructure);
        } else if (choice == 2) {
            removeProject(structureProjects, taskStructure, structureContributors);
        } else if (choice == 3) {
            editProject(structureProjects, taskStructure);
        } else if (choice == 4) {
            break;
        } else {
            cout << "Nie ma takiego wyboru!" << endl;
        }
    }
}

/*interfejs zadania*/
void tasksInterface(vector<taskStructure> &taskStructure, vector<structureContributors> &structureContributors,
                    vector<structureProjects> &structureProjects) {
    while (true) {
        system("clear");
        cout << "ZADANIA\n1. Dodaj zadanie\n2. Usun zadanie\n3. Edytuj zadanie\n4. Menu glowne" << endl;
        const int choice = inputInt("Wybierz opcje:", 4);
        // obsluga wyboru uzytkownika
        if (choice == 1) {
            addTask(taskStructure, structureProjects, -1, false);
        } else if (choice == 2) {
            removeTask(-1, taskStructure, structureContributors);
        } else if (choice == 3) {
            editTask(taskStructure);
        } else if (choice == 4) {
            break;
        } else {
            cout << "Nie ma takiego wyboru!" << endl;
        }
    }
}

/*interfejs czlonkowie*/
void contributorsInterface(vector<structureContributors> &structureContributors,
                           vector<taskStructure> &taskStructure) {
    // obsluga wyboru uzytkownika
    while (true) {
        system("clear");
        cout << "CZLONKOWIE\n1. Dodaj czlonka\n2. Usun czlonka\n3. Edytuj czlonka\n4. Menu glowne" << endl;
        const int choice = inputInt("Wybierz opcje: ", 4);
        if (choice == 1) {
            addContributor(structureContributors, taskStructure);
        } else if (choice == 2) {
            removeContributor(structureContributors, taskStructure);
        } else if (choice == 3) {
            editContributor(structureContributors, taskStructure);
        } else if (choice == 4) {
            break;
        } else {
            cout << "Nie ma takiego wyboru!" << endl;
        }
    }
}

/*menu glowne*/
void mainMenu(vector<structureProjects> &structureProjects,
              vector<taskStructure> &taskStructure,
              vector<structureContributors> &structureContributors,
              files &files) {
    while (true) {
        system("clear");
        cout << "MENU GLOWNE\n1. Projekty\n2. Zadania\n3. Czlonkowie\n4. Koniec" << endl;
        const int choice = inputInt("Wybierz opcje: ", 4);
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
