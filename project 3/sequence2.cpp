/*
INVARIANTS OF THE CLASS
 
 1. The items in the sequence can be accessed by the pointer data
    *data is the first element in the sequence and
    *(data + i - 1) is the last element in the sequence.
 
 2. Capacity is the current max element the sequence can hold. The Capacity can change because we are using dynamic memory.
 3.used is define as how much of the sequence is filled up.
 4. current_index is the current index of the sequence.
 if the sequence is empty, then there is no current index.
if the sequence is not empty and current_index > used-1, then there is no valid current index.
 otherwise, the current index is data[current_index]
*/

#include <iostream>
#include <cstdlib> // provides size_t
#include <algorithm>
#include <cassert>
#include "sequence2.h"
using std::copy;

namespace main_savitch_4 {
    
    const sequence::size_type sequence::DEFAULT_CAPACITY;
    
    sequence::sequence(size_type initial_capacity) {
        // this is the constructor
        data = new value_type[initial_capacity];
        capacity = initial_capacity;
        used = 0;
    }
    sequence::sequence(const sequence& source) {
        // this is the copy constructor
        data = new value_type[source.capacity];
        capacity = source.capacity;
        used = source.used;
        copy(source.data, source.data + used, data);
        current_index = source.current_index;
    }
    void sequence::operator =(const sequence& source) {
        // this is the assignment operator
        if (this == &source)
            return;
        /*
        value_type *new_data;
        new_data = new value_type[source.capacity];
        delete [] data;
        data = new_data;
         used = source.used;
        for (int i = 0; i < used; i++) {
            data[i] = source.data[i];
        }
         */
        if (capacity != source.capacity) {
            value_type *new_data;
            new_data = new value_type[source.capacity];
            delete [] data;
            data = new_data;
            capacity = source.capacity;
        }
        used = source.used;
        copy(source.data, source.data + used , data);
        current_index = source.current_index;
    }
    
    sequence::~sequence() {delete [] data;} // Destructor
    
    sequence::size_type sequence::size() const { return used;}
    bool sequence::is_item() const {
        if (used > 0 ) {
            return current_index < used;
        }
        return false;
    }
    void sequence::start() {
        if (size() > 0)
            current_index = 0;
    }
    
    void sequence::advance() {
        assert(is_item());
        ++current_index;
    }
    sequence::value_type sequence::current() const {
        //assert(is_item()); if assert fails then the program halts
        assert(is_item());
        return data[current_index];
    }
    void sequence::resize(size_type new_capacity) {
        value_type *larger_array;
        if (capacity == new_capacity)
            return;
        
        if (new_capacity < used)
            new_capacity = used; // can't allocate less then the current size of the array !!!
        
        larger_array = new value_type[new_capacity];
        copy(data , data + used, larger_array);
        delete [] data;
        data = larger_array;
        capacity = new_capacity;
        }
    
    void sequence::insert(const value_type& entry) {
        if (used == capacity) resize(capacity * 2);
        if (!(is_item())) { current_index = 0 ;}
        for (size_type i = used; i > current_index ; --i) {
            data[i] = data[i-1];
        }
        data[current_index] = entry;
        ++used;
        // shift the array right [not circular]. Entry has to be behind the current_index.
    }
    void sequence::attach(const value_type& entry) {
        if ( used == capacity) resize(capacity * 2);
        if (!(is_item())) { current_index = used;}
        else {
            current_index++;
            for ( size_type i = used; i > current_index ; --i) {
                data[i] = data[i-1];
            }
        }
        data[current_index] = entry;
        ++used;
        // Shift the array right [not circular] entry has to be in front of current_index.
    }
    void sequence::remove_current() {
        assert(is_item());
        for (size_type i = current_index + 1 ; i < used; ++i) {
            data[i-1] = data[i]; // Shift the array left [not circular] entry has to be in the back of current_index
            }
        --used;
        }
    
    // Extra credit for implementing [] , += , +
    sequence::value_type sequence::operator [] (size_type index) const {
        assert(index >= 0 && index < used);
        return data[index];
    }
    void sequence::operator +=(const sequence& addend) {
        if (this == &addend) return;
        if ( size() + addend.size() <= capacity) {
            copy( addend.data , addend.data + addend.used, data + used );
            used += addend.used;
        }
        else {
            resize(used + addend.used);
            copy(addend.data, addend.data + addend.used, data + used );
            used += addend.used;
        }
    }
    sequence operator +(const sequence& s1, const sequence& s2) {
        sequence s3;
        s3 += s1;
        s3 += s2;
        return s3;
        
    }
}


