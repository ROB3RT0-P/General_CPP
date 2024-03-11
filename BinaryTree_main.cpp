#include "BinaryTree.h"

int main() {
    BinaryTree myTree;
    myTree.insert(50);
    myTree.insert(30);
    myTree.insert(70);
    myTree.insert(20);
    myTree.insert(40);
    myTree.insert(60);
    myTree.insert(80);

    std::cout << "Original tree: ";
    myTree.inOrderTraversal();

    myTree.invert();

    std::cout << "Inverted tree: ";
    myTree.inOrderTraversal();

    return 0;
}
