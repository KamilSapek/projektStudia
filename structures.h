//
// Created by Kamil on 29/12/2024.
//

#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <string>
#include <vector>
using namespace std;


struct structureContributors {
    int ID;
    std::string name, surname;
    std::vector<int> tasksToDo, historyOfTasks;
};

struct date {
    short day, month, year;
};

struct taskStructure {
    int ID, completionPercentage, status, priority;
    string name, description;
    vector<int> dependencies, contributors;
    date startDate, endDate;
};

struct files {
    std::string projectsFile, tasksFile, contributorsFile;
};

struct structureProjects {
    string name, description;
    int status, ID;
    vector<int> taskList;
    date startDate, endDate;
};


#endif //STRUCTURES_H
