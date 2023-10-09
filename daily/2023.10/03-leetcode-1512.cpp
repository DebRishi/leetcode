#include<iostream>
#include<map>
using namespace std;

// LEETCODE - 1512 - Number of Good Pairs

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int, int> map;
        for (int num : nums) {
            map[num]++;
        }
        int ans = 0;
        for (auto& [ _, n ] : map) {
            ans += (n*(n-1))/2;
        }
        return ans;
    }
};