#include <iostream>

#include "include/Components.h"
#include "include/Arc.h"
#include "include/Functions.h"


// Node Class -----------------------------------------------------------------
// allows nodes to be equated. NOTE: when node A is set = to node B, node A retains its name
Node& Node::operator=(const Node& node) {
    this->order = node.order;
    this->working_value = node.working_value;
    this->final_value = node.final_value;
    this->connections = node.connections;

    return *this;
}

// desctructor
Node::~Node(){}

// connect to another node in the graph
int Node::connect(Node& node, int arc_length) {

    // if the node is in the `connections` vector, no need to connect
    for (int i=0; i<this->connections.size(); ++i) {
        if (this->connections[i]->node == &node) { 
            // connection failed; nodes are already connected
            return -1;
        }
    }
    // add the nodes to each others' `connections` vectors
    this->connections.push_back(new Arc(&node, arc_length));
    node.connections.push_back(new Arc(this, arc_length));

    // successful connection
    return 0;
}

// disconnect from a node previously connected to
int Node::disconnect(Node& node) {
    
    // using `std::remove_if()` with a lambda function to remove Arc* from `connections`
    auto arcPtr = std::find_if(this->connections.begin(), this->connections.end(), [&](Arc* arc) {
        return arc->node == &node;
    });

    // find the Arc* object corresponding to current node in `connections` of specified node
    if (arcPtr != this->connections.end()) {
        
        std::cout << "this worked" << std::endl;

        // disconnect nodes *from each other*
        this->connections.erase(arcPtr);
        auto nodePtr = std::find_if(node.connections.begin(), node.connections.end(), [&](Arc* arc) {
            return arc->node == this;
        });
        if (nodePtr != node.connections.end()) {
            node.connections.erase(nodePtr);
            return 0;
        }
    }

    // not connected
    return -1;
}

// void Node::print_connections() {
//     std::cout << " -- Connections To " << this->name  << ":"<< std::endl; 
//     for (auto const& [node, arc] : this->connections) {
//         std::cout << "Node: " << node.name << " / " << "Arc-Length: " << arc << std::endl;
//     }
//     if (this->connections.size() == 0) {
//         std::cout << "[ " << this->name <<  " has no connections ]" << std::endl;
//     }
// }

void Node::print_connections() {
    std::cout << " -- Connections To " << this->name  << ":"<< std::endl; 
    for (auto const& a : this->connections) {
        std::cout << "Node: " << a->node->name << " / " << "Arc-Length: " << a->arc << std::endl;
    }
    if (this->connections.size() == 0) {
        std::cout << "[ " << this->name <<  " has no connections ]" << std::endl;
    }
}


// Network Class --------------------------------------------------------------
// initialise network
Network::Network() {
    this->members = std::vector<Node>();
}

Network::~Network(){}

// returns size of network (how many nodes it contains)
int Network::size() {
    return this->members.size();
}

int Network::add(Node& node) {
    for (int i=0; i<this->members.size(); i++) {
        if (this->members[i].get_name() == node.get_name()) {
            std::cout << "> " << node.get_name() <<" already in network" << std::endl;
            return -1;
        }
    }
    this->members.push_back(node);
    return 0;
}

int Network::add(std::vector<Node>& nodes) {
    for (int member=0; member<nodes.size(); member++) {
        add(nodes[member]);
    }
    return 0;
}

// TODOS: make remove work;
// X -iterates through each node `node` is connected to in `connections` -> DONE
// X -calls `.disconnect` on each to remove -> DONE
// -removes `node` from `members` -> not working

int Network::remove(Node& node) {

    // iterate through the vector using subscript notation

    bool found = vec_remove(this->members, node);

    // bool found = false;
    // for (size_t i = 0; i < this->members.size(); ++i) {
        // if (this->members[i] == node) {
            // std::cout << "node found: " << node.name << std::endl;
            // std::cout << "index found: " << i << std::endl;
            // this->members.erase(this->members.begin() + i);
            // found = true;
            // break;
        // }
    // }
    if (!found) {
        return -1;
    }

    // iterate through the remaining nodes and remove the specified node from their connections
    for (Arc* n : node.connections) {
        node.disconnect(*n->node);
    }

    // Print the updated members list
    std::cout << "Updated members list after removal:" << std::endl;
    for (const Node& n : this->members) {
        std::cout << n.name << std::endl;
    }

    return 0; // Node successfully removed
}

void Network::print_members() {
    for (int i=0; i<this->members.size(); i++) {
        std::cout << this->members[i].get_name() << std::endl;
    }
}

int Network::locate(Node& node) {
    return find(this->members, node);
}

inline int Network::locate(std::string name) {
    return find(this->members, name);
}