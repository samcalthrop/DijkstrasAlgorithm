#ifndef ARC_H
#define ARC_H


// forward declaration of Node
class Node;


class Arc {
public:
    Node* node;
    int arc;

    Arc(Node* node, int arc);
    Arc(const Arc& arc);
    Arc& operator=(const Arc& arc);
        
    virtual ~Arc();
};

#endif