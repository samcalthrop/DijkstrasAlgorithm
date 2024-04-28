#include <iostream>
#include <string>
#include <array>

#include "Components.h"
#include "Functions.h"

int main() {
    Node A, B, C, D, E, F, G, H;
    Network network;

    A.set_name("<A>"), B.set_name("<B>"), C.set_name("<C>");
    D.set_name("<D>"), E.set_name("<E>"), F.set_name("<F>");
    G.set_name("<G>"), H.set_name("<H>");

    std::vector<Node> abc;
    abc.push_back(A), abc.push_back(B), abc.push_back(C), abc.push_back(D), abc.push_back(E), abc.push_back(F), abc.push_back(G), abc.push_back(H);
    
    A.connect(B, 4), A.connect(C, 4), A.connect(D, 4), A.connect(E, 4), A.connect(F, 4), A.connect(G, 4), A.connect(H, 4);

    network.add(abc);
    network.print_members();

    for (Node n : network.members) {
        std::cout << &n << std::endl; // all print the same address
    }
    std::cout << &A << ", " << &B << std::endl; // have unique addresses

    A.print_connections();
    std::cout << std::endl;
    B.print_connections();
    std::cout << std::endl;
    C.print_connections();
    std::cout << std::endl;
    D.print_connections();
    std::cout << std::endl;
    E.print_connections();
    std::cout << std::endl;
    F.print_connections();
    std::cout << std::endl;
    
    // D.disconnect(C);
    network.remove(A);
    std::cout << std::endl;

    A.print_connections();
    std::cout << std::endl;
    B.print_connections();
    std::cout << std::endl;
    C.print_connections();
    std::cout << std::endl;
    D.print_connections();
    std::cout << std::endl;
    E.print_connections();
    std::cout << std::endl;
    F.print_connections();
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