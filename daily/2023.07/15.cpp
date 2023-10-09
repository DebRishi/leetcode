#include <iostream>
using namespace std;

// LEETCODE 1751 - Maximum Number of Events That Can Be Attended II

// MEMOIZATION
class Solution {
public:
    vector<vector<int>> memo;
    
    int solve(vector<vector<int>>& events, int k, int idx = 0, int end = 0) {
        if(k == 0 || idx == events.size())
            return 0;
        if(events[idx][0] <= end)
            return solve(events, k, idx+1, end);
        if(memo[idx][k] != -1)
            return memo[idx][k];
        else
            return memo[idx][k] = max(solve(events, k, idx+1, end), solve(events, k-1, idx+1, events[idx][1]) + events[idx][2]);
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        memo = vector<vector<int>>(events.size(), vector<int>(k+1, -1));
        sort(begin(events), end(events));
        return solve(events, k);
    }
};

// RECURSION
class Solution {
public:
    int solve(vector<vector<int>>& events, int k, int idx = 0, int end = 0) {
        if(k == 0 || idx == events.size())
            return 0;
        if(events[idx][0] <= end)
            return solve(events, k, idx+1, end);
        return max(solve(events, k, idx+1, end), solve(events, k-1, idx+1, events[idx][1]) + events[idx][2]);
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        sort(begin(events), end(events));
        return solve(events, k);
    }
};