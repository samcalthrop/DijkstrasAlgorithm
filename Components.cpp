#include "include/Components.h"
#include "include/defs.h"
#include "include/Functions.h"

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

// connect to another node in the graph
int Node::connect(Node& node) {

    // searches for `node`'s name in `this`'s `connections` vector
    auto iterator = std::find(
        this->connections.begin(), 
        this->connections.end(), 
        node.get_name()
    );
    
    // if the node is in the `connections` vector, no need to connect
    if (iterator != this->connections.end()) { 
        // connection failed; nodes are already connected
        return -1;
    }

    // add the nodes to each others' `connections` vectors
    this->connections.push_back(node.get_name());
    node.connections.push_back(this->get_name());

    // successful connection
    return 0;
}

// disconnect from a node previously connected to
int Node::disconnect(Node& node) {
    
    // searches for `node`'s name in `this`'s `connections` vector
    auto iterator = std::find(
        this->connections.begin(), 
        this->connections.end(), 
        node.get_name()
    );
    
    // if the node is in the vector, removes the node from it, and removes `this` from `node`'s
    // `connections` vector aswell (handshake lemma means the connection goes both ways)
    if (iterator != this->connections.end()) { 
        this->connections.erase(iterator); 
        node.connections.erase(
            std::find(
                node.connections.begin(),
                node.connections.end(),
                this->get_name()
            )
        );
        // successful disconnection
        return 0; 
    }
    // disconnect failed; nodes weren't connected before hand
    return -1;
}