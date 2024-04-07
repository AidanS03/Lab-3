#ifndef TREE_ADT_H
#define TREE_ADT_H

#include <iostream>
#include <vector>

using namespace std;

// Node class for general tree
class TreeNode {
public:
    string data;
    vector<TreeNode*> children;

    TreeNode(string value);
    ~TreeNode();
};

// General Tree class
class Tree {
private:
    TreeNode* root;

    void insertRecursive(TreeNode* current, string parentValue, string value);
    void printRecursive(TreeNode* node);

public:
    Tree();
    ~Tree();
    void insert(string parentValue, string value);
    void print();
    
};

TreeNode::TreeNode(string value) {    // Constructor
    data = value;
}

TreeNode::~TreeNode() {// Destructor to delete dynamically allocated memory
    for (TreeNode* child : children) {
        delete child;
    }
}

void Tree::insertRecursive(TreeNode* current, string parentValue, string value) {// Helper function to recursively insert a value into the tree
    if (current->data == parentValue) {
        current->children.push_back(new TreeNode(value));
        return;
    }
    for (TreeNode* child : current->children) {
        insertRecursive(child, parentValue, value);
    }
}

void Tree::printRecursive(TreeNode* node) {    // Helper function to recursively print the tree using depth-first traversal
    if (node == nullptr)
        return;
    cout << node->data << " ";
    for (TreeNode* child : node->children) {
        printRecursive(child);
    }
}

Tree::Tree() {// Constructor
    root = nullptr;
}

Tree::~Tree() {// Destructor to delete dynamically allocated memory
    delete root;
}

void Tree::insert(string parentValue, string value) {// Function to insert a value into the tree
    if (root == nullptr) {
        root = new TreeNode(parentValue);
        root->children.push_back(new TreeNode(value));
        return;
    }
    insertRecursive(root, parentValue, value);
}

void Tree::print() {// Function to print the tree
    printRecursive(root);
    cout << endl;
}

#endif //TREE_ADT_H