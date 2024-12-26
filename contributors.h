#ifndef CONTRIBUTORS_H
#define CONTRIBUTORS_H
#include "tasks.h"
#include <string>
#include <vector>
using namespace std;

struct structureContributors {
    int ID;
    string name, surname;
    vector<int> tasksToDo, historyOfTasks;
};

void addContributor(vector<structureContributors>& structure, vector<taskStructure>& taskStruc);
void removeContributor(vector<structureContributors>& structure, vector<taskStructure>& taskStruc);
void reportContributor(vector<structureContributors>& structure);
void editContributor();
void saveContributor(vector<structureContributors>& structure);
void readContributors(vector<structureContributors>& structure);



#endif //CONTRIBUTORS_H