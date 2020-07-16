/**************
 * table.h - class for a hash table
 *
 * 
 ********/

#ifndef TABLE_H
#define TABLE_H

#include <cstdlib>

template <class RecordType>
class table {
    public:
        static const std::size_t CAPACITY = 811;

        table() { 
            // constructor body
            used = 0;
            for(int i = 0; i < CAPACITY; i++) {
                data[i] = RecordType("","", NEVER_USED);
            }
        };


        // Modification member functions
        void insert(const RecordType& entry);
        void remove(int key);

        // Constant member functions
        bool is_present(int key) const;
        void find(int key, bool& found, RecordType& result) const;
        std::size_t size() const { return used; }

    private:
        // Constants - used in key field of special records
        static const int NEVER_USED = -1;
        static const int PREVIOUSLY_USED = -2;
        
        // Member vars
        RecordType data[CAPACITY];
        std::size_t used;

        // Helper functions
        std::size_t hash(int key) const;
        std::size_t hash2(int key) const;
        std::size_t next_index(std::size_t index) const;
        void find_index(int key, bool& found, std::size_t& index) const;
        bool never_used(std::size_t index) const;
        bool is_vacant(std::size_t index) const;
    
};

// include the cpp file because of template nonsense
#include "table.cpp"
#endif
