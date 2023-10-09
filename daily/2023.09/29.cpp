#include<iostream>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = true;
        bool dec = true;
        for (int i = 1 ; i < nums.size() ; i++) {
            inc = inc && (nums[i-1] <= nums[i]);
            dec = dec && (nums[i-1] >= nums[i]);
        }
        return inc || dec;
    }
};