
#include <iostream>
#include <cassert>
#include "sequence2.h"
using std::cout;
using std::cin;
using std::endl;
using main_savitch_4::sequence;

int main() {
    sequence s1;
    s1.attach(4);
    s1.attach(2);
    sequence s2;
    s2.attach(8);
    s2.attach(10);
    //s1 += s2;
    //s1 += s1;
    sequence s3;
    /*
    s3 = s1 + s2;
    for( s3.start(); s3.is_item(); s3.advance()) {
        cout << s3.current() << "\n";
    }
     */
    s2 += s2;
    for (s2.start(); s2.is_item(); s2.advance()) {
        cout << s2.current() << "\n";
    }
    
        /*
    int capacity = 5;
    int array[capacity];
    int used = 5;
    array[0] = 10;
    array[1] = 3;
    array[2] = 6;
    array[3] = 9;
    array[4] = 2;
    //cout << array[used] << "\n";
     */
    return 0;
}


