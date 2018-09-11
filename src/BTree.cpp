//
// Created by michael on 18-9-11.
//

#include <cassert>
#include "BTree.h"

BTree::BTree() {

}

void BTree::insert(Node *parent, const int &value) {
    if (parent->value > value) {
        if (parent->left) insert(parent->left, value);
        else {
            auto node = new Node(Node::NODE_TYPE_LEFT, value);
            node->parent = parent;
            parent->left = node;
        }
    } else {
        if (parent->right) insert(parent->right, value);
        else {
            auto node = new Node(Node::NODE_TYPE_RIGHT, value);
            node->parent = parent;
            parent->right = node;

        }
    }
}

Node *BTree::find(Node *parent, const int &value) {
    Node *found = nullptr;

    if (parent) {
        if (parent->value == value) {
            found = parent;
        } else if (parent->value > value) {
            found = find(parent->left, value);
        } else {
            found = find(parent->right, value);
        }
    }

    return found;
}

Node *BTree::findMinNode(Node *root) {
    Node *node = nullptr;
    if (root->isLeaf() || !(root->left)) {
        node = root;
    } else {
        node = findMinNode(root ->left);
    }

    return node;
}

Node *BTree::findMaxNode(Node *root) {
    Node *node = nullptr;
    if (root->isLeaf() || !(root->right)) {
        node = root;
    } else {
        node = findMinNode(root ->right);
    }

    return node;
}

bool BTree::delNode(Node *parent, const int &value) {
    bool deleted = false;

    if (parent) {
        if (parent->value > value) {
            deleted = delNode(parent->left, value);
        } else if (parent->value < value) {
            deleted = delNode(parent->right, value);
        } else if (parent->value == value) {
            // leaf node
            if (!(parent->left) && !(parent->right)) {
                if (parent->nodeType == Node::NODE_TYPE_LEFT) {
                    parent->parent->left = nullptr;
                } else {
                    parent->parent->right = nullptr;
                }
            } else if (parent->left && !(parent->right)) {
                // only has left child
                if (parent->nodeType == Node::NODE_TYPE_LEFT) {
                    parent->parent->left = parent->left;
                } else {
                    parent->parent->right = parent->left;
                }
            } else if (!(parent->left) && parent->right) {
                // only has right child
                if (parent->nodeType == Node::NODE_TYPE_LEFT) {
                    parent->parent->left = parent->right;
                } else {
                    parent->parent->right = parent->right;
                }
            } else {
                // has left and right child
                auto leftMax = findMaxNode(parent->left);
                auto replaceNode = new Node(parent->nodeType, leftMax->value);
                deleted = delNode(parent, leftMax->value);
                assert(deleted);

                replaceNode->left = parent->left;
                replaceNode->right = parent->right;

                if (parent->nodeType == Node::NODE_TYPE_LEFT) {
                    parent->parent->left = replaceNode;
                } else {
                    parent->parent->right = replaceNode;
                }
            }

            delete parent;
            deleted = true;
        }
    }

    return deleted;
}

bool BTree::insert(const int &value) {
    if (!root) {
        root = new Node(Node::NODE_TYPE_ROOT, value);
    }

    Node *exist = find(value);
    bool inserted = false;
    if (!exist) {
        inserted = true;
        insert(root, value);
    }

    return inserted;
}

Node *BTree::find(const int &value) {
    return find(root, value);
}

bool BTree::delNode(const int &value) {
    return delNode(root, value);
}

void BTree::printL2R() {
    printL2R(root);
}

void BTree::printMinddle() {
    printMinddle(root);
}

void BTree::printR2L() {
    printR2L(root);
}

void BTree::printL2R(Node *root) {
    if (root->left) {
        printL2R(root->left);
    }
    root->print();
    if (root->right) {
        printL2R(root->right);
    }
}

void BTree::printMinddle(Node *root) {
    root->print();
    if (root->left) {
        printMinddle(root->left);
    }
    if (root->right) {
        printMinddle(root->right);
    }
}

void BTree::printR2L(Node *root) {
    if (root->right) {
        printR2L(root->right);
    }
    root->print();
    if (root->left) {
        printR2L(root->left);
    }
}

int BTree::height(Node *root) {
    int h = 1;
    if (root) {
        auto l = height(root->left);
        auto r = height(root->right);
        h += (l > r ? l : r);
    }

    return h;
}

int BTree::height() {
    return height(root);
}

BTree::~BTree() {
    if (root) delete root;
}
