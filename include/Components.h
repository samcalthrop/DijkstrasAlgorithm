#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <math.h>
#include <string>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>

#include "defs.h"


// forward declaration of Arc
class Arc;


class Node {
public:
    int working_value;
    int final_value;
    int order;
    std::string name;
    std::vector<Arc*> connections; // <node, arc_length>
    
    // initialise node
    Node(std::string name = "",
        int order = 1,
        int working_value = INF,
        int final_value = INF,
        std::vector<Arc*> connections = std::vector<Arc*>()) 
    {
        this->name = name;
        this->order = order;
        this->working_value = working_value;
        this->final_value = final_value;
        this->connections = connections;
    }
    
    virtual ~Node();

    Node& operator=(const Node& node);
    bool operator==(const Node& node) const { return this->name == node.name; }

    void set_name(std::string n = "") { this->name = n; };
    void set_order(int o) { this->order = o; };
    void set_working_value(int wv) { this->working_value = wv; };
    void set_final_value(int fv) { this->final_value = fv; };
    void set_connections(std::vector<Arc*> c) { this->connections = c; };

    inline std::string get_name() { return this->name; };
    inline int get_order() { return this->order; };
    inline int get_working_value() { return this->working_value; };
    inline int get_final_value() { return this->final_value; };
    inline std::vector<Arc*> get_connections() { return this->connections; };

    int connect(Node& node, int arc_length);
    int disconnect(Node& node);
    void print_connections();
};


class Network {
public:
    std::vector<Node> members;
    Network();
    ~Network();

    int size();
    int add(Node& node);
    int add(std::vector<Node>& nodes);
    int remove(Node& node);
    void print_members();
    int locate(Node& node);
    inline int locate(std::string name);
};


#endif