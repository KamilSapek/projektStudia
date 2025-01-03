#ifndef CONTRIBUTORS_H
#define CONTRIBUTORS_H
#include "structures.h"
#include <vector>
using namespace std;


void addContributor(vector<structureContributors> &structure, vector<taskStructure> &taskStruc);

void removeContributor(vector<structureContributors> &structure, vector<taskStructure> &taskStruc);

void reportContributor(const vector<structureContributors> &structure, const vector<taskStructure> &taskStruc);

void editContributor(vector<structureContributors> &structure, vector<taskStructure> &taskStruc);

void saveContributor(const string &name, vector<structureContributors> &structure);

void readContributors(const string &name, vector<structureContributors> &structure);

void contributorLoad(const vector<structureContributors> &structureContributors,
                     const vector<taskStructure> &taskStruc);


#endif //CONTRIBUTORS_H
