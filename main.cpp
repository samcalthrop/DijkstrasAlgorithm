#include <iostream>
#include <string>
#include <array>

#include "Components.h"
#include "Functions.h"

int main() {
    Node A, B, C, D, E, F;
    Network network;

    A.set_name("<A>"), B.set_name("<B>"), C.set_name("<C>");
    D.set_name("<D>"), E.set_name("<E>"), F.set_name("<F>");

    B.set_working_value(1);

    std::vector<Node> abc;
    abc.push_back(A), abc.push_back(B), abc.push_back(C), abc.push_back(D);
    std::vector<Node> def;
    def.push_back(D), def.push_back(E), def.push_back(F);
    A.connect(B, 12), A.connect(C, 10);

    network.add(abc);
    // network.print_members();

    A.print_connections();
    std::cout << std::endl;
    B.print_connections();
    std::cout << std::endl;
    C.print_connections();
    std::cout << std::endl;

    // A.disconnect(B);
    network.remove(C);
    std::cout << std::endl;

    A.print_connections();
    std::cout << std::endl;
    B.print_connections();
    std::cout << std::endl;
    C.print_connections();
    std::cout << std::endl;

    network.print_members();
    // for (int i=0; i<=network.size(); i++) {
        // std::cout << network.members[i].get_name() << std::endl;
    // }
    std::cout << network.size() << std::endl;

    
    
    // std::vector<Node> vec = {A, B};

    // std::cout << vec.size() << std::endl;

    // vec.erase(std::remove(vec.begin(), vec.end(), A), vec.end()); <-- this works!!!

    // std::cout << vec.size() << std::endl;
    // for (int i=0; i<vec.size(); i++) {
    //     std::cout << vec[i].name << std::endl;
    // }



    return 0;
}