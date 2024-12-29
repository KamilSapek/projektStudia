#ifndef CONTRIBUTORS_H
#define CONTRIBUTORS_H
#include "structures.h"
#include <vector>
using namespace std;




void addContributor(vector<structureContributors>& structure, vector<taskStructure>& taskStruc);
void removeContributor(vector<structureContributors>& structure, vector<taskStructure>& taskStruc);
void reportContributor(vector<structureContributors>& structure);
void editContributor();
void saveContributor(const string& name, vector<structureContributors>& structure);
void readContributors(const string& name, vector<structureContributors>& structure);



#endif //CONTRIBUTORS_H