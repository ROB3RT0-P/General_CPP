#include <iostream>

// Define a node for the binary tree
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to insert a node into the binary tree
TreeNode* insert(TreeNode* root, int val) {
    if (!root) {
        return new TreeNode(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

void inorderTraversal(TreeNode* root) {
    if (root) {
        inorderTraversal(root->left);
        std::cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

TreeNode* reverseBinaryTree(TreeNode* root) {
    if (!root) {
        return nullptr;
    }

    // Swap left and right subtrees recursively
    TreeNode* temp = root->left;
    root->left = reverseBinaryTree(root->right);
    root->right = reverseBinaryTree(temp);

    return root;
}

int main() {
    TreeNode* root = nullptr;
    root = insert(root, 4);
    insert(root, 2);
    insert(root, 1);
    insert(root, 3);
    insert(root, 6);
    insert(root, 5);
    insert(root, 7);

    std::cout << "Original Binary Tree (inorder traversal): ";
    inorderTraversal(root);
    std::cout << std::endl;

    root = reverseBinaryTree(root);

    std::cout << "Reversed Binary Tree (inorder traversal): ";
    inorderTraversal(root);
    std::cout << std::endl;

    return 0;
}
