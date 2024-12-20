//
// Created by Kamil on 19/12/2024.
//

#include "interface.h"
#include "tasks.h"
#include "projects.h"
#include "contributors.h"
#include "commonFunctions.h"

#include <iostream>
using namespace std;

/*fukcja od wyswietlania opcji wyboru i wybierania*/
int interfaceAndChoice(const string& firstLine, const vector<string>& vector) {
    int iterator = 1;
    cout << firstLine << endl;
    for (const string& i : vector) {
        cout << iterator << ". " << i << endl;
        iterator++;
    }
    int choice = inputInt("Wybierz opcje:", "Wybierz opcje ponownie:");
    return choice;
}

/*interfejs projekty*/
void projectsInterface() {
    while (true) {
        int choice = interfaceAndChoice("PROJEKTY",
        {"Dodaj projekt", "Usun projekt", "Edytuj projekt", "Menu glowne"});
        if (choice == 1) {
            addProject();
        } else if (choice == 2) {
            removeProject();
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
void tasksInterface() {
    vector<taskStructure> taskStructure;
    while (true) {
        int choice = interfaceAndChoice("ZADANIA",
            {"Dodaj zadanie", "Usun zadanie", "Edytuj zadanie", "Menu glowne"});
        if (choice == 1) {
            addTask(taskStructure);
        } else if (choice == 2) {
            removeTask();
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
void contributorsInterface() {
    vector<structureContributors> structureContributors;
    vector<taskStructure> taskStructure;
    while (true) {
        int choice = interfaceAndChoice("CZLONKOWIE",
             {"Dodaj czlonka", "Usun czlonka", "Edytuj czlonka", "Menu glowne"});
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

void mainMenu() {
    while (true) {
        int choice = interfaceAndChoice("Czym chcesz zarzadzac?",
          {"Projekty", "Zadania", "Czlonkowie", "Koniec"});
        if (choice == 1) {
            projectsInterface();
        } else if (choice == 2) {
            tasksInterface();
        } else if (choice == 3) {
            contributorsInterface();
        } else if (choice == 4) {
            break;
        } else {
            cout << "Nie ma takiego wyboru!" << endl;
        }
    }
}
