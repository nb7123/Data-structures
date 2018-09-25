#include <iostream>
#include "bstree/BSTree.h"

int main() {
    std::cout << "BTee test..." << std::endl;
    std::cout << "Generate 100 integers..." << std::endl;

    int values[100];

    srand(time(nullptr));

    for (int i = 0; i < 100; ++i) {
        values[i] = static_cast<int>(random());
    }

    std::cout << "Build BTree use the 100 integer values..." << std::endl;

    BSTree bTree = BSTree();

    for (int j = 0; j < 100; ++j) {
        bTree.insert(values[j]);
    }

    std::cout << "Print BTree..." << std::endl;
    std::cout << "Print BTree left to right" << std::endl;
    bTree.printL2R();

    std::cout << "Print BTree right to left" << std::endl;
    bTree.printR2L();

    std::cout << "Print BTree middle" << std::endl;
    bTree.printMinddle();

    auto value = values[random()%100];
    auto found = bTree.find(value);

    std::cout << "Find value: " << value
              << " node info, left child->" << found->left
                 << ", right child->" << found->right
                             << ", node value:" << found->value << std::endl;


    std::cout << "Delete value: " << value << std::endl;

    auto deleted = bTree.delNode(value);
    std::cout << "Delete result: " << deleted << std::endl;

    found = bTree.find(value);
    std::cout << "Find value: " << value
              << ", node info: " << found << std::endl;

    std::cout << "BTree height: " << bTree.getDepth() << std::endl;

    return 0;
}