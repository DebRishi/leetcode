#include<iostream>
using namespace std;

// LEETCODE 1420 - Build Array Where You Can Find The Maximum Exactly K Comparisons

class Solution {
public:
    
    int memo[51][51][101];
    
    int solve(int size, int high, int cost, int curr = 0) {
        //printf("size: %d, high: %d, cost: %d, curr: %d\n", size, high, cost, curr);
        if (size == 0)
            return cost == 0;
        if (cost < 0)
            return 0;
        if (memo[size][cost][curr] != -1)
            return memo[size][cost][curr];
        int ans = 0;
        for (int i = 1 ; i <= high ; i++) {
            if (i > curr) {
                ans += solve(size-1, high, cost-1, i);
            }
            else {
                ans += solve(size-1, high, cost, curr);
            }
            ans = ans % 1000000007;
        }
        return memo[size][cost][curr] = ans;
    }
    
    int numOfArrays(int size, int high, int cost) {
        memset(memo, -1, sizeof(memo));
        return solve(size, high, cost);
    }
};