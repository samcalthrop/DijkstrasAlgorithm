#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <math.h>
#include <string>
#include <vector>
#include <limits>

#include "defs.h"
#include "Functions.h"


class Node {
private:
    std::string name;
    int working_value;
    int final_value;
    int order;

public:
    std::vector<std::string> connections;
    
    // initialise node
    Node(std::string name = "",
        int order = 1,
        int working_value = INF,
        int final_value = INF,
        std::vector<std::string> connections = std::vector<std::string>()) 
    {
        this->name = name;
        this->order = order;
        this->working_value = working_value;
        this->final_value = final_value;
        this->connections = connections;
    }

    Node& operator=(const Node& n);
    virtual ~Node();

    void set_name(std::string n = "") { this->name = n; };
    void set_order(int o) { this->order = o; };
    void set_working_value(int wv) { this->working_value = wv; };
    void set_final_value(int fv) { this->final_value = fv; };
    void set_connections(std::vector<std::string> c) { this->connections = c; };

    inline std::string get_name() { return this->name; };
    inline int get_order() { return this->order; };
    inline int get_working_value() { return this->working_value; };
    inline int get_final_value() { return this->final_value; };
    inline std::vector<std::string> get_connections() { return this->connections; };

    int connect(Node& node);
    int disconnect(Node& node);
};


class Network {
private:
    int num_members;
    std::vector<std::string> members;

public:
    Network() {
        this->members = std::vector<std::string>();
        this->num_members = 0;
    }
    ~Network();
};


#endif