#include <iostream>
#include <string>

#include "Components.h"

int main() {
    Node node1("abcdefghijklmnopqrstuvwxyz", 1, 2);
    Node node2;

    std::cout << node1.get_name() << ", " << node1.get_working_value() << std::endl;

    node1.set_name("node 1");
    
    node2.set_name("node 2");
    node2.set_working_value(1);

    std::cout << node1.get_name() << ", " << node1.get_working_value() << std::endl;
    std::cout << node1.get_name() << ", " << node2.get_working_value() << std::endl;

    node1 = node2;

    std::cout << node1.get_name() << ", " << node1.get_working_value() << std::endl;

    Network nodes;

    if (node1 == node1){
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    node1.connect(node2);

    std::cout << node1.get_connections()[0] << std::endl;
    std::cout << node2.get_connections()[0] << std::endl;
    
    return 0;
}