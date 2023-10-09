#include<iostream>
using namespace std;

// LEETCODE 34 - Find First and Last Position of Element in Sorted Array

class Solution {
public:
    
    int lowerBound(vector<int>& nums, int key) {
        int low = 0;
        int hii = nums.size();
        while (low < hii) {
            int mid = (low + hii) >> 1;
            if (nums[mid] < key)
                low = mid + 1;
            else
                hii = mid;
        }
        return hii;
    }
    
    vector<int> searchRange(vector<int>& nums, int key) {
        int low = lowerBound(nums, key);
        int hii = lowerBound(nums, key+1);
        if (low == hii)
            return {-1, -1};
        else
            return {low, hii-1};
    }
};