#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <string>
#include <vector>
using namespace std;

struct structureContributors {
    int ID;
    string name, surname;
    vector<int> tasksToDo, historyOfTasks;
};

struct date {
    short day, month, year;
};

struct taskStructure {
    int ID, projectID;
    short completionPercentage, status, priority;
    string name, description;
    vector<int> dependencies, contributors;
    date startDate, endDate;
};

struct files {
    string projectsFile, tasksFile, contributorsFile;
};

struct structureProjects {
    string name, description;
    short status;
    int ID;
    vector<int> taskList;
    date startDate, endDate;
};


#endif //STRUCTURES_H
