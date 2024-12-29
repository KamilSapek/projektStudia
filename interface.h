
#ifndef INTERFACE_H
#define INTERFACE_H
#include <string>
#include "projects.h"
#include "tasks.h"
#include "contributors.h"
using namespace std;

void mainMenu(vector<structureProjects>& structureProjects,
    vector<taskStructure>& taskStructure,
    vector<structureContributors>& structureContributors);

#endif //INTERFACE_H
