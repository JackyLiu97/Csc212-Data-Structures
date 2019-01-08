
/*
void sequence::insert(const value_type& entry) {
    //   void insert(const value_type& entry)
    //     Postcondition: A new copy of entry has been inserted in the sequence before
    //     the current item. If there was no current item, then the new entry has
    //     been inserted at the front of the sequence. In either case, the newly
    //     inserted item is now the current item of the sequence.
    // work out the edge cases ... so first one
    
    // the first case is when the link list is empty.
    if (!(is_item())) {
        if (many_nodes == 0 ) {
            list_head_insert(head_ptr, entry);
            tail_ptr = head_ptr;
            cursor = head_ptr;
            precursor = NULL;
            many_nodes += 1;
        }
        // inserting in the front of the sequence when there is no current item for whatever reason.
        // maybe the current item falls off the sequence.
        else {
            node *insert_ptr;
            insert_ptr = new node(entry, head_ptr);
            head_ptr = insert_ptr;
            cursor = head_ptr;
            precursor = NULL;
        }
    }
    else {
        // if cursor is pointing to the head_ptr then we just use
        // list_head_insert
        // if (cursor == head_ptr does this mean that head_ptr doesn't point to anything ? head_ptr points to NULL ?
        if ( cursor == head_ptr) {
            node* insert_ptr;
            insert_ptr = new node(entry, head_ptr);
            head_ptr = insert_ptr;
            precursor = NULL;
            cursor = head_ptr;
        }
        else {
            list_insert(precursor,entry);
            cursor = precursor->link();
        }
    }
}
*/



void sequence::operator =(const sequence& source)
{
    if (this == &source)
        return;
    
    list_clear(head_ptr);
    many_nodes = 0;
    many_nodes = source.many_nodes;
    list_copy(source.head_ptr, head_ptr, tail_ptr);
    
    node* index_src;
    index_src = source.head_ptr;
    precursor = head_ptr;
    
    if (source.cursor == NULL)
    {
        if (source.precursor == NULL)
        {
            cursor = NULL;
            precursor = NULL;
        }
        else
        {
            precursor = tail_ptr;
            cursor = NULL;
        }
    }
    else
    {
        if (source.precursor == NULL)
        {
            cursor = head_ptr;
            precursor = NULL;
        }
        else
        {
            while (index_src != source.precursor)
            {
                index_src = index_src->link();
                precursor = precursor->link();
            }
            cursor = precursor->link();
        }
    }
}


sequence::sequence(const sequence& source)
{
    many_nodes = source.many_nodes;
    list_copy(source.head_ptr, head_ptr, tail_ptr);
    
    node* index_src;
    index_src = source.head_ptr;
    precursor = head_ptr;
    
    if (source.cursor == NULL)
    {
        if (source.precursor == NULL)
        {
            cursor = NULL;
            precursor = NULL;
        }
        else
        {
            precursor = tail_ptr;
            cursor = NULL;
        }
    }
    else
    {
        if (source.precursor == NULL)
        {
            cursor = head_ptr;
            precursor = NULL;
        }
        else
        {
            while (index_src != source.precursor)
            {
                index_src = index_src->link();
                precursor = precursor->link();
            }
            cursor = precursor->link();
        }
    }
}



