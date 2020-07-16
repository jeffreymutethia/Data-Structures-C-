/***************
 * implementations for some toolkit functions
 * for the binary_tree_node class
 *
 *******/

// please note the beautiful use of recursion in this function
template <class Item>
void tree_clear(binary_tree_node<Item>*& root_ptr) {
    binary_tree_node<Item>* child;
    if(root_ptr != NULL) {
        child = root_ptr->left();
        tree_clear(child);
        child = root_ptr->right();
        tree_clear(child);
        delete root_ptr;
        root_ptr = NULL;
    }
}

// Count the total number of nodes in a given tree
// hint: use recursion!
template <class Item>
int tree_size(binary_tree_node<Item>* root_ptr) {
    if(root_ptr == NULL){
        return 0;
    }
    else{
        int leftsize = tree_size(root_ptr -> left());
        int rightsize = tree_size(root_ptr -> right());
        return leftsize + rightsize + 1;
    }
    //recursive case above
}

// return the height of the tree (that is, the largest
// distance from the root to a leaf) again, use recursion!
template <class Item>
int tree_height(binary_tree_node<Item>* root_ptr) {
    if(root_ptr == NULL){
        return 0;
    }
    else{
        int leftheight = tree_height(root_ptr -> left());
        int rightheight = tree_height(root_ptr -> right());
        if (leftheight > rightheight){
            return leftheight + 1;
        }
        else{
            return rightheight + 1;
        }
    }
}


// find whether a given tree contains the given data item
template <class Item>
bool tree_contains(binary_tree_node<Item>* root_ptr, const Item& target) {
    if(root_ptr == NULL){
        if (root_ptr -> data() == target){
            return true;
        }
        if (tree_contains(root_ptr -> left(), target) == true){
            return true;
        }
        if (tree_contains(root_ptr -> right(), target) == true){
            return true;
        }
    }   
} 

// print the items in the tree, in a preorder traversal
// (that is, print root, then left, then right)
// again, use recursion
template <class Item>
void print_preorder(binary_tree_node<Item>* root_ptr) {
    if(root_ptr != NULL){
    std::cout << root_ptr -> data() << std::endl;
    print_preorder(root_ptr -> left());
    print_preorder(root_ptr -> right());
}
}

