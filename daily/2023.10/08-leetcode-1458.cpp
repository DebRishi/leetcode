#include<iostream>
#include<map>
using namespace std;

// LEETCODE 1458 - Max Dot Product of Two Subsequences

class Solution {
public:
    map<pair<int, int>, int> memo;
    
    int solve(vector<int>& nums1, vector<int>& nums2, int i = 0, int j = 0) {
        if (i == nums1.size() || j == nums2.size())
            return 0;
        if (memo.count({i, j}) != 0)
            return memo[{i, j}];
        int ans = INT_MIN;
        if (i < nums1.size() && j < nums2.size())
            ans = max({ans, nums1[i] * nums2[j], (nums1[i] * nums2[j]) + solve(nums1, nums2, i+1, j+1)});
        if (i < nums1.size()-1)
            ans = max(ans, solve(nums1, nums2, i+1, j));
        if (j < nums2.size()-1)
            ans = max(ans, solve(nums1, nums2, i, j+1));
        return memo[{i, j}] = ans;
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        return solve(nums1, nums2);
    }
};