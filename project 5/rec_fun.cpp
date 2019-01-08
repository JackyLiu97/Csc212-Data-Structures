
// Jacky Liu yliu009@citymail.cuny.edu

#include <iostream>
#include <cassert>
using std::cin;
using std::cout;
using std::endl;
using std::string;

double pow(double x, int n) {
    // Precondition: If x is zero, then n must be positive.
    // Postcondition: The value returned is x raised to the power n.
    
    //Hint: use the formula x^2n = x^n*x^n
    if ( x == 0) {
        assert(x > 0);
        return 0;
    }
    
    if ( n == 0) {
        return 1;
    }
    else if ( n > 0) {
        double temp = pow(x,n/2);
        if (n%2 == 0) {
            return temp*temp;
        }
        else {
            return x*temp*temp;
        }
    }
    else {
        return 1/pow(x,-n);
    }
}


void binary(std::ostream& outs, unsigned int n) {
    /*
     The function prints the value of n as a BINARY number to the ostream outs. If n is zero, then a single zero is printed; otherwise no leading zeros are printed in the output. The '\n' character is NOT printed at the end of the output.
     EXAMPLES:
     n=0  Output:0
     n=4  Output:100
     n=27 Output:11011
     NOTE: Your recursive implementation must not use any local variables.
     */
    if ( n > 0) {
        binary(std::cout, n/2);
        outs << n%2;
    //outs << "hello world" << endl;
    }
}

void triangle(std::ostream& outs, unsigned int m , unsigned int n){
    // Precondition: m <= n
    // Postcondition: The function has printed a pattern of 2*(n-m+1) lines
    // to the output stream outs. The first line contains m asterisks, the next
    // line contains m+1 asterisks, and so on up to a line with n asterisks.
    // Then the pattern is repeated backwards, going n back down to m.
    /* Example output:
     triangle(cout, 3, 5) will print this to cout:
     ***
     ****
     *****
     *****
     ****
     ***
     */
//Hint: Only one of the arguments changes in the recursive call. Which one?

    if ( m > n)
        return;
    else {
        for ( int i = 1; i <= m ;i++) {
            outs << "*";
        }
        cout << endl;
        triangle(std::cout, m+1, n);
        for (int i = 1 ; i <= m; i++) {
            outs << "*";
        }
        outs << endl;
    }
}

void indented_sentences(size_t m, size_t n) {
    /*
     This was written by calling number 1.
        This was written by calling number 2.
            This was written by calling number 3.
                This was written by calling number 4.
                This was ALSO written by calling number 4.
            This was ALSO written by calling number 3.
        This was ALSO written by calling number 2.
     This was ALSO written by calling number 1.
     
     In the above example, the recursion stopped when it reached four levels deep, but your function should be capable of continuing any specific level with the following function prototype.
     
     void indented_sentences(size_t m, size_t n);
     // precondition: m <=n;
     //postcondition: print out the above pattern by calling number from m to n
     */
    if ( m > n)
        return;
    else {
        string indents = "";
        for (int i = 0; i <= m; i++) {
            indents += " ";
        }
        cout << indents << "This was written by calling number " << m << ".\n";
        indented_sentences(m+1,n);
        cout << indents << "This was ALSO written by calling number " << m << ".\n";
    }
}




int main() {
    // TEST FUNCTIONS FOR PROJECT 5
    cout << pow(2,3) << endl;
    triangle(std::cout,3,5);
    indented_sentences(3,5);
    binary(std::cout,27);
    cout << "\n";
    return 0;
}


