#include<iostream>
using namespace std;

// LEETCODE 137 - Single Number II

// Counting Set Bits 2 - INTUITIVE
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0 ; i < 32 ; i++) {
            int cnt = 0;
            for(int num : nums) {
                cnt += (num & (1 << i)) ? 1 : 0;
            }
            if(cnt % 3 == 1)
                ans += (1 << i);
        }
        return ans;
    }
};

// Counting Set Bits 1 - INTUITIVE
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32);
        for(int num : nums) {
            for(int i = 0 ; i < 32 ; i++) {
                if(num & (1 << i))
                    bits[i]++;
            }
        }
        int ans = 0;
        for(int i = 0 ; i < 32 ; i++)
            if(bits[i] % 3)
                ans += (1 << i);
        return ans;
    }
};

// Bit Manipulation
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;
        for(int num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        return ones;
    }
};

// Sorting 2
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(nums.size() == 1 || nums[0] != nums[1])
            return nums[0];
        if(nums[n-2] != nums[n-1])
            return nums[n-1];
        for(int i = 1 ; i < n ; i += 3) {
            if(nums[i] != nums[i-1])
                return nums[i-1];
        }
        return -1;
    }
};

// Sorting 1
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int idx = 0;
        int pos = 0;
        while(idx < nums.size()) {
            cnt = 0;
            pos = idx;
            while(idx < nums.size() && nums[idx] == nums[pos])
                idx++, cnt++;
            if(cnt == 1)
                return nums[pos];
        }
        return -1;
    }
};

// Hashmap
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int num : nums)
            map[num]++;
        for(auto m : map)
            if(m.second == 1)
                return m.first;
        return -1;
    }
};