#include "BinaryTree.h"

BinaryTree::BinaryTree() : root(nullptr) {}

Node* BinaryTree::insertRecursive(Node* current, int value) {
    if (current == nullptr) {
        return new Node(value);
    }

    if (value < current->data) {
        current->left = insertRecursive(current->left, value);
    } else if (value > current->data) {
        current->right = insertRecursive(current->right, value);
    }

    return current;
}

void BinaryTree::inOrderTraversal(Node* current) {
    if (current != nullptr) {
        inOrderTraversal(current->left);
        std::cout << current->data << " ";
        inOrderTraversal(current->right);
    }
}

Node* BinaryTree::invertRecursive(Node* current) {
    if (current == nullptr) {
        return nullptr;
    }

    // Swap the left and right subtrees
    Node* temp = current->left;
    current->left = invertRecursive(current->right);
    current->right = invertRecursive(temp);

    return current;
}

void BinaryTree::insert(int value) {
    root = insertRecursive(root, value);
}

void BinaryTree::inOrderTraversal() {
    inOrderTraversal(root);
    std::cout << std::endl;
}

void BinaryTree::invert() {
    root = invertRecursive(root);
}
