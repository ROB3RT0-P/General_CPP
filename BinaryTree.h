#ifndef BINARY_TREE_H

#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

    Node* insertRecursive(Node* current, int value);
    void inOrderTraversal(Node* current);

    // Helper function for inverting the tree
    Node* invertRecursive(Node* current);

public:
    BinaryTree();
    void insert(int value);
    void inOrderTraversal();
    void invert(); // New function for inverting the tree
};

#endif // BINARY_TREE_H
