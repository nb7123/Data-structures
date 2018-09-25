//
// Created by michael on 18-9-25.
//

#include <cassert>
#include "BNode.h"

BNode::BNode() = default;

bool BNode::insert(int key) {
    assert(isLeaf());

    auto inserted = false;

    for (auto it = keys.begin(); it != keys.end(); ++it) {
        if (*it > key) {
            keys.insert(it, key);
            inserted = true;
            break;
        }
    }

    if (!inserted) {
        keys.push_back(key);
    }

    return true;
}

bool BNode::isFull(const int m) {
    if (!isLeaf()) {
        assert(keys.size() + 1 == child.size());
    }

    return keys.size() == m;
}

bool BNode::isLeaf() {
    return false;
}

int BNode::keyCount() {
    return static_cast<int>(keys.size());
}

BNode::~BNode() {

}
