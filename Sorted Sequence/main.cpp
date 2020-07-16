#include "sorted_seq.h"
#include <iostream>

using namespace std;

// This function takes in two sorteq_sequence collections and 
//  uses iterators (and only iterators) to check that all their items are equal
template<class Item>
bool sequence_equal(sorted_seq<Item> s1, sorted_seq<Item> s2) {
    // TODO: Complete this implementation
    
    const_node_iterator<Item> it1 = s1.begin();
    const_node_iterator<Item> it2 = s2.begin();
    while(*it1 != *it2){
        return false;
    }
}

int main() {
    sorted_seq<string> s;
    cout << s.length() << endl;

    s.insert("foo");
    cout << s.length() << endl;

    s.insert("hoo");
    s.insert("pew");
    s.insert("nah");
    s.insert("zoo");
    s.insert("blah");
    s.insert("meh");
    s.insert("aaa");

    sorted_seq<string> s2;
    s2.insert("foo");
    s2.insert("pew");
    s2.insert("zoo");
    s2.insert("nah");
    s2.insert("blah");
    s2.insert("meh");
    s2.insert("hoo");

    const_node_iterator<string> it;
    const_node_iterator<string> it2;
    for(it = s.begin(); it != s.end(); ++it) {
        cout << *it << endl;
    }

    cout << (it == it2) << endl;
    cout << sequence_equal(s, s2) << endl;
}
