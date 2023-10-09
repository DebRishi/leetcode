#include <iostream>
using namespace std;

// LEETCODE - 852. Peak Index in a Mountain Array

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int size = nums.size();
        if(size == 1)
            return 0;
        if(nums[0] > nums[1]) 
            return 0;
        if(nums[size-1] > nums[size-2])
            return size-1;
        int low = 1;
        int hii = size-2;
        while(low <= hii) {
            int mid = (low + hii) >> 1;
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
                return mid;
            else if(nums[mid] > nums[mid-1])
                low = mid + 1;
            else
                hii = mid - 1;
        }
        return -1;
    }
};