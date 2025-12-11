#pragma once
#include <iostream>
using namespace std;

// A templated Binary Search Tree (BST) class.
// Allows storing and organizing values of any type T
// as long as T supports comparison operators (<, >, ==).
template <typename T>
class BinarySearchTree {

    // ===============================
    // Internal node structure
    // ===============================
    struct Node {
        T data;        // The value stored at this node
        Node* left;    // Pointer to the left child (values < data)
        Node* right;   // Pointer to the right child (values > data)

        // Constructor that initializes a node with given data
        Node(T d) : data(d), left(nullptr), right(nullptr) {}
    };

    // Pointer to the root node of the entire BST.
    Node* root;

    // ============================================================
    // PRIVATE RECURSIVE INSERT FUNCTION
    //
    // Inserts 'value' into the subtree whose root is 'node'.
    // Returns the (possibly new) root of this subtree.
    //
    // This is the classic recursive BST insertion algorithm:
    //   - If subtree is empty → create a new node here.
    //   - If value < current node → insert in left subtree.
    //   - If value > current node → insert in right subtree.
    //   - Duplicate values are ignored (do nothing).
    // ============================================================
    Node* insert(Node* node, T value) {
        // Base case: found an empty spot → create a new node here.
        if (!node) return new Node(value);

        // Recur down the appropriate branch:
        if (value < node->data)
            node->left = insert(node->left, value);   // insert into left subtree
        else if (value > node->data)
            node->right = insert(node->right, value); // insert into right subtree
        // If value == node->data, we do nothing (BSTs often ignore duplicates)

        return node; // Return this node to keep tree links intact
    }

    // ============================================================
    // PRIVATE RECURSIVE IN-ORDER TRAVERSAL
    //
    // Traversal order: LEFT → NODE → RIGHT
    // This prints values in ascending order for a BST.
    // ============================================================
    void inorder(Node* node) const {
        if (!node) return;                 // Base case: reached empty child

        inorder(node->left);               // Visit left subtree
        cout << node->data << " ";         // Process current node
        inorder(node->right);              // Visit right subtree
    }

    // ============================================================
    // PRIVATE RECURSIVE SEARCH FUNCTION
    //
    // Returns true if 'value' is found in the subtree rooted at 'node'.
    // Uses BST property to decide which direction to recurse.
    // ============================================================
    bool search(Node* node, T value) const {
        if (!node) return false;           // Value not found (empty subtree)
        if (node->data == value) return true; // Value found at current node

        // If value is smaller → search left subtree
        // Else search right subtree.
        return (value < node->data)
            ? search(node->left, value)
            : search(node->right, value);
    }

public:

    // Constructor initializes an empty tree
    BinarySearchTree() : root(nullptr) {}

    // PUBLIC INSERT:
    // Calls the recursive function and updates the root.
    void insert(T value) {
        cout << "Inserting " << value << " into BST...\n";
        root = insert(root, value);
    }

    // PUBLIC IN-ORDER DISPLAY:
    // Simply prints the entire BST in sorted order.
    void displayInorder() const {
        cout << "\nBST (In-order): ";
        inorder(root);
        cout << endl;
    }

    // PUBLIC SEARCH:
    // Prints "Found" or "Not Found" depending on result.
    void searchValue(T value) const {
        cout << "Searching " << value << " -> ";
        cout << (search(root, value) ? "Found\n" : "Not Found\n");
    }
};
