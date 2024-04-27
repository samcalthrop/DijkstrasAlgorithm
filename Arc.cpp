#include "include/Arc.h"
#include "include/Components.h"

// Arc class ------------------------------------------------------------------
// initialisation of vector
Arc::Arc(Node* node, int arc)
    :node(node), arc(arc)
{}

Arc::Arc(const Arc& a)
    :node(a.node), arc(a.arc)
{}

// equals operator
Arc& Arc::operator=(const Arc& a) {
    node = a.node;
    arc = a.arc;
    return *this;
}

// deconstructor
Arc::~Arc() {}