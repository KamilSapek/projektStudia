#include "commonFunctions.h"
#include "interface.h"
#include "contributors.h"
#include "projects.h"
#include "tasks.h"
#include <iostream>
using namespace std;

/*szuka parametru podanego w argumencie*/
string findFileName(const int &argc, char *argv[], const char *param) {
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], param) == 0) {
            return argv[i + 1];
        }
    }
    return "";
}

int main(const int argc, char *argv[]) {
    /*sprawdzanie parametrow*/
    if (argc == 0) {
        cout << "Nie podales zadnego parametru" << endl;
        cout << "Do poprawnego korzystania z programu, musisz uzyc parametrow\n"
                "-p [nazwa pliku z danymi do projektow]\n"
                "-z [nazwa pliku z danymi do zadan]\n"
                "-c [nazwa pliku z danymi do czlonkow]" << endl;
    } else if (argc < 7) {
        cout << "Nie podales jakiegos parametru" << endl;
        cout << "Do poprawnego korzystania z programu, musisz uzyc parametrow\n"
                "-p [nazwa pliku z danymi do projektow]\n"
                "-z [nazwa pliku z danymi do zadan]\n"
                "-c [nazwa pliku z danymi do czlonkow]" << endl;
    } else {
        files files = {};
        files.projectsFile = findFileName(argc, argv, "-p");
        files.tasksFile = findFileName(argc, argv, "-z");
        files.contributorsFile = findFileName(argc, argv, "-c");

        vector<structureProjects> structureProjects;
        vector<taskStructure> taskStructure;
        vector<structureContributors> structureContributors;

        readProjects(files.projectsFile, structureProjects);
        readTasks(files.tasksFile, taskStructure);
        readContributors(files.contributorsFile, structureContributors);
        /*uruchomienie interfejsu*/
        mainMenu(structureProjects, taskStructure, structureContributors, files);
        return 0;
    }
}
