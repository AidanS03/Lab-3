#ifndef AI_TREE_H
#define AI_TREE_H

#include <iostream>
#include <vector>

using namespace std;

class RowCol{//class to create an object that holds a row and column value
public:
    int row;
    int col;
};

class TreeNode {// Node class for general tree
public:
    string data;
    int row;
    int col;
    vector<TreeNode*> children;

    TreeNode(string value);
    ~TreeNode();
};

class Tree {// General Tree class
private:
    TreeNode* root;

    void insertRecursive(TreeNode* current, string parentValue, string value);
    void preorderRecursive(TreeNode* node);

public:
    Tree();
    ~Tree();
    void insert(string parentValue, string value);
    void preorderTraversal();
    
};

TreeNode::TreeNode(string value) {    // Constructor
    data = value;
}

TreeNode::~TreeNode() {// Destructor to delete dynamically allocated memory
    for (TreeNode* child : children) {
        delete child;
    }
}

Tree::Tree() {// Constructor
    root = nullptr;
}

Tree::~Tree() {// Destructor to delete dynamically allocated memory
    delete root;
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

void Tree::preorderRecursive(TreeNode* node) {    // Helper function to recursively print the tree using depth-first traversal
    if (node == nullptr)
        return;
    cout << node->data << endl;
    for (TreeNode* child : node->children) {
        preorderRecursive(child);
    }
}

void Tree::insert(string parentValue, string value) {// Function to insert a value into the tree
    if (root == nullptr) {
        root = new TreeNode(parentValue);
        root->children.push_back(new TreeNode(value));
        return;
    }
    insertRecursive(root, parentValue, value);
}

void Tree::preorderTraversal() {// Function to print the tree
    preorderRecursive(root);
    cout << endl;
}



#endif //AI_TREE_H