#ifndef PROJECTS_H
#define PROJECTS_H
#include "structures.h"
#include <vector>
using namespace std;

void addProject(vector<structureProjects> &structure, vector<taskStructure> &taskStructure);

void removeProject(vector<structureProjects> &structure, vector<taskStructure> &taskStructure,
                   vector<structureContributors> &structureContributors);

void reportProejct(const vector<structureProjects> &structure, const vector<taskStructure> &taskStruc);

void readProjects(const string &name, vector<structureProjects> &structure);

void saveProjects(const string &name, vector<structureProjects> &structure);

void editProject(vector<structureProjects> &structure, vector<taskStructure> &taskStruc);

void scheme(const vector<structureProjects> &structure);


#endif //PROJECTS_H
