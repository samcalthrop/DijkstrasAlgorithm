#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <math.h>
#include <string>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>

#include "defs.h"
#include "Functions.h"


class Node {
private:
    std::string name;
    int working_value;
    int final_value;
    int order;

public:
    std::map<std::string, int> connections; // <node, arc>
    
    // initialise node
    Node(std::string name = "",
        int order = 1,
        int working_value = INF,
        int final_value = INF,
        std::map<std::string, int> connections = std::map<std::string, int>()) 
    {
        this->name = name;
        this->order = order;
        this->working_value = working_value;
        this->final_value = final_value;
        this->connections = connections;
    }

    Node& operator=(const Node& node);
    bool operator==(const Node& node);
    virtual ~Node();

    void set_name(std::string n = "") { this->name = n; };
    void set_order(int o) { this->order = o; };
    void set_working_value(int wv) { this->working_value = wv; };
    void set_final_value(int fv) { this->final_value = fv; };
    void set_connections(std::map<std::string, int> c) { this->connections = c; };

    inline std::string get_name() { return this->name; };
    inline int get_order() { return this->order; };
    inline int get_working_value() { return this->working_value; };
    inline int get_final_value() { return this->final_value; };
    inline std::map<std::string, int> get_connections() { return this->connections; };

    int connect(Node& node, int arc_length);
    int disconnect(Node& node);
    void print_connections();
};


class Network {
private:
    std::vector<Node> members;

public:
    Network();
    ~Network();

    inline int size();
    int add(Node& node);
    int add(std::vector<Node>& nodes);
    int remove(Node& node);
    void print_members();
};


#endif