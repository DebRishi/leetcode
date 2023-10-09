#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int low = 0;
        int hii = 0;
        while (hii < nums.size()) {
            if (nums[hii] % 2 == 0)
                swap(nums[low++], nums[hii]);
            hii++;
        }
        return nums;
    }
};