#include<iostream>
using namespace std;

// LEETCODE 343 - Integer Break

class Solution {
public:
    int integerBreak(int num) {
        vector<int> dp(num+1);
        dp[1] = 1;
        for (int i = 2 ; i <= num ; i++) {
            for (int j = 1 ; j < i ; j++) {
                dp[i] = max(dp[i], max(j, dp[j]) * max(i-j, dp[i-j]));
            }
        }
        return dp[num];
    }
};

class Solution {
public: 
    vector<int> memo;
    
    int solve(int num) {
        if (num <= 1)
            return 1;
        if (memo[num] != -1)
            return memo[num];
        int ans = 0;
        for (int i = 1 ; i < num ; i++) {
            ans = max(ans, max(i, solve(i)) * max(num-i, solve(num-i)));
        }
        return memo[num] = ans;
    }
    
    int integerBreak(int num) {
        memo = vector<int>(num+1, -1);
        return solve(num);
    }
};