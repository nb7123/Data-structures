//
// Created by michael on 18-9-25.
//

#ifndef BTREE_BNODE_H
#define BTREE_BNODE_H


#include <array>
#include <vector>

class BNode {
private:
    /**
     * stored key array
     */
     std::vector<int> keys;
    /**
     * children pointers
     */
    std::vector<BNode*> child;
    /**
     * parent pointer
     */
    BNode *parent;

public:
    explicit BNode();
    bool insert(int key);
    bool isFull(int m);
    bool isLeaf();
    int keyCount();
    ~BNode();
};


#endif //BTREE_BNODE_H
