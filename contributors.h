#ifndef CONTRIBUTORS_H
#define CONTRIBUTORS_H
#include <string>
#include <vector>

struct strucureContributors {
    int ID;
    std::pmr::string name, surname;
    std::vector<int> tasksToDo, historyOfTasks;
};

void addContributor();
void removeContributor();
void reportContributor();
void editContributor();
void saveContributor(const char* name, std::pmr::vector<strucureContributors>& structure);
void readContributors(const char* name, std::pmr::vector<strucureContributors>& structure);



#endif //CONTRIBUTORS_H