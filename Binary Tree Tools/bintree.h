/***************
 * bintree.h
 * 
 * template class for a node in a binary tree
 * based off of the book's code
 ***************/

#ifndef BINTREE_H
#define BINTREE_H

#include <cstdlib>

template<class Item>
class binary_tree_node {

    public:
        binary_tree_node(
            const Item& init_data = Item(),
            binary_tree_node* init_left = NULL,
            binary_tree_node* init_right = NULL) {

            data_field = init_data;
            left_field = init_left;
            right_field = init_right;
        }

        // member functions
        Item& data() { return data_field; }
        binary_tree_node*& left() { return left_field; }
        binary_tree_node*& right() { return right_field; }
        void set_data(const Item& new_data) { data_field = new_data; }
        void set_left(const Item& new_left) { left_field = new_left; }
        void set_right(const Item& new_right) { right_field = new_right; }
    
        // const member functions
        const Item& data() const { return data_field; }
        const binary_tree_node* left() const { return left_field; }
        const binary_tree_node* right() const { return right_field; }
        bool is_leaf() const { 
            return (left_field == NULL) && (right_field == NULL); 
        }

    private:
        Item data_field;
        binary_tree_node *left_field;
        binary_tree_node *right_field;

};

template <class Item>
void tree_clear(binary_tree_node<Item>*& root_ptr);

template <class Item>
int tree_size(binary_tree_node<Item>* root_ptr);

template <class Item>
int tree_height(binary_tree_node<Item>* root_ptr);

template <class Item>
bool tree_contains(binary_tree_node<Item>* root_ptr, const Item& target);

template <class Item>
void print_preorder(binary_tree_node<Item>* root_ptr);

#include "bintree.cpp"
#endif
