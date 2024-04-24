#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <math.h>
#include <string>
#include <vector>
#include <limits>


class Node {
    private:
        std::string name;
        int order;
        int working_value;
        int final_value;
        std::vector<std::string> connections;

    public:
        Node();
        // Node(const Node& n);
        // Node& operator=(const Node& n);
        virtual ~Node();

        void set_name(std::string n) { name = n; };
        void set_order(int o) { order = o; };
        void set_working_value(int wv) { working_value = wv; };
        void set_final_value(int fv) { final_value = fv; };
        void set_connections(std::vector<std::string> c) { connections = c; };

        inline std::string get_name() { return name; };
        inline int get_order() { return order; };
        inline int get_working_value() { return working_value; };
        inline int get_final_value() {return final_value; };
        inline std::vector<std::string> get_connections() { return connections; };

        void connect(Node node);
        void disconnect(Node node);
};

#endif