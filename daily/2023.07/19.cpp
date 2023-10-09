#include <iostream>
using namespace std;

// LEETCODE 435 - Non-overlapping Intervals

class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        int ans = 0;
        int end = INT_MIN;
        for(auto& interval : intervals) {
            if(end <= interval[0])
                end = interval[1];
            else
                ans++;
        }
        return ans;
    }
};