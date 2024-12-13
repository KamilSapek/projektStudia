
#ifndef TASKS_H
#define TASKS_H
#include <string>
#include <vector>
using namespace std;

struct taskStructure {
    int ID, completionPercentage;
    string name, description, priority, status;
    vector<int> dependencies, estimatedEndDate, startDate, contributors;
};

void addTask();
void removeTask();
void reportTask();
void editTask();
void readTasks(const char* name, vector<taskStructure>& structure);
void saveTasks(const char* name, vector<taskStructure>& structure);


#endif //TASKS_H
