#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <string>

int find(std::vector<std::string> vec, std::string val) {
    for (int index=0; index<vec.size(); index++) {
        if (vec[index] == val) {
            return index;
        }
    }
    return -1;
}

int find(std::vector<int> vec, int val) {
    for (int index=0; index<vec.size(); index++) {
        if (vec[index] == val) {
            return index;
        }
    }
    return -1;
}

#endif