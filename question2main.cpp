#include <iostream>
#include "classes.h" // Include the header file for the BinaryTree class

using namespace std;

int main() {
    // Create a binary tree object
    BinaryTree tree;

    // Linked-based representation
    Node* linkedRoot = new Node('+'); // Create a root node with operator '+'
    linkedRoot->left = new Node('*'); // Add left child with operator '*'
    linkedRoot->left->left = new Node('2'); // Add left child of left child with operand '2'
    linkedRoot->left->right = new Node('-'); // Add right child of left child with operator '-'
    linkedRoot->left->right->left = new Node('5'); // Add left child of right child of left child with operand '5'
    linkedRoot->left->right->right = new Node('1'); // Add right child of right child of left child with operand '1'
    linkedRoot->right = new Node('*'); // Add right child with operator '*'
    linkedRoot->right->left = new Node('3'); // Add left child of right child with operand '3'
    linkedRoot->right->right = new Node('2'); // Add right child of right child with operand '2'

    // Set the root of the tree
    tree.setRoot(linkedRoot);

    // Evaluate the expression using linked-based representation
    cout << "Result (Linked-based representation): " << tree.evaluateExpression() << endl;

    // Array-based representation
    char arrayTree[] = { '+', '*', '*', '2', '-', '3', '2', '\0', '\0', '5', '1', '\0' }; // Array representation of the binary tree
    int size = sizeof(arrayTree) / sizeof(arrayTree[0]); // Calculate the size of the array

    // Evaluate the expression using array-based representation
    cout << "Result (Array-based representation): " << tree.evaluateExpression(arrayTree, 0, size) << endl;

    return 0;
}
