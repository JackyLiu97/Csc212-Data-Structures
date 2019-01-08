
#include <iostream>
#include <cassert>
using std::cout;
using std::cin;
    /*
    int current_index = 1;
    int used = 5;
    int array[5];
    array[0] = 10;
    array[1] = 3;
    array[2] = 6;
    array[3] = 9;
    array[4] = 2;
    for ( int i = used; used > current_index; --used) {
        array[used] = array[used-1];
        
    }
    cout << array[0] << "\n";
    cout << array[1] << "\n";
    cout << array[2] << "\n";
    cout << array[3] << "\n";
    cout << array[4] << "\n";
     */
    /*
    int current_index = 0;
    cout << array[current_index] << "\n";
    cout << array[current_index++] << "\n";
    cout << current_index << "\n";
     */

int main () {
    
    int x[5] = { 5, 4, 3, 2, 1 };
    
    int array_size = sizeof (x) / sizeof (x[0]);
    
    for (int j = array_size - 1; j > 0; j--) {
        
        x[j] = x[j - 1];
    }
    
    x[0] = 6;
    
    for (int j = 0; j < array_size; j++) {
        
        std::cout << x[j] << std::endl;
    }
    
    return 0;
}

