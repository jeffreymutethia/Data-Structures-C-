#include "gtest/gtest.h"
#include "sorted_seq.h"

using namespace std;

// nothing really to test, but hopefully they don't crash
// or leak memory :)
TEST(SSeqTest, ConstructorTest) {
    sorted_seq<string> s1;
    EXPECT_TRUE(true);
}

// sequence with nothing in it should have length 0
TEST(SSeqTest, LengthBasic) {
    sorted_seq<string> s1;
    EXPECT_EQ(0, s1.length());
}

// insert things and check length
TEST(SSeqTest, InsertLengthTest) {
    sorted_seq<string> s1;
    EXPECT_EQ(0, s1.length());
    s1.insert("blah");
    EXPECT_EQ(1, s1.length());
    s1.insert("abc");
    EXPECT_EQ(2, s1.length());
    s1.insert("abc");
    EXPECT_EQ(3, s1.length());
    s1.insert("zzz");
    EXPECT_EQ(4, s1.length());
}

// insert things then check that they are there
TEST(SSeqTest, ContainsTest) {
    sorted_seq<string> s1;
    s1.insert("blah");
    s1.insert("abc");
    s1.insert("zzz");
    EXPECT_TRUE(s1.contains("blah"));
    EXPECT_TRUE(s1.contains("zzz"));
    EXPECT_TRUE(s1.contains("abc"));
    EXPECT_FALSE(s1.contains("c"));
    EXPECT_FALSE(s1.contains(""));
    EXPECT_FALSE(s1.contains("foo"));
}

// insert things then check that they are in the proper place
TEST(SSeqTest, IndexOfTest) {
    sorted_seq<string> s1;
    s1.insert("blah");
    s1.insert("abc");
    s1.insert("zzz");
    EXPECT_EQ(0, s1.index("abc"));
    EXPECT_EQ(1, s1.index("blah"));
    EXPECT_EQ(2, s1.index("zzz"));
    EXPECT_EQ(-1, s1.index("foobar"));

}

// insert things then try to remove them then check what happened
TEST(SSeqTest, EraseOneTest) {
    sorted_seq<string> s1;
    s1.insert("blah");
    s1.insert("abc");
    s1.insert("zzz");
    EXPECT_FALSE(s1.erase_one("foo"));
    EXPECT_EQ(3, s1.length());
    
    EXPECT_TRUE(s1.erase_one("abc"));
    EXPECT_EQ(2, s1.length());
    EXPECT_EQ(0, s1.index("blah"));
    EXPECT_EQ(1, s1.index("zzz"));
    EXPECT_EQ(-1, s1.index("abc"));

    s1.insert("aaa");
    EXPECT_EQ(3, s1.length());
    EXPECT_TRUE(s1.erase_one("zzz"));
    EXPECT_EQ(2, s1.length());
    EXPECT_EQ(0, s1.index("aaa"));
    EXPECT_EQ(1, s1.index("blah"));
}

// copy constructor test
TEST(SSeqTest, CopyConstructor) {
    sorted_seq<string> s1;
    s1.insert("blah");
    s1.insert("abc");
    s1.insert("zxy");
    
    sorted_seq<string> s2 = s1;
    EXPECT_EQ(3, s2.length());
    EXPECT_EQ(1, s2.index("blah"));
    
    s1.erase_one("blah");
    EXPECT_EQ(1, s2.index("blah"));
}

// test iterator
TEST(SSeqIteratorTest, BeginTest) {
    sorted_seq<string> s1;
    s1.insert("blah");
    s1.insert("abc");
    s1.insert("zxy");
   
    // can't really test anything, make sure no seg faults
    const_node_iterator<string> it = s1.begin();
    EXPECT_TRUE(true);
}

// test * operator
TEST(SSeqIteratorTest, StarTest) {
    sorted_seq<string> s1;
    s1.insert("blah");
    s1.insert("abc");
    s1.insert("zxy");
    const_node_iterator<string> it = s1.begin();
    EXPECT_EQ("abc", *it);
}

// test ++ prefix operator
TEST(SSeqIteratorTest, PlusPlusTest) {
    sorted_seq<string> s1;
    s1.insert("blah");
    s1.insert("abc");
    s1.insert("zxy");

    const_node_iterator<string> it = s1.begin();
    ++it;
    EXPECT_EQ("blah", *it);
    ++it;
    EXPECT_EQ("zxy", *it);
}

// test ++ postfix operator
TEST(SSeqIteratorTest, TestPlusPlus) {
    sorted_seq<string> s1;
    s1.insert("blah");
    s1.insert("abc");
    s1.insert("zxy");

    const_node_iterator<string> it = s1.begin();
    it++;
    EXPECT_EQ("blah", *it);
    it++;
    EXPECT_EQ("zxy", *it);
}

// test == and != operators
TEST(SSeqIteratorTest, TestEqNeq) {
    sorted_seq<string> s1;
    s1.insert("blah");
    s1.insert("abc");
    s1.insert("zxy");
    const_node_iterator<string> it = s1.begin();
    const_node_iterator<string> it2 = s1.begin();
    EXPECT_TRUE(it == it2);
    ++it;
    EXPECT_TRUE(it != it2);
    EXPECT_TRUE(it != s1.end());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
