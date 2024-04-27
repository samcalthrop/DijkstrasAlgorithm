#include <iostream>

#include "include/Functions.h"
#include "include/Components.h"

int find(std::vector<Node>& vec, Node node) {
    for (int index=0; index<vec.size(); index++) {
        if (vec[index] == node) {
            return index;
        }
    }
    return -1;
}

int find(std::vector<Node>& vec, std::string name) {
    for (int index=0; index<vec.size(); index++) {
        if (vec[index].get_name() == name) {
            return index;
        }
    }
    return -1;
}

bool vec_remove(std::vector<Node>& vec, Node& node) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] == node) {
            std::cout << "node found: " << node.name << std::endl;
            std::cout << "index found: " << i << std::endl;
            vec.erase(vec.begin() + i);
            return true;
        }
    }
    return false;
}