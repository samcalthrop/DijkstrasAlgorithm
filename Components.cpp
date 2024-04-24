#include "include/Components.h"
#include "include/defs.h"

#include <iostream>

Node::Node() 
    :name(""), 
    order(1), 
    working_value(INF),
    final_value(INF), 
    connections(std::vector<std::string>())
{}

// Node::Node(const Node& n) { }

// Node& Node::operator=(const Node& n){
//     this->name = n.name;
//     this->order = n.order;
//     this->working_value = n.working_value;
//     this->final_value = n.final_value;
//     this->connections = n.connections;

//     return *this;
// }

Node::~Node(){}

void connect(Node node);

void disconnect(Node node);