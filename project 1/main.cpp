#include "stats.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using std::vector;
using std::cout;
using std::cin;

using main_savitch_2C::statistician;
int main() {
    statistician s1;
    statistician s2;
    statistician s4;
    s1.next(3.2);
    s1.next(3.2);
    s2.next(3.2);
    s2.next(3.2);
    s4.next(3.2);
    s4.next(3.2);
    s4.next(3.2);
    s4.next(3.2);
    
    if (s1 == s2) {
        cout << "s1==s2 should work -.-." << "\n";
    }
    else {
        cout << "diaster" << "\n";
    }
    statistician s3;
    s3 = s1 + s2;
    assert(s3 == s4);
    //s.next(4.0);
    //s.next(5);
    //cout << "nothing wrong so far right?" << "\n";
    //cout << s.minimum() << "\n";
    //cout << s.maximum() << "\n";
    //cout << s.length() << "\n";
    //cout << s.sum() << "\n";
    //cout << s.mean() << "\n";
    /*
    vector<double> v{4.0, 80, 2.0, 60};
    v.push_back(4.0);
    v.push_back(80);
    v.push_back(2.0);
    v.push_back(60);
    double min = v[0];
    double max = v[0];
    for(int i = 0; i < v.size()-1; i ++){
        if (min > v[i]) min = v[i];
        if (max < v[i]) max = v[i];
    }
    cout << min << "\n";
    cout << max << "\n";
     */
    return 0;
}
