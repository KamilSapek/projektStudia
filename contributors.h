#ifndef CONTRIBUTORS_H
#define CONTRIBUTORS_H
#include "tasks.h"
#include <string>
#include <vector>

struct structureContributors {
    int ID;
    std::pmr::string name, surname;
    std::vector<int> tasksToDo, historyOfTasks;
};

void addContributor(std::vector<structureContributors>& structure, vector<taskStructure>& taskStruc);
void removeContributor(std::vector<structureContributors>& structure, std::vector<taskStructure>& taskStruc);
void reportContributor(std::vector<structureContributors>& structure);
void editContributor();
void saveContributor(const char* name, std::pmr::vector<structureContributors>& structure);
void readContributors(const char* name, std::pmr::vector<structureContributors>& structure);



#endif //CONTRIBUTORS_H