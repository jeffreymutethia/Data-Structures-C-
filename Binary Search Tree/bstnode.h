/***************
 * bintree.h
 * 
 * template class for a node in a binary tree
 * based off of the book's code
 ***************/

#ifndef BSTNODE_H
#define BSTNODE_H

#include <cstdlib>

template<class Item>
class bst_node {

    public:
        bst_node(
            const Item& init_data = Item(),
            bst_node* init_left = NULL,
            bst_node* init_right = NULL) {

            data_field = init_data;
            left_field = init_left;
            right_field = init_right;
        }

        // member functions
        Item& data() { return data_field; }
        bst_node*& left() { return left_field; }
        bst_node*& right() { return right_field; }
        void set_data(const Item& new_data) { data_field = new_data; }
        void set_left(bst_node* new_left) { left_field = new_left; }
        void set_right(bst_node* new_right) { right_field = new_right; }
    
        // const member functions
        const Item& data() const { return data_field; }
        const bst_node* left() const { return left_field; }
        const bst_node* right() const { return right_field; }
        bool is_leaf() const { 
            return (left_field == NULL) && (right_field == NULL); 
        }

    private:
        Item data_field;
        bst_node *left_field;
        bst_node *right_field;

};

template <class Item>
void tree_clear(bst_node<Item>*& root_ptr) {
    if(root_ptr == NULL) { return; }
    tree_clear(root_ptr->left());
    tree_clear(root_ptr->right());
    delete root_ptr;
    root_ptr = NULL;
}

#endif
