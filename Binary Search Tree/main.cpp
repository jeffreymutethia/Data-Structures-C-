
#include "bst.h"

int main() {
    bst<int> b;

    b.add(20);
    b.add(30);
    b.add(10);
    b.add(15);
    b.add(22);

    b.print_inorder();


}
