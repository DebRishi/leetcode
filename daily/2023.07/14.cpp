#include <iostream>
#include <unordered_map>
using namespace std;

// LEETCODE 1218 - Longest Arithmetic Subsequence of Given Difference

class Solution {
public:
    int longestSubsequence(vector<int>& nums, int diff) {
        int ans = 0;
        unordered_map<int, int> map;
        for(int num : nums) {
            int prev = num - diff;
            map[num] = map[prev] + 1;
            ans = max(ans, map[num]);
        }
        return ans;
    }
};