//
// Created by michael on 18-9-25.
//

#ifndef BTREE_BTREE_H
#define BTREE_BTREE_H


#include "BNode.h"

class BTree {
private:
    BNode *root;
    int depth;
    int order;
    void insertKey(BNode *node, int key);

    void print(BNode *node);

public:
    explicit BTree(int order);

    void insertKey(int key);
    bool delKey(int key);
    BNode *findKeyNode(int key);
    int getDepth();

    void print();

    ~BTree();
};


#endif //BTREE_BTREE_H
