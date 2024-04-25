#include <iostream>
#include <string>

#include "Components.h"

int main() {
    Node A, B, C, D;

    A.set_name("<A>");
    B.set_name("<B>");
    C.set_name("<C>");
    D.set_name("<D>");

    B.set_working_value(1);

    Network Nodes;

    A.connect(B, 12);
    std::map<std::string, int> node1_connections = A.get_connections();

    std::vector<Node> abc;
    abc.push_back(A);
    abc.push_back(B);
    abc.push_back(C);

    Nodes.add(abc);
    Nodes.add(A);
    Nodes.add(B);
    Nodes.print_members();

    A.print_connections();
    B.print_connections();
    C.print_connections();

    A.disconnect(B);

    A.print_connections();
    B.print_connections();
    C.print_connections();

    return 0;
}