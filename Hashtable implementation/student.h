/****** 
 * student.h
 *
 * struct for a student object
 * student id is key
 *
 *****/

#include <string>

class student {
    public:
        student(std::string first="",
                std::string last="",
                int initid = -1) {
            firstname = first;
            lastname = last;
            id = initid;
        }

        // const member functions
        std::string getFirst() const { return firstname; }
        std::string getLast() const { return lastname; }
        int getID() const { return id; }
        size_t getKey() const { return id; }

        void setFirst(const std::string& newfirst) { firstname = newfirst; }
        void setLast(const std::string& newlast) { lastname = newlast; }
        void setID(int newid) { id = newid; }
    private:
        std::string firstname;
        std::string lastname;
        int id; 
};

bool operator==(student s1, student s2) {
    return s1.getID() == s2.getID();
}
