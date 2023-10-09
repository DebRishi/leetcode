#include <iostream>
using namespace std;

// LEETCODE 50 - Pow(x, n)

class Solution {
public:
    double myPow(double x, long n) {
        if(n == 0)
            return 1;
        if(n < 0) {
            x = 1 / x;
            n = -n;
        }
        if(n % 2 == 0)
            return myPow(x*x, n/2);
        else 
            return x * myPow(x, n-1);
    }
};