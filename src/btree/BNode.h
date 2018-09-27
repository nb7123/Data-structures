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
    std::vector<BNode*> children;
    /**
     * parent pointer
     */
    BNode *parent;

    bool containKey(int key);

public:
    explicit BNode();
    static BNode *merge(BNode *root);
    bool insert(int key);
    bool needSplit(int order);
    bool needMerge(int order);
    bool isLeaf();
    void split(int order);
    int keyCount();
    static BNode *find(BNode *root, int key);

    int keyAt(int index);
    BNode *childAt(int index);

    int minKey();
    int maxKey();
    BNode *leftChild();
    BNode *rightChild();

    ~BNode();
};


#endif //BTREE_BNODE_H
