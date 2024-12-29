#ifndef CONTRIBUTORS_H
#define CONTRIBUTORS_H
#include <string>
#include <vector>
using namespace std;

struct structureContributors {
    int ID;
    string name, surname;
    vector<int> tasksToDo, historyOfTasks;
};

#include "tasks.h"


void addContributor(vector<structureContributors>& structure, vector<taskStructure>& taskStruc);
void removeContributor(vector<structureContributors>& structure, vector<taskStructure>& taskStruc);
void reportContributor(vector<structureContributors>& structure);
void editContributor();
void saveContributor(const string& name, vector<structureContributors>& structure);
void readContributors(const string& name, vector<structureContributors>& structure);



#endif //CONTRIBUTORS_H