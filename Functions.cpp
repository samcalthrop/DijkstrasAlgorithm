#include "include/Functions.h"

#include "include/Components.h"

int find(std::vector<Node>& vec, Node node) {
    for (int index=0; index<vec.size(); index++) {
        if (vec[index].get_name() == node.get_name()) {
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