#include "include/Functions.h"

#include "Components.h"

int find(std::vector<Node> vec, Node node) {
    for (int index=0; index<vec.size(); index++) {
        if (vec[index] == node) {
            return index;
        }
    }
    return -1;
}