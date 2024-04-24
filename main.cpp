#include <iostream>
#include <string>

#include "Components.h"

int main() {
    Node node;
    node.set_name("node 1");

    std::cout << node.get_name() << ", " << node.get_working_value() << std::endl;
    
    return 0;
}