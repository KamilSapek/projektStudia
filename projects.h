#ifndef PROJECTS_H
#define PROJECTS_H
#include <string>
#include <vector>
using namespace std;

struct structureProjects {
    string name, description, status;
    vector<int> taskList, startDate, endDate;
};

void addProject();
void removeProject();
void report();
void readProjects(const char* name, vector<structureProjects>& structure);
void saveProjects(const char* name, vector<structureProjects>& structure);
void editProject();



#endif //PROJECTS_H
