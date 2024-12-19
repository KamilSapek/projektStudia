
//
// Created by Kamil on 12/9/2024.
//

#ifndef COMMONFUNCTIONS_H
#define COMMONFUNCTIONS_H
#include <string>
#include <vector>

std::vector<int> createVector(std::string data, char splitter);
std::string readVector(const std::vector<int> &vector, char splitter);
int interfaceAndChoice(const std::string& firstLine, const std::vector<std::string>& vector);
std::string createString(std::string text, std::string onErrorText);
int createInt(std::string text, std::string onErrorText);

#endif //COMMONFUNCTIONS_H
