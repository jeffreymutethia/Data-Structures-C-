/* Author: Jeff Mutethia
Assignment: HW 06: SortedSequence Part 2: Iterators
Date: 04/17/20
*/


#ifndef CONST_NODE_ITERATOR_H
#define CONST_NODE_ITERATOR_H

#include <cstdlib>

template <class Item>
class const_node_iterator : public std::iterator<std::forward_iterator_tag, Item> {

    public:
        // constructor: builds a new const_node_iterator given an initial node
        const_node_iterator(const node<Item>* initial = NULL) {
            current = initial;
        }

        // dereference operator: return the data that current refers to
        const Item& operator*() const { 
            // TODO: Complete this 
            return current -> data();
        }

        // postfix ++ operator: moves current forward one in the linked list, returns 
        //   reference to this
        const_node_iterator& operator ++() {
            // TODO: Complete this 
            current = current -> link();
            return *this; 
        }

        // prefix ++ operator: creates a copy, increments original, returns copy.
        //   This one is done for you as it's weird.
        const_node_iterator operator ++(int) {
            const_node_iterator original(current);
            current = current->link();
            return original;
        }

        // equality: should return true if both iterators have the same current
        bool operator ==(const const_node_iterator other) const {
            // TODO: Complete this 
            return current == other.current;
        }

        // inequality: should return true if iterators have different current
        bool operator !=(const const_node_iterator other) const {
            // TODO: Complete this 
            return current != other.current;
        }

    private:
        const node<Item>* current;

};

#endif
