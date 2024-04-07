#include <iostream>
#include <vector>
#include "tree_ADT.h"

using namespace std;

int main() {
    Tree tree;//create tree object

    tree.insert("Paper", "Title");//generate the tree
    tree.insert("Paper", "Abstract");
    tree.insert("Paper", "Chapter 1");
    tree.insert("Paper", "Chapter 2");
    tree.insert("Paper", "Chapter 3");
    tree.insert("Paper", "References");
    tree.insert("Chapter 1", "1.1");
    tree.insert("Chapter 1", "1.2");
    tree.insert("Chapter 2", "2.1");
    tree.insert("Chapter 2", "2.2");
    tree.insert("Chapter 2", "2.3");
    tree.insert("Chapter 3", "3.1");
    tree.insert("Chapter 3", "3.2");

    tree.preorderTraversal(); //use preorder traversal to move through the tree

}
