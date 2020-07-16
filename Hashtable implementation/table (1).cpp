/**************
 * table.cpp - class for a hash table
 *
 * 
 ********/

template <class RecordType>
void table<RecordType>::insert(const RecordType& entry) {
    bool found;
    size_t index = hash(entry.getKey());
    find_index(entry.getKey(), found, index);
    if (found){
        index = hash2(entry.getKey());
    }
    data[index] = entry;
    ++used;
}
template <class RecordType>
void table<RecordType>::remove(int key) {
    //lool at index hash(key)
    //to remove...replace with RecordType(**, **, PREVIOUSLY_USED)
    bool found;
    size_t index = hash(key);
    find_index(key, found, index);
    if(found)
    {
        key = PREVIOUSLY_USED;
        --used;
    }
}
template <class RecordType>
bool table<RecordType>::is_present(int key) const {
    bool found;
    size_t index = hash(key); //If key exists, it will be in data[i].
    //look at that index, if something is there, return true
    assert(key >= 0);
    find_index(key, found, index);
    if(found){
        return true;
    }
    else{
        size_t new_index = hash2(key);
        find_index(key, found, new_index);
        if(found){
            return true;
        }  
    }
    return false;
}

template <class RecordType>
void table<RecordType>::find(int key, bool& found, RecordType& result) const {
    //look at index hash(key)
    //use reference variables found and result to report answers
    size_t index = hash(key);
    find_index(key, found, index);
    if(found){
        result = data[index];
    }
}

// Helper functions
template <class RecordType>
std::size_t table<RecordType>::hash(int key) const {
    return key % CAPACITY;
}

template <class RecordType>
std::size_t table<RecordType>::hash2(int key) const {
    return 1 + (key % (CAPACITY - 2));
}
template <class RecordType>
void table<RecordType>::find_index(int key, bool& found, std::size_t& index) const {
    index = hash(key);
    while(key != data[index].getKey()){
        index++; //need to wrap around
        if(data[index].getKey() == NEVER_USED){
            found = false;
            return;
        }
    }
    found = true;
}