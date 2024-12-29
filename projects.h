#ifndef PROJECTS_H
#define PROJECTS_H
#include <string>
#include <vector>

#include "commonFunctions.h"
#include "tasks.h"
using namespace std;

struct structureProjects {
    string name, description;
    int status;
    vector<int> taskList;
    date startDate, endDate;
};

void addProject(vector<structureProjects>& structure, vector<taskStructure>& taskStructure);
void removeProject(vector<structureProjects>& structure, vector<taskStructure>& taskStructure, vector<structureContributors>& structureContributors);
void report();
void readProjects(const char* name, vector<structureProjects>& structure);
void saveProjects(const char* name, vector<structureProjects>& structure);
void editProject();



#endif //PROJECTS_H
