#include <iostream>
#include <vector>
#include "tree_ADT.h"

using namespace std;

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
