#include <iostream>
#include <vector>

using namespace std;

// Node class for general tree
class TreeNode {
public:
    string data;
    vector<TreeNode*> children;

    // Constructor
    TreeNode(string value) {
        data = value;
    }

    // Destructor to delete dynamically allocated memory
    ~TreeNode() {
        for (TreeNode* child : children) {
            delete child;
        }
    }
};

// General Tree class
class Tree {
private:
    TreeNode* root;

    // Helper function to recursively insert a value into the tree
    void insertRecursive(TreeNode* current, string parentValue, string value) {
        if (current->data == parentValue) {
            current->children.push_back(new TreeNode(value));
            return;
        }

        for (TreeNode* child : current->children) {
            insertRecursive(child, parentValue, value);
        }
    }

    // Helper function to recursively print the tree using depth-first traversal
    void printRecursive(TreeNode* node) {
        if (node == nullptr)
            return;

        cout << node->data << " ";
        for (TreeNode* child : node->children) {
            printRecursive(child);
        }
    }

public:
    // Constructor
    Tree() {
        root = nullptr;
    }

    // Function to insert a value into the tree
    void insert(string parentValue, string value) {
        if (root == nullptr) {
            root = new TreeNode(parentValue);
            root->children.push_back(new TreeNode(value));
            return;
        }

        insertRecursive(root, parentValue, value);
    }

    // Function to print the tree
    void print() {
        printRecursive(root);
        cout << endl;
    }

    // Destructor to delete dynamically allocated memory
    ~Tree() {
        delete root;
    }
};

int main() {
    // Creating a general tree
    Tree tree;

    // Inserting values into the tree
    tree.insert("root", "child1");
    tree.insert("root", "child2");
    tree.insert("child1", "grandchild1");
    tree.insert("child1", "grandchild2");
    tree.insert("child2", "grandchild3");
    tree.insert("child2", "grandchild4");

    // Printing the tree
    tree.print();

}
