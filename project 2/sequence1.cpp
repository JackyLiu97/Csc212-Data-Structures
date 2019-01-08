#include <iostream>
#include <cassert>
#include "sequence1.h"

namespace main_savitch_3 {
    
    const sequence::size_type sequence::CAPACITY;
    
    sequence::sequence() { used = 0; }
        // data[CAPACITY] don't have to initalize it.
       // current_index; there is no current index yet so i think i should just omit it.
    sequence::size_type sequence::size() const { return used;}
    
    void sequence::start() {
        if (size() > 0) { current_index = 0;}
    }
    
    void sequence::advance() {
        if (is_item()){++current_index;}
        else { current_index = used;}
    }
    
    bool sequence::is_item() const {
        if (used > 0) {
        return (current_index < used);
        }
        return false;
    }
        // 99% this is correct
    
    sequence::value_type sequence::current() const {
        assert(is_item());
        return data[current_index];
    }
    
    void sequence::insert(const value_type& entry) {
        assert( size() < CAPACITY);
        if (!(is_item())) { current_index = 0;}
        for (size_type i = used; i > current_index; --i) {
            data[i] = data[i-1];
        }
        data[current_index] = entry;
        ++used;
    }
    
    void sequence::attach(const value_type& entry) {
        assert (size() < CAPACITY);
        if (!(is_item())) { current_index = used;}
        else{
            current_index++;
            for (size_type i = used; i > current_index; --i) {
                data[i] = data[i-1];
            }
        }
        data[current_index] = entry;
        ++used;
    }
    void sequence::remove_current() {
        //if (!(is_item()) { current_index = used;}
        assert(is_item());
        // what if the current_index is at the end of the array???
        /*
        if (current_index == used-1) {
            for ( size_type i = 0; i < current_index; ++i) {
                data[i] = data[i+1];
            }
        }
        else {
         */
        // this is from the textbook I think if current_index is at the front it holds but this doesn't hold if the current_index is at the end.
         // or current_index + 1 // :c
        //++current_index;
        for (size_type i = current_index+1; i < used; ++i) {
            data[i-1] = data[i];
            }
        //--current_index;
        --used;
        }
}




