#include "include/Functions.h"

int find(std::vector<std::string> vec, std::string val) {
    for (int index=0; index<vec.size(); index++) {
        if (vec[index] == val) {
            return index;
        }
    }
    return -1;
}