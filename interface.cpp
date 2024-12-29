#include "interface.h"
#include "tasks.h"
#include "projects.h"
#include "contributors.h"
#include "commonFunctions.h"

#include <iostream>
using namespace std;

/*interfejs projekty*/
void projectsInterface(vector<structureProjects>& structureProjects, vector<taskStructure>& taskStructure, vector<structureContributors> structureContributors) {
    // obsluga wyboru uzytkownika
    while (true) {
        // const int choice = interfaceAndChoice("PROJEKTY",
        // {"Dodaj projekt", "Usun projekt", "Edytuj projekt", "Menu glowne"});
        cout << "PROJEKTY\n1. Dodaj projekt\n2. Usun projekt\n3. Edytuj projekt\n4. Menu glowne" << endl;
        const int choice = inputInt("Wybierz opcje: ");
        if (choice == 1) {
            addProject(structureProjects, taskStructure);
        } else if (choice == 2) {
            removeProject(structureProjects, taskStructure ,structureContributors);
        } else if (choice == 3) {
            editProject();
        } else if (choice == 4) {
            break;
        } else {
            cout << "Nie ma takiego wyboru!" << endl;
        }
    }
}

/*interfejs zadania*/
void tasksInterface(vector<taskStructure>& taskStructure, vector<structureContributors>& structureContributors) {
    while (true) {
        cout << "ZADANIA\n1. Dodaj zadanie\n2. Usun zadanie\n3. Edytuj zadanie\n4. Menu glowne" << endl;
        const int choice = inputInt("Wybierz opcje: ");
        // obsluga wyboru uzytkownika
        if (choice == 1) {
            addTask(taskStructure);
        } else if (choice == 2) {
            int ID = inputInt("Podaj ID zadania do usuniecia:");
            removeTask(ID, taskStructure, structureContributors);
        } else if (choice == 3) {
            editTask();
        } else if (choice == 4) {
            break;
        } else {
            cout << "Nie ma takiego wyboru!" << endl;
        }
    }
}

/*interfejs czlonkowie*/
void contributorsInterface(vector<structureContributors>& structureContributors,
    vector<taskStructure>& taskStructure) {
    // obsluga wyboru uzytkownika
    while (true) {
        cout << "CZLONKOWIE\n1. Dodaj czlonka\n2. Usun czlonka\n3. Edytuj czlonka\n4. Menu glowne" << endl;
        const int choice = inputInt("Wybierz opcje: ");
        if (choice == 1) {
            addContributor(structureContributors, taskStructure);
        } else if (choice == 2) {
            removeContributor(structureContributors, taskStructure);
        } else if (choice == 3) {
            editContributor();
        } else if (choice == 4) {
            break;
        } else {
            cout << "Nie ma takiego wyboru!" << endl;
        }
    }

}

/*menu glowne*/
void mainMenu(vector<structureProjects>& structureProjects,
    vector<taskStructure>& taskStructure,
    vector<structureContributors>& structureContributors) {
    while (true) {
        cout << "MENU GLOWNE\n1. Projekty\n2. Zadania\n3. Czlonkowie\n4. Koniec" << endl;
        const int choice = inputInt("Wybierz opcje: ");
        // obsluga wyboru uzytkownika
        if (choice == 1) {
            projectsInterface(structureProjects, taskStructure, structureContributors);
        } else if (choice == 2) {
            tasksInterface(taskStructure, structureContributors);
        } else if (choice == 3) {
            contributorsInterface(structureContributors, taskStructure);
        } else if (choice == 4) {
            break;
        } else {
            cout << "Nie ma takiego wyboru!" << endl;
        }
    }
}
