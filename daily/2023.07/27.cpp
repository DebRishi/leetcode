#include <iostream>
#include <numeric>
using namespace std;

// LEETCODE 2141 - Maximum Running Time of N Computers

// Binary Search - Removing the right search space in else
class Solution {
public:
    
    bool isPossible(int n, vector<int>& bats, long mid) {
        long power = 0;
        for(int bat : bats)
            power += min((long)bat, mid);
        return power >= (n * mid);
    }
    
    long maxRunTime(int n, vector<int>& bats) {
        long low = 1;
        long hii = accumulate(bats.begin(), bats.end(), 0L) / n;
        while(low < hii) {
            long mid = (low + hii + 1) >> 1;
            if(isPossible(n, bats, mid))
                low = mid;
            else
                hii = mid - 1; 
        }
        return low;
    }
};