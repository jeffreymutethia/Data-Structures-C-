#include "gtest/gtest.h"
#include "table.h"
#include "student.h"
#include <string>
#include <stdlib.h>
#include <vector>

using namespace std;

int simple_id = 0;

student create_basic_student(int increment=1) {
    student s("bobby", "tables #" + simple_id, simple_id);
    simple_id += increment;
    return s;
}

TEST(TableBasic, Constructor) {
    table<student> t;
    EXPECT_TRUE(true);
}

// tests for add function
TEST(TableBasic, Insert) {
    table<student> t;
    EXPECT_EQ(0, t.size());
    t.insert(create_basic_student());
    EXPECT_EQ(1, t.size());
    t.insert(create_basic_student());
    EXPECT_EQ(2, t.size());
    t.insert(create_basic_student());
    EXPECT_EQ(3, t.size());
    t.insert(create_basic_student());
    EXPECT_EQ(4, t.size());
}

TEST(TableBasic, IsPresent) {
    table<student> t;
    simple_id = 0;
    t.insert(create_basic_student());
    t.insert(create_basic_student());
    t.insert(create_basic_student());
    t.insert(create_basic_student());
    EXPECT_TRUE(t.is_present(0));
    EXPECT_TRUE(t.is_present(1));
    EXPECT_TRUE(t.is_present(2));
    EXPECT_TRUE(t.is_present(3));
}

TEST(TableBasic, Find) {
    table<student> t;
    vector<student> vec;
    for(int i = 0; i < 10; i++) {
        student s = create_basic_student();
        t.insert(s);
        vec.push_back(s);
    }

    for(int i = 0; i < 10; i++) {
        student s;
        bool found = false;
        t.find(vec[i].getKey(), found, s);
        EXPECT_TRUE(found);
        EXPECT_EQ(vec[i], s);
    }

    for(int i = 0; i < 50; i++) {
        bool is_used = false;
        for(std::vector<student>::iterator it = vec.begin(); it != vec.end(); it++) {
            if((*it).getKey() == i) { is_used = true; }
        }
        if(! is_used ) {
            student s;
            bool found = true;
            t.find(i, found, s);
            EXPECT_FALSE(found);
        }
    }
}

TEST(TableBasic, Remove) {
    table<student> t;
    std::vector<student> vec;
    for(int i = 0; i < 100; i++) {
        student s = create_basic_student();
        t.insert(s);
        vec.push_back(s);
    }
    EXPECT_EQ(100, t.size());

    int i = 99;
    for(std::vector<student>::iterator it = vec.begin(); it != vec.end(); it++) {
        t.remove((*it).getKey());
        EXPECT_EQ(i, t.size());
        i--;
    }
}


TEST(TableBasic, CollisionHandling) {
    // First, add 300 students to the table, with
    //  non-consecutive id numbers
    table<student> t;
    std::vector<student> vec;
    for(int i = 0; i < 100; i++) {
        EXPECT_EQ(i, t.size());
        student s = create_basic_student(7);
        t.insert(s);
        vec.push_back(s);
    }
    for(int i = 0; i < 100; i++) {
        EXPECT_EQ(i+100, t.size());
        student s = create_basic_student(11);
        t.insert(s);
        vec.push_back(s);
    }
    for(int i = 0; i < 100; i++) {
        EXPECT_EQ(i+200, t.size());
        student s = create_basic_student(5);
        t.insert(s);
        vec.push_back(s);
    }

    // then, double-check is_present and find for all of them
    for(std::vector<student>::iterator it = vec.begin(); it != vec.end(); it++) {
        EXPECT_TRUE(t.is_present((*it).getKey()));
        student s;
        bool found;
        t.find((*it).getKey(), found, s);
        EXPECT_TRUE(found);
        EXPECT_EQ(*it, s);
    }
    
    std::vector<student> newvec;
    // then, remove half of them
    for(int i = 0; i < 300; i++) {
        if(i % 2 == 0) {
            t.remove(vec[i].getKey());
        } else {
            newvec.push_back(vec[i]);
        }
    }

    // then, double-check is_present and find for all of them
    for(std::vector<student>::iterator it = newvec.begin(); it != newvec.end(); it++) {
        EXPECT_TRUE(t.is_present((*it).getKey()));
        student s;
        bool found;
        t.find((*it).getKey(), found, s);
        EXPECT_TRUE(found);
        EXPECT_EQ(*it, s);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
