#include <iostream>

#include "include/Components.h"
#include "include/Functions.h"

// Node Class ------------------------------------------------

// allows nodes to be equated. NOTE: when node A is set = to node B, node A retains its name
Node& Node::operator=(const Node& node) {
    this->order = node.order;
    this->working_value = node.working_value;
    this->final_value = node.final_value;
    this->connections = node.connections;

    return *this;
}

bool Node::operator==(const Node& node) {
    // returns true only if they share the same address in memory
    return (&node == this);
}

// desctructor
Node::~Node(){}

// connect to another node in the graph
int Node::connect(Node& node, int arc_length) {

    // searches for `node`'s name in `this`'s `connections` map
    std::map<std::string, int>::iterator iterator = this->connections.find(node.name);
    
    // if the node is in the `connections` vector, no need to connect
    if (iterator != this->connections.end()) { 
        // connection failed; nodes are already connected
        return -1;
    }

    // add the nodes to each others' `connections` vectors
    this->connections.insert(std::pair<std::string, int>(node.get_name(), arc_length));
    node.connections.insert(std::pair<std::string, int>(this->get_name(), arc_length));

    // successful connection
    return 0;
}

// disconnect from a node previously connected to
int Node::disconnect(Node& node) {
    
    // searches for `node`'s name in `this`'s `connections` map
    std::map<std::string, int>::iterator iterator = this->connections.find(node.name);
    
    // if the node is in the vector, removes the node from it, and removes `this` from `node`'s
    // `connections` vector aswell (handshake lemma means the connection goes both ways)
    if (iterator != this->connections.end()) { 
        this->connections.erase(iterator); 
        node.connections.erase(this->name);
        // successful disconnection
        return 0; 
    }
    // disconnect failed; nodes weren't connected before hand
    return -1;
}

void Node::print_connections() {
    std::cout << " -- Connections To " << this->name  << ":"<< std::endl; 
    for (auto const& [node, arc] : this->connections) {
        std::cout << "Node: " << node << " / " << "Arc-Length: " << arc << std::endl;
    }
    if (this->connections.size() == 0) std::cout << "[ " << this->name <<  " has no connections ]" << std::endl;
}


// Network Class ---------------------------------------------

// initialise network
Network::Network() {
    this->members = std::vector<Node>();
}

Network::~Network(){}

// returns size of network (how many nodes it contains)
inline int Network::size() {
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
}

int Network::remove(Node& node) {
    // if node is in `members`, aka is in the network...
    // find the node in `members` and disconnect from `node`
    return -1;
}

void Network::print_members() {
    for (int i=0; i<this->members.size(); i++) {
        std::cout << this->members[i].get_name() << std::endl;
    }
}

inline int Network::locate(Node& node) {
    return find(this->members, node);
}

inline int Network::locate(std::string name) {
    return find(this->members, name);
}