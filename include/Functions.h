#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <string>

#include "Components.h"

int find(std::vector<Node>& vec, Node node);
int find(std::vector<Node>& vec, std::string);
bool vec_remove(std::vector<Node>& vec, Node& node);

#endif