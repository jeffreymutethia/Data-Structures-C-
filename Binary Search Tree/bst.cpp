/*******
 * bst.cpp
 * 
 * implementations of the functions you are to write
 *
 * Class invariant: root is a pointer to a BST node. BST nodes are either:
 *   1. A leaf 
 *   2. A nonleaf whose left subtree is a BST with values <= this node's data and
 *      whose right subtree is a BST with values > this node's data
 *******/

template <class Item>
void add_helper(bst_node<Item>*& root_ptr, const Item& entry) {
    // outline for a possible helper function for add
    if(root_ptr == NULL){
        //add here
        root_ptr = new bst_node<Item>(entry, NULL, NULL);
    }else if(entry < root_ptr -> data()){
        add_helper(root_ptr -> left(), entry);
    }else{
        add_helper(root_ptr -> right(), entry);
    }
}

// Adds the given entry to this BST, maintaining the class invariant
template <class Item>
void bst<Item>::add(const Item& entry) {
    // code for add here! I recommend building and calling the above helper
    // function if you want to solve this problem with recursion.
    
    //if recursion: use helper function to do all work
    add_helper(root, entry);
    ++count;
    //if iterative: just write a loop in here
    //cursor, while loop, etc.
}

// Checks to see if the given entry is in this BST
template <class Item>
bool bst<Item>::contains(const Item& entry) const {
    //Iterative
    bst_node<Item>* cursor = root;
    while(cursor != NULL){
        if(cursor -> data() == entry){
            return true;
        }
        else if(entry < (cursor -> data())){
            cursor = cursor -> left();
        }
        else{
            cursor = cursor -> right();
        }
}
}
// Removes the given entry from this BST, maintaining the class invariant
template <class Item>
bool remove_helper(bst_node<Item>*& root_ptr, const Item& entry){
    if(root_ptr == NULL){return false;}
    else if(entry < root_ptr -> data()){
        return remove_helper(root_ptr -> left(), entry);
    }
    else if(entry > root_ptr -> data()){
        return remove_helper(root_ptr -> right(), entry);
    }
    else{//found entry
        return true;
    }  
}
template <class Item>
void bst<Item>::remove(const Item& entry) {
    //STEP 1: find entry
    //STEP 2: remove
    if(remove_helper(root, entry)){
        --count;
    }
}
// prints out the items of the tree in an inorder traversal
template <class Item>
void bst<Item>::print_inorder() const {
     bst_node<Item>* cursor = root;
     while(cursor != NULL){
        cursor = cursor -> left();
        std::cout << cursor -> data() << std::endl;
        cursor = cursor -> right();
     }
}
