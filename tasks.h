
#ifndef TASKS_H
#define TASKS_H
#include <string>
#include <vector>
using namespace std;

struct taskStructure {
    int ID, completionPercentage, status;
    string name, description, priority;
    vector<int> dependencies, estimatedEndDate, startDate, contributors;
};

#include "contributors.h"



int addTask(vector<taskStructure>& structure);
void removeTask(int ID, vector<taskStructure>& structure, vector<structureContributors>& structureContributors);
void reportTask();
void editTask();
void readTasks(const char* name, vector<taskStructure>& structure);
void saveTasks(const char* name, vector<taskStructure>& structure);


#endif //TASKS_H
