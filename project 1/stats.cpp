

#include <iostream>
#include "stats.h"
#include <vector>
using std::vector;

namespace main_savitch_2C {
    statistician::statistician() {
        total = 0;
        count = 0;
    }
    
    void statistician::next(double r) {
        total += r;
        count += 1;
        if (count > 1 ) {
        if ( r < tinyest ) tinyest = r;
        if ( r > largest ) largest = r;
        }
        else if (count == 1) largest = tinyest = r;
        /*
        vector<double> numbers;
        numbers.push_back(r);
        tinyest = numbers[0];
        largest = numbers[0];
        for (int i = 0; i < numbers.size()-1; i++) {
            if (tinyest > numbers[i]) tinyest = numbers[i];
            if ( largest < numbers[i]) largest = numbers[i];
        }
        */
    }
    
    void statistician::reset() {
        total = 0;
        count = 0;
    }
    
    int statistician::length() const {return count;}
    double statistician::sum() const {return total;}
    double statistician::mean() const {
        if ( count > 0) return total/count;
        else return 0;
    }
    double statistician::minimum() const {return tinyest;}
    double statistician::maximum() const {return largest;}
    
    bool operator == (const statistician& s1, const statistician& s2) {
        if (s1.length() == 0 && s2.length() == 0) return true;
        return (s1.length() == s2.length()
                && s1.sum() == s2.sum()
                && s1.mean() == s2.mean()
                && s1.minimum() == s2.minimum()
                && s1.maximum() == s2.maximum());
    }
    statistician operator +(const statistician& s1, const statistician& s2) {
        statistician temp;
        if (s1.length() == 0) return s2;
        if (s2.length() == 0) return s1;
        temp.count = s1.length() + s2.length();
        if (s1.length() && s2.length() > 0) {
            temp.total = s1.total + s2.total;
            if (s1.minimum() < s2.minimum())
                temp.tinyest = s1.minimum();
            else
                temp.tinyest = s2.minimum();
            if (s1.maximum() > s2.maximum())
                temp.largest = s1.maximum();
            else
                temp.largest = s2.maximum();
        }
        return temp;
    }
 
    statistician operator *(double scale, const statistician& s) {
        statistician temp;
        if (s.length() == 0) return s;
        //if (scale == 0) return 0;
        temp.count = s.length();
        temp.total = scale * s.sum();
        if (scale >= 0) {
            temp.tinyest = scale* s.minimum();
            temp.largest = scale* s.maximum();
        }
        else {
            temp.tinyest = scale * s.maximum();
            temp.largest = scale * s.minimum();
        }
        return temp;
        // NON-MEMBER functions for the statistician class:
        //   statistician operator +(const statistician& s1, const statistician& s2)
        //     Postcondition: The statistician that is returned contains all the
        //     numbers of the sequences of s1 and s2.
        //   statistician operator *(double scale, const statistician& s)
        //     Postcondition: The statistician that is returned contains the same
        //     numbers that s does, but each number has been multiplied by the
        //     scale number.
    }
}

