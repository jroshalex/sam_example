#pragma once
#include <iostream>
using namespace std;

template <typename T>
class BinarySearchTree {
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(T d) : data(d), left(nullptr), right(nullptr) {}
    };
    Node* root;

    Node* insert(Node* node, T value) {
        if (!node) return new Node(value);
        if (value < node->data) node->left = insert(node->left, value);
        else if (value > node->data) node->right = insert(node->right, value);
        return node;
    }
    void inorder(Node* node) const {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
    bool search(Node* node, T value) const {
        if (!node) return false;
        if (node->data == value) return true;
        return (value < node->data) ? search(node->left, value) : search(node->right, value);
    }
public:
    BinarySearchTree() : root(nullptr) {}
    void insert(T value) {
        cout << "Inserting " << value << " into BST...\n";
        root = insert(root, value);
    }
    void displayInorder() const {
        cout << "\nBST (In-order): ";
        inorder(root);
        cout << endl;
    }
    void searchValue(T value) const {
        cout << "Searching " << value << " -> ";
        cout << (search(root, value) ? "Found\n" : "Not Found\n");
    }
};
