#include "gtest/gtest.h"
#include "bintree.h"
#include <string>

using namespace std;

// nothing really to test, but hopefully they don't crash
// or leak memory :)
TEST(BinTree, ConstructorTest) {
    binary_tree_node<string> *r = new binary_tree_node<string>("foo", NULL, NULL);
    EXPECT_TRUE(true);
}

// tests for size function
TEST(BinTree, Size) {
    binary_tree_node<string> *mt = NULL;
    EXPECT_EQ(0, tree_size(mt));
    binary_tree_node<string> *n = new binary_tree_node<string>("foo", NULL, NULL);
    EXPECT_EQ(1, tree_size(n));
    binary_tree_node<string> *n1 = new binary_tree_node<string>("bar", n, NULL);
    EXPECT_EQ(2, tree_size(n1));
    binary_tree_node<string> *n2 = new binary_tree_node<string>("baz", NULL, NULL);
    binary_tree_node<string> *n3 = new binary_tree_node<string>("robot", n1, n2);
    //
    //           robot
    //           /   \
    //         bar   baz
    //         /
    //       foo
    EXPECT_EQ(4, tree_size(n3));

}

TEST(BinTree, TreeHeight) {
    binary_tree_node<string> *mt = NULL;
    EXPECT_EQ(0, tree_height(mt));
    binary_tree_node<string> *n = new binary_tree_node<string>("foo", NULL, NULL);
    EXPECT_EQ(1, tree_height(n));
    binary_tree_node<string> *n1 = new binary_tree_node<string>("bar", n, NULL);
    EXPECT_EQ(2, tree_height(n1));
    binary_tree_node<string> *n2 = new binary_tree_node<string>("baz", NULL, NULL);
    binary_tree_node<string> *n3 = new binary_tree_node<string>("robot", n1, n2);
    //
    //           robot
    //           /   \
    //         bar   baz
    //         /
    //       foo
    EXPECT_EQ(3, tree_height(n3));
}

TEST(BinTree, TreeContains) {
    binary_tree_node<string> *n = new binary_tree_node<string>("foo", NULL, NULL);
    binary_tree_node<string> *n1 = new binary_tree_node<string>("bar", n, NULL);
    binary_tree_node<string> *n2 = new binary_tree_node<string>("baz", NULL, NULL);
    binary_tree_node<string> *n3 = new binary_tree_node<string>("robot", n1, n2);
    EXPECT_TRUE(tree_contains(n3, string("foo")));
    EXPECT_TRUE(tree_contains(n3, string("baz")));
    EXPECT_FALSE(tree_contains(n3, string("hello")));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
