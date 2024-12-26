#ifndef COMMONFUNCTIONS_H
#define COMMONFUNCTIONS_H
#include <string>
#include <vector>
using namespace std;

struct files {
    string projectsFile, tasksFile, contributorsFile;
};
vector<int> createVector(string data, char splitter);
string readVector(const vector<int> &vector, char splitter);
string inputString(const string& text);
int inputInt(const string& text);

#endif //COMMONFUNCTIONS_H
