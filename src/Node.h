//
// Created by michael on 18-9-11.
//

#ifndef BTREE_NODE_H
#define BTREE_NODE_H


class Node {
public:
    static int NODE_TYPE_LEFT;
    static int NODE_TYPE_RIGHT;
    static int NODE_TYPE_ROOT;

    Node(int type, int value);

    Node *parent;
    Node *left;
    Node *right;
    int value;
    int nodeType;

    void print();
    bool isLeaf();

    ~Node();
};


#endif //BTREE_NODE_H
