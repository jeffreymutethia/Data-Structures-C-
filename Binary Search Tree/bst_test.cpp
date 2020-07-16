#include "gtest/gtest.h"
#include "bst.h"
#include <string>

using namespace std;

// nothing really to test, but hopefully they don't crash
TEST(BST, Constructor) {
    bst<double> b;
    EXPECT_TRUE(true);
}

// tests for add function
TEST(BST, Add) {
    bst<double> b;
    EXPECT_EQ(0, b.size());
    b.add(5.5);
    EXPECT_EQ(1, b.size());
    b.add(8.2);
    EXPECT_EQ(2, b.size());
    b.add(11.4);
    EXPECT_EQ(3, b.size());
    b.add(1.2);
    EXPECT_EQ(4, b.size());

}

TEST(BST, Contains) {
    bst<int> b;
    b.add(55);
    b.add(82);
    b.add(114);
    b.add(12);
    EXPECT_TRUE(b.contains(12));
    EXPECT_TRUE(b.contains(55));
    EXPECT_TRUE(b.contains(82));
    EXPECT_TRUE(b.contains(114));
    EXPECT_FALSE(b.contains(100));
    EXPECT_FALSE(b.contains(68));
    EXPECT_FALSE(b.contains(5));
    EXPECT_FALSE(b.contains(13));
    EXPECT_FALSE(b.contains(200));
}

TEST(BST, Remove) {
    bst<int> b;
    b.add(55);
    b.add(82);
    b.add(114);
    b.add(12);
    b.add(13);
    b.add(10);
    b.add(61);
    // remove 55, then check to see if everything else still there
    b.remove(55);
    EXPECT_EQ(6, b.size());
    EXPECT_TRUE(b.contains(10));
    EXPECT_TRUE(b.contains(12));
    EXPECT_TRUE(b.contains(13));
    EXPECT_TRUE(b.contains(61));
    EXPECT_TRUE(b.contains(82));
    EXPECT_TRUE(b.contains(114));
    // remove 10, check to see if everything else still there
    b.remove(10);
    EXPECT_EQ(5, b.size());
    EXPECT_TRUE(b.contains(12));
    EXPECT_TRUE(b.contains(13));
    EXPECT_TRUE(b.contains(61));
    EXPECT_TRUE(b.contains(82));
    EXPECT_TRUE(b.contains(114));
    // remove 114, etc.
    b.remove(114);
    EXPECT_EQ(4, b.size());
    EXPECT_TRUE(b.contains(12));
    EXPECT_TRUE(b.contains(13));
    EXPECT_TRUE(b.contains(61));
    EXPECT_TRUE(b.contains(82));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
