#include <iostream>
using namespace std;

// LEETCODE 673 - Number of Longest Increasing Subsequence

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> len(n, 1);
        vector<int> cnt(n, 1);
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < i ; j++) {
                if(nums[j] < nums[i]) {
                    if(len[j] + 1 > len[i]) {
                        len[i] = len[j] + 1;
                        cnt[i] = cnt[j];
                    }
                    else if(len[j] + 1 == len[i])
                        cnt[i] += cnt[j];
                }
            }
        }
        int maxLen = 0;
        int result = 0;
        for(int i = 0 ; i < n ; i++) {
            if(len[i] > maxLen) {
                maxLen = len[i];
                result = cnt[i];
            }
            else if(len[i] == maxLen)
                result += cnt[i];
        }
        return result;
    }
};