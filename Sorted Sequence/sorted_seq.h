/******************
 * Header file for a Sorted Sequence class sorted_seq.
 *
 *
 *
 */

#ifndef SORTED_SEQ_H
#define SORTED_SEQ_H

#include <iostream>
#include <cstdlib>
#include "node.h"
#include "const_node_iterator.h"

template <class Item>
class sorted_seq {
    public:

        // Default constructor
        sorted_seq() { head = NULL; count = 0; }

        // copy constructor
        sorted_seq(const sorted_seq& other);

        // destructor
        ~sorted_seq() { list_clear(head); }

        // public methods
        void insert(const Item& entry);
        bool contains(const Item& target);
        int index(const Item& target);
        bool erase_one(const Item& target);

        // iterators -- provide const iterators only because we will not
        // allow clients to alter the data inside of our list
        const_node_iterator<Item> begin() { return const_node_iterator<Item>(head); }
        const_node_iterator<Item> end() { return const_node_iterator<Item>(); }

        // const methods
        size_t length() { return count; }

    private:
        node<Item>* head;
        size_t count;
};

#include "sorted_seq.template"
#endif
