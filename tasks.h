#ifndef TASKS_H
#define TASKS_H
#include "structures.h"
#include <vector>
using namespace std;

int addTask(vector<taskStructure> &structure, vector<structureProjects> &structProjects, int projectID);

void removeTask(int ID, vector<taskStructure> &structure, vector<structureContributors> &structureContributors,
                vector<structureProjects> &structureProjects, const bool &fromProject);

void reportTask(const vector<taskStructure> &structure, const vector<structureProjects> &structureProjects,
                const vector<structureContributors> &structureContributors);

void editTask(vector<taskStructure> &taskStructure);

void readTasks(const string &name, vector<taskStructure> &structure);

void saveTasks(const string &name, vector<taskStructure> &structure);

#endif //TASKS_H
