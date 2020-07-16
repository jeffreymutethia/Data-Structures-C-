/***************
 * Class definition for a binary search tree
 *
 * a bst class uses a pointer to the root bst_node
 * to track all the data in the tree
 *
 *************/

#ifndef BST_H
#define BST_H

#include "bstnode.h"

template <class Item>
class bst {

    public:

        // Constructor
        bst() {
            root = NULL;
            count = 0;
        }

        // Destructor
        ~bst() {
            tree_clear(root);
        }
        
        // four bst functions to implement
        void add(const Item& entry);

        bool contains(const Item& entry) const;

        void print_inorder() const;

        void remove(const Item& entry);

        // get the size (number of data items) of our bst
        size_t size() const { return count; }

    private:

        bst_node<Item>* root;
        size_t count;
};

#include "bst.cpp"
#endif
