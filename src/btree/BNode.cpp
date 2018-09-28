//
// Created by michael on 18-9-25.
//

#include <cassert>
#include <cmath>
#include "BNode.h"

BNode::BNode() = default;;

BNode *BNode::merge(BNode *root) {
    auto left = root->children.front();
    auto right = root->children.back();

    // merge left
    if (left) {
        // delete left children pointer
        root->children.erase(root->children.begin());
        for (auto i = static_cast<int>(left->keys.size() - 1); i >= 0; --i) {
            root->keys.insert(root->keys.begin(), left->keys[i]);
            root->children.insert(root->children.begin(), left->children[i+1]);
        }

        // insert left children left most children pointer
        root->children.insert(root->children.begin(), left->children.front());
    }

    // merge right
    if (right) {
        // delete last pointer
        root->children.pop_back();
        for (auto i = 0; i < right->keys.size(); ++i) {
            root->keys.push_back(right->keys[i]);
            root->children.push_back(right->children[i]);
        }

        // insert right children right most children pointer
        root->children.push_back(right->children.back());
    }

    return root;
}

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

    while (children.size() < keys.size() + 1) {
        children.push_back(nullptr);
    }

    return true;
}

bool BNode::needSplit(const int order) {
    assert(keys.size() + 1 == children.size());

    return keys.size() == order;
}

bool BNode::needMerge(const int order) {
    assert(keys.size() + 1 == children.size());

    return keys.size() < static_cast<int>(std::ceil(order / 2.0f));
}

bool BNode::isLeaf() {
    bool leaf = true;

    for (auto &it : children) {
        if (it != nullptr) {
            leaf = false;
            break;
        }
    }

    return leaf;
}

void BNode::split(int order) {
    assert(needSplit(order));

    if (parent == nullptr) {
        auto *minNode = new BNode();
        auto *maxNode = new BNode();

        minNode->parent = this;
        maxNode->parent = this;

        // middle key
        auto mid = order / 2;

        // split parent node keys to minNode and maxNode
        for (int i = order-1; i > mid; --i) {
            maxNode->keys.insert(maxNode->keys.begin(), keys.back());
            maxNode->children.insert(maxNode->children.begin(), children.back());

            keys.pop_back();
            children.pop_back();
        }
        maxNode->children.insert(maxNode->children.begin(), children.back());
        children.pop_back();

        for (int i = 0; i < mid; ++i) {
            minNode->keys.push_back(keys.front());
            minNode->children.push_back(children.front());

            keys.erase(keys.begin());
            children.erase(children.begin());
        }
        minNode->children.push_back(children.front());
        children.erase(children.begin());

        assert(children.empty());

        for (auto &it : minNode->children) {
            if (it) it->parent = minNode;
        }

        for (auto &it : maxNode->children) {
            if (it) it->parent = maxNode;
        }

        children.push_back(minNode);
        children.push_back(maxNode);
    } else {
        auto *maxNode = new BNode();

        // middle key
        auto mid = order / 2;
        auto midKey = keys[mid];

        // split parent node keys to minNode and maxNode
        for (int i = order-1; i > mid; --i) {
            maxNode->keys.insert(maxNode->keys.begin(), keys.back());
            maxNode->children.insert(maxNode->children.begin(), children.back());

            keys.pop_back();
            children.pop_back();
        }
        maxNode->children.insert(maxNode->children.begin(), children.back());
        children.pop_back();
        keys.pop_back();

        // find self position in parent
        int position = -1;
        for (int i = 0; i < parent->children.size(); ++i) {
            if (parent->children[i] == this) {
                position = i;
                break;
            }
        }

        if (position < 0) {
            children.pop_back();
        }

        assert(position >= 0);

        maxNode->parent = parent;
        for (auto &it : maxNode->children) {
            if (it) it->parent = maxNode;
        }

        parent->keys.insert(parent->keys.begin() + position, midKey);
        parent->children.insert(parent->children.begin()+position+1, maxNode);
    }

    assert(keys.size() + 1 == children.size());
}

int BNode::keyCount() {
    return static_cast<int>(keys.size());
}

bool BNode::containKey(int key) {
    bool found = false;

    for (int &it : keys) {
        if (it == key) {
            found = true;
            break;
        }
    }

    return found;
}

BNode *BNode::find(BNode *root, int key) {
    BNode *found = nullptr;

    if (root) {
        if (root->containKey(key)) {
            found = root;
        }

        if (!found && (*root->keys.begin()) > key) {
            found = find(*root->children.begin(), key);
        }

        if (!found && (root->keys.back()) < key) {
            found = find(root->children.back(), key);
        }
    }

    return found;
}

int BNode::keyAt(int index) {
    assert(index >= 0 && index < keys.size());

    return keys[index];
}

BNode *BNode::childAt(int index) {
    assert(index >= 0 && index < children.size());

    return children[index];
}

int BNode::minKey() {
    return keys.front();
}

int BNode::maxKey() {
    return keys.back();
}

BNode *BNode::leftChild() {
    return children.front();
}

BNode *BNode::rightChild() {
    return children.back();
}

BNode *BNode::getParent() {
    return parent;
}

BNode::~BNode() {
    for (auto &it : children) {
        delete it;
    }
}
