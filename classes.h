#ifndef BINARYTREE_H
#define BINARYTREE_H

// Node structure for the binary tree
class Node {
public:
    char data;      // Data stored in the node
    Node* left;     // Pointer to the left child node
    Node* right;    // Pointer to the right child node

    // Constructor
    Node(char value) : data(value), left(nullptr), right(nullptr) {}
};

// Binary tree class
class BinaryTree {
private:
    Node* root;     // Pointer to the root node of the tree

public:
    BinaryTree() : root(nullptr) {}

    // Function to set the root of the tree
    void setRoot(Node* node) {
        root = node;
    }

    // Recursive function to evaluate the expression using linked-based representation
    double evaluateExpression(Node* node) {
        if (!node)
            return 0;

        if (!node->left && !node->right)
            return node->data - '0'; // Convert char to int

        double leftValue = evaluateExpression(node->left);
        double rightValue = evaluateExpression(node->right);

        switch (node->data) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            return leftValue / rightValue;
        default:
            return 0;
        }
    }

    // Function to evaluate the expression using linked-based representation
    double evaluateExpression() {
        return evaluateExpression(root);
    }

    // Function to evaluate the expression using array-based representation
    double evaluateExpression(char tree[], int index, int size) {
        if (index >= size || tree[index] == '\0')
            return 0;

        if (2 * index + 1 >= size || tree[2 * index + 1] == '\0')
            return tree[index] - '0'; // Convert char to int

        double leftValue = evaluateExpression(tree, 2 * index + 1, size);
        double rightValue = evaluateExpression(tree, 2 * index + 2, size);

        switch (tree[index]) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            return leftValue / rightValue;
        default:
            return 0;
        }
    }
};

#endif 


