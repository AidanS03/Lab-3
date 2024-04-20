#include <iostream>
#include <stack>
using namespace std;


struct Node {
    char data;          
    Node* left;         
    Node* right;        

    // Constructor
    Node(char value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to print arithmetic expression using linked-based representation
void printArithmeticExpression(Node* root) {
    if (root) {
        bool needParentheses = false;

        // Check if both children exist and if the current node is * or / and the left child is + or -
        if (root->left && root->right) {
            if (root->data == '*' || root->data == '/') {
                if (root->left->data == '+' || root->left->data == '-') {
                    needParentheses = true;
                }
            }
        }

        // Print opening parentheses if needed
        if (needParentheses)
            cout << "(";

        // Recursively print the left subtree
        printArithmeticExpression(root->left);
        
        // Print the operator at the current node
        cout << root->data;
        
        // Recursively print the right subtree
        printArithmeticExpression(root->right);

        // Print closing parentheses if needed
        if (needParentheses)
            cout << ")";
    }
}

// Function to print arithmetic expression using array-based representation
void printArithmeticExpression(char tree[], int index, int size) {
    if (index < size && tree[index] != '\0') {
        bool needParentheses = false;
        int leftChild = 2 * index + 1; // Calculate the index of the left child
        int rightChild = 2 * index + 2; // Calculate the index of the right child

        // Check if both children of the current node exist in the array
        if (leftChild < size && rightChild < size) {
            // If the operator at the current node is * or / and the left child's operator is + or -, parentheses are needed
            if (tree[index] == '*' || tree[index] == '/') {
                if (tree[leftChild] == '+' || tree[leftChild] == '-') {
                    needParentheses = true;
                }
            }
        }

       
        if (needParentheses)
            cout << "(";

       
        printArithmeticExpression(tree, leftChild, size);
        
       
        cout << tree[index];
        
       
        printArithmeticExpression(tree, rightChild, size);

       
        if (needParentheses)
            cout << ")";
    }
}

int main() {
    // Linked-based representation
    Node* linkedRoot = new Node('+'); // Create a root node with operator '+'
    linkedRoot->left = new Node('*'); // Add left child with operator '*'
    linkedRoot->left->left = new Node('2'); // Add left child of left child with operand '2'
    linkedRoot->left->right = new Node('-'); // Add right child of left child with operator '-'
    linkedRoot->left->right->left = new Node('a'); // Add left child of right child of left child with operand 'a'
    linkedRoot->left->right->right = new Node('1'); // Add right child of right child of left child with operand '1'
    linkedRoot->right = new Node('*'); // Add right child with operator '*'
    linkedRoot->right->left = new Node('3'); // Add left child of right child with operand '3'
    linkedRoot->right->right = new Node('b'); // Add right child of right child with operand 'b'

    cout << "Linked-based representation: ";
    printArithmeticExpression(linkedRoot); // Print the expression using linked-based representation
    cout << endl;

   
    char arrayTree[] = { '+', '*', '2', '-', 'a', '1', '*', '3', 'b' }; // Array representation of the binary tree
    int size = sizeof(arrayTree) / sizeof(arrayTree[0]); // Calculate the size of the array

    cout << "Array-based representation: ";
    printArithmeticExpression(arrayTree, 0, size); // Print the expression using array-based representation
    cout << endl;

    return 0;
}

*/