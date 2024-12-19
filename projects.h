
#ifndef PROJECTS_H
#define PROJECTS_H
#include <string>
#include <vector>

struct structureProjects {
    std::string name, description, status;
    std::vector<int> taskList, startDate, endDate;
};

void addProject();
void removeProject();
void report();
void readProjects(const char* name, std::vector<structureProjects>& structure);
void saveProjects(const char* name, std::vector<structureProjects>& structure);
void editProject();



#endif //PROJECTS_H
