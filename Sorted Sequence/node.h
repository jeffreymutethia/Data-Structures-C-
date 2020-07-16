#ifndef NODE_H
#define NODE_H

template <class Item>
class node {
    public:
        typedef Item value_type;

        // Constructor
        node(const Item& init_data = Item(), node* init_link=NULL) {
            data_field = init_data;
            link_field = init_link;
        }

        // Modification member functions
        Item& data() { return data_field; }
        node* link() { return link_field; }

        void set_data(const Item& new_data) { data_field = new_data; }
        void set_link(node* new_link) { link_field = new_link; }

        // Const member functions
        const Item& data() const { return data_field; }
        const node* link() const { return link_field; }

    private:
        Item data_field;
        node* link_field;

};

template <class Item>
void list_clear(node<Item>*& head_ptr);

template <class Item>
void list_copy(const node<Item>* source_ptr, 
                node<Item>*& head_ptr, 
                node<Item>*& tail_ptr);

template <class Item>
void list_head_insert(node<Item>*& head_ptr, const Item& entry);

template <class Item>
void list_head_remove(node<Item>*& head_ptr);

template <class Item>
void list_insert(node<Item>* previous_ptr, const Item& entry);

template <class Item>
void list_remove(node<Item>* previous_ptr, const Item& entry);

template <class NodePtr, class Item>
NodePtr list_search(NodePtr head_ptr, const Item& target);

#include "node.template"
#endif
