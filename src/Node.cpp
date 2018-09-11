//
// Created by michael on 18-9-11.
//

#include <iostream>
#include "Node.h"

void Node::print() {
    std::cout << value << std::endl;
}

int Node::NODE_TYPE_LEFT = 0;
int Node::NODE_TYPE_RIGHT = 1;
int Node::NODE_TYPE_ROOT = 2;

Node::Node(int type, int value) {
    left = nullptr;
    right = nullptr;
    this->value = value;
    this->nodeType = type;
}

Node::~Node() {
    delete(left);
    delete(right);
    std::cout << "Delete node: " << value << std::endl;
}

bool Node::isLeaf() {
    return left == nullptr && right == nullptr;
}
