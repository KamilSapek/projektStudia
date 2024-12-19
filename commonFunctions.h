
//
// Created by Kamil on 12/9/2024.
//

#ifndef COMMONFUNCTIONS_H
#define COMMONFUNCTIONS_H
#include <string>
#include <vector>

std::vector<int> createVector(std::string data, char splitter);
std::string readVector(const std::vector<int> &vector, char splitter);
std::string inputString(const std::string& text, const std::string& onErrorText);
int inputInt(const std::string& text, const std::string& onErrorText);

#endif //COMMONFUNCTIONS_H
