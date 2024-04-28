#include <iostream>

#include "include/Functions.h"
#include "include/Components.h"

// find node by [node object]
int find(std::vector<Node>& vec, Node node) {
    for (int index=0; index<vec.size(); index++) {
        if (vec[index] == node) {
            return index;
        }
    }
    return -1;
}

// find node by [std::string]
int find(std::vector<Node>& vec, std::string name) {
    for (int index=0; index<vec.size(); index++) {
        if (vec[index].get_name() == name) {
            return index;
        }
    }
    return -1;
}

// remove node from `std::vector<Node>`
bool vec_remove(std::vector<Node>& vec, Node& node) {
    int size = vec.size();
    for (size_t i = 0; i < size; ++i) {
        if (vec[i] == node) {
            std::cout << "node to be removed: " << node.name << std::endl;
            std::cout << "index of node to be removed: " << i << std::endl;
            vec.erase(std::remove(vec.begin(), vec.end(), node), vec.end()); // here?
            return true;
        }
    }
    // vec.erase(std::remove(vec.begin(), vec.end(), node), vec.end()); // here?
    return false;
}