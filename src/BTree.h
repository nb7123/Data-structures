//
// Created by michael on 18-9-11.
//

#ifndef BTREE_BTREE_H
#define BTREE_BTREE_H


#include "Node.h"

class BTree {
private:
    Node *root;
    void insert(Node *parent, const int &value);
    Node *find(Node *parent, const int &value);
    Node *findMinNode(Node *root);
    Node *findMaxNode(Node *root);

    /**
     * delete left leaf
     * situation 1, a simple btree
     *
     **                   X1
     **                /     \
     **               X2      X3
     **             /   \    /   \
     **            X4   X5  X6   X7
     **           /                \
     **          X8               X11
     **            \             /
     **           X12          X13
     *
     * 1-delete node X4(leaf node)
     * delete directly
     *
     * 2-delete node X4/X7(only has left child or right child)
     * let parent node left/right node pointer point X4/X7 only child
     *
     * 3-delete node X2/X3(node has left and right child)
     * 1)find left child tree largest node, replace the delete node
     * 2)delete the largest node parent pointer(here is X5)
     * or
     * 1)find right child tree min node, replace the delete node
     * 2)delete the largest node parent pointer(here is X6)
     *
     * @param parent    root node
     * @param value     delete value
     * @return          true-if delete success, false-node not found
     */
    bool delNode(Node *parent, const int &value);

    void printL2R(Node *root);
    void printMinddle(Node *root);
    void printR2L(Node *root);
    int height(Node *root);

public:
    BTree();

    bool insert(const int &value);
    Node *find(const int &value);
    bool delNode(const int &value);
    void printL2R();
    void printMinddle();
    void printR2L();

    int height();

    ~BTree();
};


#endif //BTREE_BTREE_H
