#include "bintree.h"

#include <iostream>
using namespace std;

int main() {
    


    binary_tree_node<string>* n1 = new binary_tree_node<string>("blah");
    binary_tree_node<string>* n2 = new binary_tree_node<string>("m");
    binary_tree_node<string>* n3 = new binary_tree_node<string>("q", n1, n2);
    binary_tree_node<string>* n4 = new binary_tree_node<string>("zzz");
    binary_tree_node<string>* root = new binary_tree_node<string>("foo", n3, n4);

    cout << root->data() << endl;

    cout << "printing in preorder traversal: " << endl;
    print_preorder(root);
}
