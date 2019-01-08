/*
 INVARIANTS OF THE CLASS
 
 1. The items in the sequence are stored in a link list
 
 2. node *head_ptr is the head pointer that points to the first element of the link list.
 if the sequence is empty then head_ptr points to NULL.

 3.node *tail_ptr is the tail pointer that points to the last element of the link list.
 if the sequence is empty then tail_ptr points to NULL.
 
 4.node *cursor is the pointer that points to the current node.
 if cursor doesn't points to the current node then cursor points to NULL.
 
 5.node *precursor is the pointer follows behind cursor. precursor is always one node behnind the cursor pointer.
 if there is no current node or cursor points to the first item in the sequence then precursor is NULL.
 
 6. many_nodes tells us the size of the link list so far.
 */


#include <iostream>
#include <cstdlib> // provides size_t
#include <cassert> // provides assert
#include "sequence3.h"

namespace main_savitch_5 {
    
    sequence::sequence() {
        // constructor
        head_ptr = NULL;
        tail_ptr = NULL;
        precursor = NULL;
        cursor = NULL;
        many_nodes = 0;
    }
    
    sequence::sequence(const sequence& source) {
        // Run Time Analysis: Linked List - O(n)
        // Rune Time Analysis: Dynamic array - O(n)
        // this is the copy constructor
        // we have to find the precursor and cursor by going through the source link list
        // we can't do precursor = source.precursor and cursor = source.cursor because that would be the address of the
        // other link list and not the new one you're making.
        list_copy(source.head_ptr,head_ptr,tail_ptr);
        precursor = NULL;
        cursor = head_ptr;
        many_nodes = source.many_nodes;
        node *traverse = source.head_ptr;
        while (traverse != NULL && traverse != source.cursor) {
            traverse = traverse->link();
            advance();
        }
    }
    
    void sequence::operator =(const sequence& source) {
        // Run Time Analysis: Linked List - O(n)
        // Rune Time Analysis: Dynamic array - O(n)
        // this is the assignment operator
        // we have to find the precursor and cursor by going through the source link list
        // we can't do precursor = source.precursor and cursor = source.cursor because that would be the address of the
        // other link list and not the new one you're making.
        if (this == &source)
            return;
        list_clear(head_ptr);
        list_copy(source.head_ptr, head_ptr, tail_ptr);
        many_nodes = source.many_nodes;
        precursor = NULL;
        cursor = head_ptr;
        node *traverse = source.head_ptr;
        while(traverse != NULL && traverse != source.cursor) {
            traverse = traverse->link();
            advance();
        }
    }
    
    sequence::~sequence() {
        // Run Time Analysis: Linked List - O(n)
        // Rune Time Analysis: Dynamic array - (1)
        list_clear(head_ptr);
        many_nodes = 0;
    }
    
    size_t sequence::size() const { return many_nodes;}
    // Run Time Analysis: Linked List - O(1)
    // Rune Time Analysis: Dynamic array - O(1)
    
    void sequence::start() {
        // Run Time Analysis: Linked List - O(1)
        // Rune Time Analysis: Dynamic array - (1)
        precursor = NULL;
        cursor = head_ptr;
    }
    
    bool sequence::is_item() const {
        // Run Time Analysis: Linked List - O(1)
        // Rune Time Analysis: Dynamic array - (1)
        if (many_nodes > 0 ) {
            return cursor != NULL;
        }
        return false;
    }

    void sequence::advance() {
        // Run Time Analysis: Linked List - O(1)
        // Rune Time Analysis: Dynamic array - (1)
        assert(is_item());
        precursor = cursor;
        cursor = cursor->link();
    }
    
    sequence::value_type sequence::current() const {
        // Run Time Analysis: Linked List - O(1)
        // Rune Time Analysis: Dynamic array - (1)
        return cursor->data();
    }
    void sequence::insert(const value_type& entry) {
        // Run Time Analysis: Linked List - O(1)
        // Rune Time Analysis: Dynamic array - (n)
        // the first case is when the link list is empty.
        if (!(is_item())) {
            if (many_nodes == 0 ) {
                list_head_insert(head_ptr, entry);
                tail_ptr = head_ptr;
            }
            // inserting in the front of the sequence when there is no current item for whatever reason.
            // maybe the current item falls off the sequence.
            else {
                node *insert_ptr;
                insert_ptr = new node(entry, head_ptr);
                head_ptr = insert_ptr;
                // We do not need to do tail_ptr = head_ptr because the tail_ptr is somewhere in the list ...
            }
            start();
        }
        else {
            // you're putting it in the front so head_ptr needs to change ....
            if ( cursor == head_ptr) {
                node* insert_ptr;
                insert_ptr = new node(entry, head_ptr);
                head_ptr = insert_ptr;
                start();
            }
            else {
                // the cursor is in the middle of the link list
                list_insert(precursor,entry);
                cursor = precursor->link(); // this makes cursor point to the newly inserted list.
                // your cursor changes to the newly inserted entry so it's right behind the cursor
                // nothing change about the precursor location
            }
        }
        many_nodes++;
    }
    
    void sequence::attach(const value_type& entry) {
        // Run Time Analysis: Linked List - O(1)
        // Rune Time Analysis: Dynamic array - (n)
        if(!(is_item())) {
            // if the link list is empty lol
            if (many_nodes == 0) {
                list_head_insert(head_ptr, entry);
                tail_ptr = head_ptr;
                start();
            }
            // if the isn't a current item, attach it to the end
            // attaching at the end of the sequence.
            else {
                list_insert(tail_ptr, entry);
                precursor = tail_ptr;
                tail_ptr = tail_ptr->link();
                cursor =  tail_ptr;
            }
        }
        // the current item is in the middle of the link list
        // or cursor and tail_ptr is in the same location.
        else {
            list_insert(cursor, entry);
            if (cursor == tail_ptr) tail_ptr = tail_ptr->link();
            advance();
        }
        many_nodes++;
    }
    
    void sequence::remove_current() {
        // Run Time Analysis: Linked List - O(1 )
        // Rune Time Analysis: Dynamic array - (n)
        assert(is_item());
        // there is a current item
        if (precursor != NULL) {
            list_remove(precursor);
            cursor = precursor->link();
        }
        else { // otherwise cursor points to head_ptr and
                // precursor points to null
            list_head_remove(head_ptr);
            cursor = head_ptr;
            precursor = NULL;
        }
        many_nodes--;
    }
    
}
