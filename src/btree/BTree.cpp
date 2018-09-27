//
// Created by michael on 18-9-25.
//

#include <iostream>
#include <map>
#include "BTree.h"

BTree::BTree(int order): order(order) {
    root = nullptr;
    depth = 0;
}

void BTree::insertKey(BNode *node, int key) {
    bool inserted = false;
    for (int i = 0; i < node->keyCount(); ++i) {
        if (key < node->keyAt(i)) {
            if (node->isLeaf()) {
                node->insert(key);
            } else {
                insertKey(node->leftChild(), key);
            }

            inserted = true;
            break;
        }
    }

    if (!inserted) {
        if (node->isLeaf()) {
            node->insert(key);

            inserted = true;
        } else {
            insertKey(node->rightChild(), key);
        }
    }

    if (inserted && node->needSplit(order)) {
        node->split(order);

        if (node == this->root) {
            depth += 1;
        }
    }
}

void BTree::insertKey(int key) {
    if (!root) {
        root = new BNode();
        root->insert(key);
        depth += 1;
    }

    BNode *exist = BNode::find(root, key);

    if (!exist) {
        insertKey(root, key);
    }
}

bool BTree::delKey(int key) {
    return false;
}

BNode *BTree::findKeyNode(int key) {
    return BNode::find(root, key);
}

int BTree::getDepth() {
    return depth;
}

void printData(BNode *node, std::map<int, std::vector<int>> &data, int level) {
    if (node) {
        for (int i = 0; i < node->keyCount(); ++i) {
            data[level].push_back(node->keyAt(i));
        }

        for (int i = 0; i <= node->keyCount(); ++i) {
            printData(node->childAt(i), data, level + 1);
        }
    }
}

void BTree::print(BNode *node) {
//    std::map<int, std::vector<int>> data;
//
//    for (int i = 0; i < depth; ++i) {
//        data.insert(data.begin(), std::pair<int, std::vector<int>>(i, std::vector()));
//    }
//
//    printData(root, data, 1);
//
//    for (int i = 0; i < depth; ++i) {
//        for (auto it = data.begin(); it != data.end(); ++it) {
//            std::cout << *it << "  ";
//        }
//
//        std::cout << std::endl;
//    }
//    if (node) {
//        // print self
//        for (int i = 0; i < node->keyCount(); ++i) {
//            std::cout << node->keyAt(i) << "  ";
//        }
//
//        std::cout << "   " << std::endl;
//
//        for (int i = 0; i <= node->keyCount(); ++i) {
//            print(node->childAt(i));
//        }
//    }
}

void BTree::print() {
    std::map<int, std::vector<int>> data;

    for (int i = 0; i < depth; ++i) {
        data.insert(data.begin(), std::pair<int, std::vector<int>>(i, std::vector<int>()));
    }

    printData(root, data, 0);

    for (int i = 0; i < depth; ++i) {
        for (int j = (depth - i - 1) * 8 + 1; j > 1; --j) {
            std::cout << " ";
        }

        for (int &it : data[i]) {
            std::cout << it << "   ";
        }

        std::cout << std::endl;
    }
}

BTree::~BTree() {
    delete(root);
}
