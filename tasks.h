
#ifndef TASKS_H
#define TASKS_H
#include "structures.h"
#include <vector>
using namespace std;

void addTask(vector<taskStructure>& structure, vector<structureProjects>& structProjects, int projectID, const bool& fromProject);
void removeTask(int ID, vector<taskStructure>& structure, vector<structureContributors>& structureContributors);
void reportTask();
void editTask(vector<taskStructure> &taskStructure);
void readTasks(const string& name, vector<taskStructure>& structure);
void saveTasks(const string& name, vector<taskStructure>& structure);

#endif //TASKS_H
